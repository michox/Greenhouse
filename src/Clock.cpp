#include "Clock.h"
#include "Sleep.h"
#include "Watering.h"

PCF8563_Class rtc;
ESP32Time systemTime;

RTC_DATA_ATTR int lastResetDay = -1;
RTC_DATA_ATTR int lastResetMonth = -1;
RTC_DATA_ATTR int lastResetYear = -1;


void clockTask(void *)
{
    working++;
    vTaskDelay(2000 / portTICK_PERIOD_MS); // wait till wire is ready
    xSemaphoreTake(mutex, portMAX_DELAY);
    rtc.begin();
    auto dateTime = rtc.getDateTime();
    systemTime.setTime(dateTime.second, dateTime.minute, dateTime.hour, 9, 5, 2025);
    Serial.println(rtc.formatDateTime());


    // Only reset if after 5:00 am and not already reset today
    if ((dateTime.hour >= RESET_HOUR) &&
        (lastResetDay != dateTime.day || lastResetMonth != dateTime.month || lastResetYear != dateTime.year)) {
        Serial.println("New day detected after 5:00 am, resetting water volumes");
        xSemaphoreTake(wateringMutex, portMAX_DELAY);
        spentWaterVolume1 = 0;
        spentWaterVolume2 = 0;
        spentWaterVolume3 = 0;
        spentWaterVolume4 = 0;
        xSemaphoreGive(wateringMutex);
        lastResetDay = dateTime.day;
        lastResetMonth = dateTime.month;
        lastResetYear = dateTime.year;
    }
    xSemaphoreGive(mutex);

    working--;
    vTaskDelay(portMAX_DELAY);
    while (true)
    {
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        working++;
        xSemaphoreTake(mutex, portMAX_DELAY);
        auto now = rtc.getDateTime();
        if ((now.hour >= RESET_HOUR) &&
            (lastResetDay != now.day || lastResetMonth != now.month || lastResetYear != now.year)) {
            Serial.println("New day detected after 5:00 am, resetting water volumes");
            xSemaphoreTake(wateringMutex, portMAX_DELAY);
            spentWaterVolume1 = 0;
            spentWaterVolume2 = 0;
            spentWaterVolume3 = 0;
            spentWaterVolume4 = 0;
            xSemaphoreGive(wateringMutex);
            lastResetDay = now.day;
            lastResetMonth = now.month;
            lastResetYear = now.year;
        }
        xSemaphoreGive(mutex);
        working--;
    }
}