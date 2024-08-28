#include "Clock.h"
#include "Sleep.h"
#include "Watering.h"

PCF8563_Class rtc;
ESP32Time systemTime;

// returns true if alarm is no longer active
bool resetAlarm()
{
    rtc.resetAlarm();
    rtc.setAlarmByHours(RESET_HOUR);
    Serial.println("Alarm is now " + String(rtc.alarmActive()));
    rtc.enableAlarm();
    Serial.println("Alarm is now " + String(rtc.alarmActive()));
    return !rtc.alarmActive();
}

void clockTask(void *)
{
    // while(true){vTaskDelay(portMAX_DELAY);}
    working++;
    vTaskDelay(2000 / portTICK_PERIOD_MS); // wait till wire is ready
    xSemaphoreTake(mutex, portMAX_DELAY);
    rtc.begin();
    auto dateTime = rtc.getDateTime();
    systemTime.setTime(dateTime.second, dateTime.minute, dateTime.hour, 30, 5, 2023);
    Serial.println(rtc.formatDateTime());
    // rtc.setAlarm(systemTime.getHour(), systemTime.getMinute() + 1, PCF8563_NO_ALARM, PCF8563_NO_ALARM);
    rtc.setAlarmByHours(RESET_HOUR);

    if (rtc.alarmActive())
    {
        uint retry = 0;
        Serial.println("triggered Alarm");
        while (resetAlarm() && retry++ < 10)
        {
            Serial.println("resetting Alarm");
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
        xSemaphoreTake(wateringMutex, portMAX_DELAY);
        spentWaterVolume1 = 0;
        spentWaterVolume2 = 0;
        spentWaterVolume3 = 0;
        spentWaterVolume4 = 0;
        xSemaphoreGive(wateringMutex);
    }
    xSemaphoreGive(mutex);

    working--;
    vTaskDelay(portMAX_DELAY);
    while (true)
    {
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        working++;
        xSemaphoreTake(mutex, portMAX_DELAY);
        if (rtc.alarmActive())
        {
            uint retry = 0;
            Serial.println("triggered Alarm");
            while (resetAlarm() && retry++ < 10)
            {
                Serial.println("resetting Alarm");
                vTaskDelay(100 / portTICK_PERIOD_MS);
            }
            xSemaphoreTake(wateringMutex, portMAX_DELAY);
            Serial.println("triggered Alarm");
            spentWaterVolume1 = 0;
            spentWaterVolume2 = 0;
            spentWaterVolume3 = 0;
            spentWaterVolume4 = 0;
            xSemaphoreGive(wateringMutex);
        }
        xSemaphoreGive(mutex);
        working--;
    }
}