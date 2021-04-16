#include "Clock.h"
#include "Sleep.h"
#include "Watering.h"

 Rtc_Pcf8563 rtc;
 ESP32Time systemTime;

void clockTask(void *)
{
    working++;
    vTaskDelay(1000); //wait until I2C was initialized by the display.

    rtc.getDateTime();
    systemTime.setTime(rtc.getSecond(), rtc.getMinute(), rtc.getHour(), 1, 1, 2021);

    if (!rtc.alarmEnabled())
    {
        rtc.setAlarm(0, RESET_HOUR, 99, 99);
        rtc.enableAlarm();
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
            rtc.enableAlarm();
        }
        
    working--;
    while (true)
    {
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        rtc.getTime();
        systemTime.setTime(rtc.getSecond(), rtc.getMinute(), rtc.getHour(), 1, 1, 2021);
        
        if (rtc.alarmActive())
        {
            Serial.println("triggered Alarm");
            spentWaterVolume1 = 0;
            spentWaterVolume2 = 0;
            spentWaterVolume3 = 0;
            spentWaterVolume4 = 0;
            rtc.clearAlarm();
            rtc.setAlarm(1, 12, 99, 99);
            rtc.enableAlarm();
        }
    }
}