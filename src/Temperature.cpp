#include "Arduino.h"
#include "Sleep.h"
#include "DHT.h"

#define DHTTYPE DHT22 // DHT 22  (AM2302)

RTC_DATA_ATTR float maxTemperature = 0;
RTC_DATA_ATTR float minTemperature = 100;
float humidity = NAN;
float temperature = NAN;
float topTemperature = NAN;
float bottomTemperature = NAN;

void temperatureMeasuringTask(void *)
{

    DHT dhtBottom(DHT_BOTTOM, DHTTYPE);
    DHT dhtTop(DHT_TOP, DHTTYPE);
    dhtBottom.begin();
    dhtTop.begin();
    Serial.println("started temperature measuring task");

    while (true)
    {
        working++; //don't want the device go to sleep mid through a reading
        Serial.printf("working++ temperature. working : %d\n", working);

        humidity = dhtTop.readHumidity();
        Serial.printf("top t:%.2f ", humidity);
        if (!isnan(humidity))
        {
            humidity += dhtBottom.readHumidity();
            humidity /= 2;
            Serial.printf("bot t:%.2f ", humidity);
        }
        topTemperature = dhtTop.readTemperature();

        bottomTemperature = dhtBottom.readTemperature();
        if (!isnan(topTemperature) && !isnan(bottomTemperature))
        {
            temperature = (topTemperature + bottomTemperature) / 2;
            if (temperature > maxTemperature)
                maxTemperature = temperature;
            else if (temperature < minTemperature)
                minTemperature = temperature;
        }
        else
            temperature = NAN;
        working--;
        Serial.printf("working-- temperature. working : %d\n", working);

        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}