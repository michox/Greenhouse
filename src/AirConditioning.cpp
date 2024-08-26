#include "AirConditioner.h"

AirConditioner ac;
void airConditioningTask(void *)
{
    ac.begin();
    while (true)
    {
        // ac.regulate();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}