#pragma once
#include "Arduino.h"
#include "Pinout.h"
#include "FlowMeter.h"

extern RTC_DATA_ATTR boolean pumpIsBlocked;

class Pump
{
public:
    int32_t ticksSincePumpStart = -1;   
    void begin()
    {
        pinMode(PUMP, OUTPUT);
        digitalWrite(PUMP, RELAY_OFF);
    }
    void run()
    {
        if (!isRunning())
        {
            ticksSincePumpStart = 0;
        }
        digitalWrite(PUMP, RELAY_ON);
    }
    void stop()
    {
        ticksSincePumpStart = -1;
        digitalWrite(PUMP, RELAY_OFF);
    }
    bool isRunning()
    {
        return digitalRead(PUMP) == RELAY_ON;
    }

    bool notBlocked()
    {
        if (pumpIsBlocked) return false;
        if (ticksSincePumpStart < 30)
        {
            pumpIsBlocked = false;
        }
        else if (averageFlow > 0.1)
        {
            pumpIsBlocked = false;
        }
        else
        {
            #ifdef DEBUG
            pumpIsBlocked = false;
            #else
            pumpIsBlocked = true;
            #endif
        }
        return !pumpIsBlocked;
    }
};
extern Pump pump;