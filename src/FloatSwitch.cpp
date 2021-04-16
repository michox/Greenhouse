#include "Arduino.h"
#include "Pinout.h"

bool waterAvailable;
bool waterLow;

void floatSwitchTask(void*){
    while (true){
        waterAvailable =  digitalRead(WATER_AVAILABLE);
        waterLow = digitalRead(WATER_LOW);
        vTaskDelay(100);
    }
}