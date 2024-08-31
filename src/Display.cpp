#include "Display.h"
#include "Sleep.h"
#include "Watering.h"
#include "SnailFence.h"
#include "AirConditioner.h"
#include "Clock.h"
#include "SH1106Wire.h"
#include "FreeRTOS.h"

#define TIMEOUT_TICKS 300

SH1106Wire display(0x3C, SDA, SCL);
OLEDDisplayUi ui(&display);

const uint8_t activeSymbol[] PROGMEM = {
    B00000000,
    B00000000,
    B00011000,
    B00100100,
    B01000010,
    B01000010,
    B00100100,
    B00011000};

const uint8_t inactiveSymbol[] PROGMEM = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000};

void msOverlay(OLEDDisplay *display, OLEDDisplayUiState *state)
{
}

void mainFrame(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{
    display->displayOn();
    display->setFont(ArialMT_Plain_16);
    display->drawString(5, 0, "Feucht. " + String(humidity, 0) + " %");
    display->drawString(5, 18, "Temp. " + String(temperature, 1) + " C");
    display->drawString(5, 36, String(minTemperature, 1) + "<" + String(maxTemperature, 1));
}

void screenOff(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{
    display->clear();
    display->displayOff();
}

template <uint areaCount>
void areaInfo(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{
    xSemaphoreTake(wateringMutex, portMAX_DELAY);
    display->setFont(ArialMT_Plain_16);
    display->clear();
    display->drawString(5, 0, "Feld " + String(areaCount + 1) + " " + areas[areaCount].printModeName());
    display->drawString(5, 18, "Gegossen: " + String(areas[areaCount].spentLiters(), 1) + " L");
    //display->drawString(5, 36, "Feucht.: " + String(areas[areaCount].currentHumidity(), 0) + " %");
    display->setTextAlignment(TEXT_ALIGN_RIGHT);
    display->drawString(128, 0, String(areas[areaCount].readDailyTarget(), 0));
    display->setTextAlignment(TEXT_ALIGN_LEFT);
    xSemaphoreGive(wateringMutex);
}

void temperatureConfig(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{
    display->clear();
    display->setFont(ArialMT_Plain_16);
    display->drawString(5, 0, "Komfortzone:");
    display->setFont(ArialMT_Plain_10);
    display->drawString(5, 22, "min alt:" + String(ac.getMinimumTemperature()) + " C, neu: " + String(areas[0].readDailyTarget() / 3, 0) + " C");
    display->drawString(5, 36, "max alt:" + String(ac.getMaximumTemperature()) + " C, neu: " + String(areas[1].readDailyTarget() / 3, 0) + " C");
}

void clockFrame(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{
    display->clear();
    display->setFont(ArialMT_Plain_24);
    display->drawString(17, 12, systemTime.getTime());
    // vTaskDelay(100 / portTICK_PERIOD_MS);
}

void waterLowFrame(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{
    display->clear();
    display->setFont(ArialMT_Plain_16);
    if (pumpIsBlocked)
    {
        display->drawString(17, 12, "Pumpe Fehler");
    }
    else if (!waterAvailable)
        display->drawString(17, 12, "Wasser leer!");
    else if (snail_fence_short_circuit)
        display->drawString(17, 12, "Scheckenzaun inaktiv!");
    // else if (waterLow)
    //     display->drawString(17, 12, "Wasser niedrig");
}

// This array keeps function pointers to all frames

FrameCallback frames[] = {
    screenOff,
    waterLowFrame,
    mainFrame,
    areaInfo<0>,
    areaInfo<1>,
    areaInfo<2>,
    areaInfo<3>,
    temperatureConfig,
    clockFrame,
};

// Overlays are statically drawn on top of a frame. It is not used here but the code had difficulties running without specifying anything
OverlayCallback overlays[] = {msOverlay};
int overlaysCount = 1;

bool displayTimeout()
{
    OLEDDisplayUiState *uiState = ui.getUiState();
    return uiState->currentFrame != 0 && uiState->ticksSinceLastStateSwitch > TIMEOUT_TICKS;
}

void displayTask(void *)
{
    Serial.print("Starting display Task...");
    vTaskDelay(10); // wait 5 ticks for the other processes to complete initializing
    xSemaphoreTake(mutex, portMAX_DELAY);
    ui.setTargetFPS(24);

    // Customize the active and inactive symbol
    ui.setActiveSymbol(activeSymbol);
    ui.setInactiveSymbol(inactiveSymbol);

    // You can change this to
    // TOP, LEFT, BOTTOM, RIGHT
    ui.setIndicatorPosition(BOTTOM);

    // Defines where the first frame is located in the bar.
    ui.setIndicatorDirection(LEFT_RIGHT);
    ui.setTimePerTransition(0);
    ui.disableAutoTransition();

    // Add frames
    ui.setFrames(frames, FRAME_COUNT);
    ui.setOverlays(overlays, overlaysCount);

    // Initialising the UI will init the display too.
    ui.init();
    
    display.flipScreenVertically();

    if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_EXT0)
    {

        if (waterAvailable && !pumpIsBlocked)
            ui.switchToFrame(MAIN_FRAME);
        else
            ui.switchToFrame(ALERT_FRAME);
        working++;
        Serial.printf("working++ Display. working : %d\n", working);
    }
    else
    {
        ui.switchToFrame(SCREEN_OFF);
    }

    ui.update();
    xSemaphoreGive(mutex);
    while (true)
    {
        xSemaphoreTake(mutex, portMAX_DELAY);
        int timeBudget = ui.update();
        xSemaphoreGive(mutex);
        if (timeBudget > 0)
        {
            if (displayTimeout())
            {
                xSemaphoreTake(mutex, portMAX_DELAY);
                ui.switchToFrame(SCREEN_OFF);
                xSemaphoreGive(mutex);
                Serial.printf("working-- Display. working : %d\n", working);
                working--;
            }
            vTaskDelay(timeBudget / portTICK_PERIOD_MS);
        }
    }
}
