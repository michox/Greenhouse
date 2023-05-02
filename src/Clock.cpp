#include "Clock.h"
#include "Sleep.h"
#include "Watering.h"

Rtc_Pcf8563 rtc;
ESP32Time systemTime;

void clockTask(void *)
{
    working++;
    xSemaphoreTake(mutex, portMAX_DELAY);
    rtc.getDateTime();
    systemTime.setTime(rtc.getSecond(), rtc.getMinute(), rtc.getHour(), 1, 1, 2021);


    if (!rtc.alarmEnabled())
    {
        Serial.println("enabling alarm");
        rtc.setAlarm(0, RESET_HOUR, 99, 99);
        // rtc.enableAlarm();
    }

    if (rtc.alarmActive())
    {
        Serial.println("triggered Alarm");
        spentWaterVolume1 = 0;
        spentWaterVolume2 = 0;
        spentWaterVolume3 = 0;
        spentWaterVolume4 = 0;
        rtc.clearAlarm();
        rtc.setAlarm(0, RESET_HOUR, 99, 99);
        // rtc.enableAlarm();

    }
    xSemaphoreGive(mutex);
    working--;
    while (true)
    {
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        working++;
        xSemaphoreTake(mutex, portMAX_DELAY);
        rtc.getDateTime();
        systemTime.setTime(rtc.getSecond(), rtc.getMinute(), rtc.getHour(), rtc.getDay(), rtc.getMonth(), 2022);
        if (rtc.alarmActive())
        {
            Serial.println("triggered Alarm");
            spentWaterVolume1 = 0;
            spentWaterVolume2 = 0;
            spentWaterVolume3 = 0;
            spentWaterVolume4 = 0;
            rtc.clearAlarm();
            rtc.setAlarm(0, RESET_HOUR, 99, 99);
            // rtc.enableAlarm();
        }
        working--;
        xSemaphoreGive(mutex);
    }
}