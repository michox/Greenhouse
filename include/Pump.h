#pragma once
#include "Arduino.h"
#include "esp32-hal-ledc.h"
#include "Pinout.h"


class Pump
{
public:
    Pump()
    {
        pinMode(PUMP, OUTPUT);
    }
    void run() { digitalWrite(PUMP, HIGH); }
    void stop() { digitalWrite(PUMP, LOW); }
} ;
extern Pump pump;