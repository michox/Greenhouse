#include "Arduino.h"
#include "Pinout.h"
/*
YF‐ S201 Water Flow Sensor
Water Flow Sensor output processed to read in litres/hour
Adaptation Courtesy: www.hobbytronics.co.uk
*/

volatile int flow_frequency = 0; // Measures flow sensor pulsesunsigned

float flow;                   // Calculated litres/hour
void flowCounter() // Interrupt function
{
    flow_frequency++;
}

void flowMeasuringTask()
{
    pinMode(FLOW_METER, INPUT);
    digitalWrite(FLOW_METER, HIGH);          // Optional Internal Pull-Up
    attachInterrupt(FLOW_METER, flowCounter, RISING); // Setup Interrupt
    sei();                                   // Enable interrupts
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true)
    {
        // Every second, calculate and print litres/hour
        vTaskDelayUntil(&xLastWakeTime, 1000);
        // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
        flow = (flow_frequency / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
        flow_frequency = 0;            // Reset Counter
    }
}
