#include "WateringArea.h"
#include "Sleep.h"

std::vector<WateringArea> areas;

RTC_DATA_ATTR float spentWaterVolume1 = 0;
RTC_DATA_ATTR float spentWaterVolume2 = 0;
RTC_DATA_ATTR float spentWaterVolume3 = 0;
RTC_DATA_ATTR float spentWaterVolume4 = 0;

void wateringTask(void *)
{
    Serial.print("Starting Watering Task...");
    pump.begin();
    Hygrometer hygro[] = {HYGRO_1, HYGRO_2, HYGRO_3, HYGRO_4};

    // spentWaterVolume1 = constrain(spentWaterVolume1, 0, 100);
    // spentWaterVolume2 = constrain(spentWaterVolume2, 0, 100);
    // spentWaterVolume3 = constrain(spentWaterVolume3, 0, 100);
    // spentWaterVolume4 = constrain(spentWaterVolume4, 0, 100);

    areas.emplace_back(AREA_SOLENOID_1, AREA_POTI_1, &hygro[0]);
    areas.emplace_back(AREA_SOLENOID_2, AREA_POTI_2, &hygro[1]);
    areas.emplace_back(AREA_SOLENOID_3, AREA_POTI_3, &hygro[2]);
    areas.emplace_back(AREA_SOLENOID_4, AREA_POTI_4, &hygro[3]);

    Serial.println("Watering Task started");

    while (true)
    {
        working++;
        Serial.printf("working++ watering. working : %d\n", working);

        for (auto &area : areas)
        {
            while (area.water())
            {
                Serial.println("Watering...");
                vTaskDelay(100 / portTICK_PERIOD_MS);
            }
        }
        working--;
        Serial.printf("working-- watering. working : %d\n", working);

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}