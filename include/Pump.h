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
        stop();
    }
    void run()
    {
        if (!isRunning())
        {
            ticksSincePumpStart = 0;
        }
        gpio_hold_dis(PUMP); //to enable hold during deep sleep and keep the pins pulled low.
        digitalWrite(PUMP, RELAY_ON);
        gpio_hold_en(PUMP);
    }
    void stop()
    {
        ticksSincePumpStart = -1;
        gpio_hold_dis(PUMP);
        digitalWrite(PUMP, RELAY_OFF);
        gpio_hold_en(PUMP);
    }
    bool isRunning()
    {
        return digitalRead(PUMP) == RELAY_ON;
    }

    bool notBlocked()
    {
        if (pumpIsBlocked) return false;
        if (ticksSincePumpStart < 100)
        {
            pumpIsBlocked = false;
        }
        else if (averageFlow > 0.1)
        {
            Serial.println("Pump is running, flow: " + String(averageFlow) + " l/h");
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