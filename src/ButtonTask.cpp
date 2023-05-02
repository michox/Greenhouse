#include "FreeRTOS.h"
#include "button.h"
#include "Pump.h"
#include "Sleep.h"
#include "Clock.h"
#include "Display.h"
#include "Temperature.h"
#include "Watering.h"
#include "AirConditioner.h"
#include "Pinout.h"
void buttonTask(void *)
{

    button_event_t ev;
    QueueHandle_t button_events = button_init(PIN_BIT(BUTTON));
    SemaphoreHandle_t eventSemaphore = xSemaphoreCreateMutex();

    while (true)
    {
        if (xQueueReceive(button_events, &ev, portMAX_DELAY))
        {
            xSemaphoreTake(mutex, portMAX_DELAY);
            int currentFrame = ui.getUiState()->currentFrame;
            if ((ev.pin == BUTTON) && (ev.event == BUTTON_HELD) && xSemaphoreTake(eventSemaphore, 0))
            {
                if (currentFrame == ALERT_FRAME)
                {
                    pumpIsBlocked = false;
                }
                if (currentFrame == MAIN_FRAME)
                {
                    maxTemperature = 0;
                    minTemperature = 100;
                }
                else if (currentFrame >= AREA_FRAME_0 && currentFrame <= AREA_FRAME_3)
                {

                    areas[currentFrame - AREA_FRAME_0].switchMode();
                }
                else if (currentFrame == TEMPERATURE_FRAME)
                {
                    Serial.println(ac.getMinimumTemperature());
                    ac.setMinimumTemperature(areas[0].readDailyTarget() / 3);
                    ac.setMaximumTemperature(areas[1].readDailyTarget() / 3);
                }
                else if (currentFrame == CLOCK_FRAME)
                {
                    rtc.setDateTime(1, 1, 1, 0, 22, 12, 0, 0);
                    systemTime.setTime(rtc.getSecond(), rtc.getMinute(), rtc.getHour(), 1, 1, 2021);
                }
            }
            else if ((ev.pin == BUTTON) && (ev.event == BUTTON_UP && xSemaphoreGive(eventSemaphore) != pdTRUE))
            {
                if (currentFrame == SCREEN_OFF)
                {
                    working++;
                    Serial.printf("working++ Display. working : %d\n", working);
                    if (waterAvailable && !pumpIsBlocked)
                        ui.switchToFrame(MAIN_FRAME);
                }
                else if (currentFrame == CLOCK_FRAME)
                {
                    working--;
                    Serial.printf("working-- Display. working : %d\n", working);
                }

                ui.nextFrame();
            }
            xSemaphoreGive(mutex);
        }
    }
}