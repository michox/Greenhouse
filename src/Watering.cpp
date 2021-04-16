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
    Hygrometer hygro[] = {HYGRO_1, HYGRO_2, HYGRO_3, HYGRO_4};

    areas.emplace_back(AREA_SOLENOID_1, AREA_POTI_1, &hygro[0], spentWaterVolume1);
    areas.emplace_back(AREA_SOLENOID_2, AREA_POTI_2, &hygro[1], spentWaterVolume2);
    areas.emplace_back(AREA_SOLENOID_3, AREA_POTI_3, &hygro[2], spentWaterVolume3);
    areas.emplace_back(AREA_SOLENOID_4, AREA_POTI_4, &hygro[3], spentWaterVolume4);

    Serial.println(" started");

    while (true)
    {
        working++;  Serial.printf("working++ watering. working : %d\n", working);

        for (auto &area : areas)
        {
            while (area.water())
            {
                Serial.println("Watering...");
                vTaskDelay(10000 / portTICK_PERIOD_MS);
            }
        }
        working--;   Serial.printf("working-- watering. working : %d\n", working);

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}