#pragma once
#include <Arduino.h>
#include "Temperature.h"
#include "Sleep.h"
#include "Preferences.h"
#include "HTU21D.h"

extern Preferences preferences;

#define DEFAULT_MIN_TEMP 5
#define DEFAULT_MAX_TEMP 27

class AirConditioner
{
private:
    int targetMaximumTemperature;
    int targetMinimumTemperature;

    bool tooCold()
    {
        if (isnan(temperature) || temperature == HTU21D_ERROR)
        {
            return false;
        }
        return (temperature < targetMinimumTemperature);
    }

    bool tooHot()
    {
        if (isnan(temperature) || temperature == HTU21D_ERROR)
        {
            return false;
        }
        return (temperature > targetMaximumTemperature);
    }

    bool warmEnough()
    {
        if (isnan(temperature) || temperature == HTU21D_ERROR)
        {
            return true;
        }
        return (temperature > targetMinimumTemperature + 2);
    }

    bool coolEnough()
    {
        if (isnan(temperature) || temperature == HTU21D_ERROR)
        {
            return true;
        }
        return (temperature < targetMaximumTemperature - 2);
    }

public:
    AirConditioner()
    {
    }

    void begin()
    {
        pinMode(HEATER, OUTPUT);
        pinMode(FAN, OUTPUT);
        digitalWrite(HEATER, RELAY_OFF);
        digitalWrite(FAN, RELAY_OFF);
        this->targetMaximumTemperature = preferences.getInt("maxTemp", DEFAULT_MAX_TEMP);
        this->targetMinimumTemperature = preferences.getInt("minTemp", DEFAULT_MIN_TEMP);
    }

    void setMaximumTemperature(int temp)
    {
        targetMaximumTemperature = temp;
        preferences.putInt("maxTemp", temp);
    }

    void setMinimumTemperature(int temp)
    {
        targetMinimumTemperature = temp;
        preferences.putInt("minTemp", temp);
    }

    int getMaximumTemperature() { return targetMaximumTemperature; }
    int getMinimumTemperature() { return targetMinimumTemperature; }

    void regulate()
    {
        if (tooCold())
        {
            working++;
            Serial.printf("working++ heater. working : %d\n", working);

            while (!warmEnough())
            {
                Serial.println("heating");
                digitalWrite(HEATER, RELAY_ON);
                vTaskDelay(3000 / portTICK_PERIOD_MS);
            }
            digitalWrite(HEATER, RELAY_OFF);
            working--;
            Serial.printf("working-- heater. working : %d\n", working);
        }
        else if (tooHot())
        {
            working++;
            Serial.printf("working++ fan. working : %d\n", working);

            while (!coolEnough())
            {
                Serial.println("Cooling...");
                digitalWrite(FAN, RELAY_ON);
                vTaskDelay(3000 / portTICK_PERIOD_MS);
            }
            digitalWrite(FAN, RELAY_OFF);
            working--;
            Serial.printf("working-- fan. working : %d\n", working);
        }
    }
};

extern AirConditioner ac;

void airConditioningTask(void *);