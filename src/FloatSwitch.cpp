#include "Arduino.h"
#include "Pinout.h"

bool waterAvailable;

void floatSwitchTask(void*){
    
    while (true){
        xSemaphoreTake(mutex, portMAX_DELAY);
        #ifdef DEBUG
        waterAvailable = true;//digitalRead(WATER_AVAILABLE);
        #else
        waterAvailable = digitalRead(WATER_AVAILABLE);
        #endif
        xSemaphoreGive(mutex);
        vTaskDelay(500);
    }
}