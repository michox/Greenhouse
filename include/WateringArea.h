#pragma once
#include "Arduino.h"
#include "Hygrometer.h"
#include "FloatSwitch.h"
#include "FlowMeter.h"
#include "Pump.h"
#include "Preferences.h"

extern Preferences preferences;

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
    float &spentWaterVolume; //ml
    char *preferencesKey;
    float dailyTarget; //ml
    time_t timeOfLastWaterCalculation;

public:
    WATERING_MODE mode = MANU_MODE;
    WateringArea(uint solenoidPin, uint potentiometerPin, Hygrometer *hygro, float &spentWaterVolume) : solenoidPin(solenoidPin), potentiometerPin(potentiometerPin), hygro(hygro), spentWaterVolume(spentWaterVolume)
    {
        adcAttachPin(potentiometerPin);
        String storageAddress = "mode" + String(solenoidPin);
        this->mode = (WATERING_MODE)preferences.getInt(storageAddress.c_str());
    }

    void switchMode()
    {
        mode = mode == AUTO_MODE ? MANU_MODE : AUTO_MODE;
        String storageAddress = "mode" + String(solenoidPin);
        preferences.putInt(storageAddress.c_str(), mode);
    }

    String printModeName()
    {
        return mode == AUTO_MODE ? "manu" : "auto";
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

    float spentLiters()
    {
        return spentWaterVolume / 1000;
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
        countWater();
        if (waterAvailable && needsMoreWater())
        {
            digitalWrite(solenoidPin, HIGH);
            pump.run();
            return true;
        }
        else
        {
            digitalWrite(solenoidPin, LOW);
            pump.stop();
            return false;
        }
    }

    void countWater()
    {
        uint32_t timeOfThisWaterCalculation = millis();
        uint64_t timeSinceLastCalculation = timeOfThisWaterCalculation - timeOfLastWaterCalculation;
        timeOfLastWaterCalculation = timeOfThisWaterCalculation;

        spentWaterVolume += flow / (60 * 60) * timeSinceLastCalculation;
    }
};

