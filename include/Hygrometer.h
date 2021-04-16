#pragma once
#include "Arduino.h"

class Hygrometer
{
public:
    Hygrometer(uint pin) : pin(pin){
        adcAttachPin(pin);
    };
    float read()
    {
        // When the plant is watered well the sensor will read a value 380~400, I will keep the 400
        // value but if you want you can change it below.

        float value = analogRead(pin);        //Read analog value
        value = constrain(value, 400, 1023);   //Keep the ranges!
        value = map(value, 400, 4096, 100, 0); //Map value : 400 will be 100 and 4096 will be 0
        return value;
    }
    bool isDry(){
        if (read()<100) return true;
        else return false;
    }

private:
    uint pin;
};

