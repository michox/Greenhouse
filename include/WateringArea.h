#pragma once
#include "Arduino.h"
#include "Hygrometer.h"
#include "FloatSwitch.h"
#include "FlowMeter.h"
#include "Pump.h"
#include "Preferences.h"

extern Preferences preferences;

extern RTC_DATA_ATTR float spentWaterVolume1;
extern RTC_DATA_ATTR float spentWaterVolume2;
extern RTC_DATA_ATTR float spentWaterVolume3;
extern RTC_DATA_ATTR float spentWaterVolume4;

enum WATERING_MODE
{
    AUTO_MODE,
    MANU_MODE
};

class WateringArea
{
private:
    uint solenoidPin;
    uint potentiometerPin;
    Hygrometer *hygro;

    char *preferencesKey;
    float dailyTarget; // l
    uint64_t timeOfLastWaterCalculation = 0;

public:
    WATERING_MODE mode = MANU_MODE;
    WateringArea(uint solenoidPin, uint potentiometerPin, Hygrometer *hygro) : solenoidPin(solenoidPin), potentiometerPin(potentiometerPin), hygro(hygro)
    {
        adcAttachPin(potentiometerPin);
        String storageAddress = "mode" + String(solenoidPin);
        this->mode = (WATERING_MODE)preferences.getInt(storageAddress.c_str());
        pinMode(solenoidPin, OUTPUT);
        digitalWrite(solenoidPin, RELAY_OFF);
    }

    void switchMode()
    {
        mode = mode == AUTO_MODE ? MANU_MODE : AUTO_MODE;
        String storageAddress = "mode" + String(solenoidPin);
        preferences.putInt(storageAddress.c_str(), mode);
    }

    String printModeName()
    {
        return mode == AUTO_MODE ? "auto" : "manu";
    }

    float readDailyTarget()
    {
        uint reading = analogRead(potentiometerPin);
        dailyTarget = map(reading, 0, 4096, 0, 100);
        return dailyTarget;
    }

    float currentHumidity()
    {
        return hygro->read();
    }

    float getSpentWaterVolume()
    {
        switch (solenoidPin)
        {
        case AREA_SOLENOID_1:
            return spentWaterVolume1;
        case AREA_SOLENOID_2:
            return spentWaterVolume2;
        case AREA_SOLENOID_3:
            return spentWaterVolume3;
        case AREA_SOLENOID_4:
            return spentWaterVolume4;
        default:
            return 999; //error
        }
    }

    void setSpentWaterVolume(float newVolume)
    {
        switch (solenoidPin)
        {
        case AREA_SOLENOID_1:
            spentWaterVolume1 = newVolume;
            break;
        case AREA_SOLENOID_2:
            spentWaterVolume2 = newVolume;
            break;
        case AREA_SOLENOID_3:
            spentWaterVolume3 = newVolume;
            break;
        case AREA_SOLENOID_4:
            spentWaterVolume4 = newVolume;
            break;
        }
    }

    float spentLiters()
    {
        return getSpentWaterVolume() / 1000;
    }

    bool needsMoreWater()
    {
        if (mode == AUTO_MODE)
        {
            return (hygro->read() < readDailyTarget());
        }
        else
        {
            return (spentLiters() < readDailyTarget());
        }
    }

    bool water()
    {
        xSemaphoreTake(wateringMutex, portMAX_DELAY);
        if (pump.notBlocked())
        {
            if (waterAvailable && needsMoreWater())
            {
                countWater();
                digitalWrite(solenoidPin, RELAY_ON);
                if (!pump.isRunning())
                {
                    pump.run();
                }
                xSemaphoreGive(wateringMutex);
                return true;
            }
            else
            {
                digitalWrite(solenoidPin, RELAY_OFF);
                pump.stop();
                xSemaphoreGive(wateringMutex);
                return false;
            }
        }
        else
        {
            auto ticksSincePumpStart = pump.ticksSincePumpStart;
            pump.stop();
            digitalWrite(solenoidPin, RELAY_OFF);
            pump.ticksSincePumpStart = ticksSincePumpStart;
            xSemaphoreGive(wateringMutex);
            return false;
        }
        xSemaphoreGive(wateringMutex);
    }

    void countWater()
    {        
        auto timeOfThisWaterCalculation = millis();
        if (timeOfLastWaterCalculation == 0) // first time
        {
            timeOfLastWaterCalculation = timeOfThisWaterCalculation;
            return;
        }
        auto millisSinceLastCalculation = timeOfThisWaterCalculation - timeOfLastWaterCalculation; // should be rollover safe
        timeOfLastWaterCalculation = timeOfThisWaterCalculation;
        float spentWaterSinceLastCalculation = flow / 60. * millisSinceLastCalculation; // / 1000 ms/s *1000 ml/l
        setSpentWaterVolume(getSpentWaterVolume() + spentWaterSinceLastCalculation);
    }
};
