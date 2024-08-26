#include "Arduino.h"
#include "Sleep.h"
#include "..\lib\HTU21D\src\HTU21D.h"

RTC_DATA_ATTR float maxTemperature = 0;
RTC_DATA_ATTR float minTemperature = 100;
float humidity = NAN;
float temperature = NAN;
float humidityOld = NAN;
float temperatureOld = NAN;

void temperatureMeasuringTask(void *)
{
    vTaskDelay(100);
    xSemaphoreTake(mutex, portMAX_DELAY);
    HTU21D htu;
    htu.begin();
    xSemaphoreGive(mutex);
    Serial.println("started temperature measuring task");
    while (true)
    {
        working++; // don't want the device go to sleep mid through a reading
        Serial.printf("working++ temperature. working : %d\n", working);
        xSemaphoreTake(mutex, portMAX_DELAY);
        humidity = htu.readCompensatedHumidity();
        temperature = htu.readTemperature();
        Serial.printf("temperature = %.2f, humidity = %.2f", temperature, humidity);
        if (temperature != HTU21D_ERROR && humidity != HTU21D_ERROR)
        {
            humidityOld = humidity;
            temperatureOld = temperature;
            if (temperature > maxTemperature)
                maxTemperature = temperature;
            else if (temperature < minTemperature)
                minTemperature = temperature;
        }
        else
        {
            temperature = temperatureOld;
            humidity = humidityOld;
        }
        xSemaphoreGive(mutex);
        working--;
        Serial.printf("working-- temperature. working : %d\n", working);

        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}