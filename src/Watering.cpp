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

  // if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_UNDEFINED)
  // {
  //   Serial.println("normal boot");
  //   spentWaterVolume1 = 0;
  //   spentWaterVolume2 = 0;
  //   spentWaterVolume3 = 0;
  //   spentWaterVolume4 = 0;
  // }
  // else
  // {
  //   Serial.println("wakeup boot");
  //   spentWaterVolume1 = preferences.getFloat("Water1",0);
  //   spentWaterVolume2 = preferences.getFloat("Water2",0);
  //   spentWaterVolume3 = preferences.getFloat("Water3",0);
  //   spentWaterVolume4 = preferences.getFloat("Water4",0);
  // }

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
      bool needsWater = area.water();
      while (needsWater)
      {
        Serial.println("Watering...");
        vTaskDelay(100 / portTICK_PERIOD_MS);
        needsWater = area.water();
      }
    }
    working--;
    Serial.printf("working-- watering. working : %d\n", working);

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}