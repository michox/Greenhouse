#include "AirConditioner.h"

AirConditioner ac;
void airConditioningTask(void *)
{
    Serial.print("Starting AC Task...");
    Serial.println(" started");

    while (true)
    {
        ac.regulate();
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}