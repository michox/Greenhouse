#include "Arduino.h"
#include "Pinout.h"

bool waterAvailable;
bool waterLow;

void floatSwitchTask(void*){
    while (true){
        xSemaphoreTake(mutex, portMAX_DELAY);
        waterAvailable = digitalRead(WATER_AVAILABLE);
        waterLow = digitalRead(WATER_LOW);
        xSemaphoreGive(mutex);
        vTaskDelay(500);
    }
}