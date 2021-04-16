#include "Arduino.h"
#include "Sleep.h"
#include "C:\Users\michox\Documents\PlatformIO\Projects\Greenhouse\lib\HTU21D\src\HTU21D.h"

RTC_DATA_ATTR float maxTemperature = 0;
RTC_DATA_ATTR float minTemperature = 100;
float humidity = NAN;
float temperature = NAN;


void temperatureMeasuringTask(void *)
{

    vTaskDelay(100);
    HTU21D htu;
    htu.begin();
    Serial.println("started temperature measuring task");
    while (true)
    {
        working++; //don't want the device go to sleep mid through a reading
        Serial.printf("working++ temperature. working : %d\n", working);

        humidity = htu.readCompensatedHumidity();
        temperature = htu.readTemperature();
        Serial.printf("temperature = %.2f, humidity = %.2f", temperature, humidity);
        if (temperature != HTU21D_ERROR && humidity != HTU21D_ERROR)
        {
            if (temperature > maxTemperature)
                maxTemperature = temperature;
            else if (temperature < minTemperature)
                minTemperature = temperature;
        }
        else
            temperature = NAN;
            humidity = NAN;
        working--;
        Serial.printf("working-- temperature. working : %d\n", working);

        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}