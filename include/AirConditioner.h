#pragma once
#include <Arduino.h>
#include "Temperature.h"
#include "Sleep.h"
#include "Preferences.h"

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
        if (isnan(bottomTemperature))
        {
            return false;
        }
        return (bottomTemperature < targetMinimumTemperature);
    }

    bool tooHot()
    {
        if (isnan(topTemperature))
        {
            return false;
        }
        return (topTemperature > targetMaximumTemperature);
    }

    bool warmEnough()
    {
        if (isnan(bottomTemperature))
        {
            return true;
        }
        return (bottomTemperature > targetMinimumTemperature + 2);
    }

    bool coolEnough()
    {
        if (isnan(topTemperature))
        {
            return true;
        }
        return (topTemperature < targetMaximumTemperature - 5);
    }

public:
    AirConditioner()
    {
        pinMode(HEATER, OUTPUT);
        pinMode(FAN, OUTPUT);

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
                digitalWrite(HEATER, HIGH);
                digitalWrite(FAN, HIGH);
                vTaskDelay(30000 / portTICK_PERIOD_MS);
            }
            digitalWrite(HEATER, LOW);
            vTaskDelay(30000 / portTICK_PERIOD_MS);
            digitalWrite(FAN, LOW);
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
                digitalWrite(FAN, HIGH);
                vTaskDelay(30000 / portTICK_PERIOD_MS);
            }
            digitalWrite(FAN, LOW);
            working--;
            Serial.printf("working-- fan. working : %d\n", working);

        }
    }
};

extern AirConditioner ac;

void airConditioningTask(void *);