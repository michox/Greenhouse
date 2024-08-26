#include "Arduino.h"
#include "Pinout.h"
#include "Pump.h"
/*
YF‐ S201 Water Flow Sensor
Water Flow Sensor output processed to read in litres/minute
Adaptation Courtesy: www.hobbytronics.co.uk
*/

volatile uint flowCount = 0; // Measures flow sensor pulses

float flow = 0;         // Calculated litres/minute
float averageFlow = -1; // Calculated litres/minute
void flowCounter()      // Interrupt function
{
    flowCount++;
}

void flowMeasuringTask(void *)
{
    int flowMeasurementsIndex = 0;
    float flowMeasurements[20] = {0};
    pinMode(FLOW_METER, INPUT);
    attachInterrupt(FLOW_METER, flowCounter, RISING); // Setup Interrupt
    sei();                                            // Enable interrupts
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true)
    {

        vTaskDelayUntil(&xLastWakeTime, 100);
        xSemaphoreTake(wateringMutex, portMAX_DELAY);
        #ifdef DEBUG
        flowCount=10;
        #endif
        // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
        flow = (flowCount * 10.) / 75; // (Pulse frequency in Hz) / 7.5Q = flowrate in L/minute
        flowMeasurements[flowMeasurementsIndex++] = flow;
        if (flowMeasurementsIndex >= 20)
        {
            flowMeasurementsIndex = 0;
        }
        // calculate average flow from flow measurements
        float flowSum = 0;
        for (int i = 0; i < 20; i++)
        {
            flowSum += flowMeasurements[i];
        }
        averageFlow = flowSum / 20;
        if (pump.ticksSincePumpStart != -1 && pump.ticksSincePumpStart < INT32_MAX)
        {
            pump.ticksSincePumpStart++;
        }
        flowCount = 0; // Reset Counter
        xSemaphoreGive(wateringMutex);
    }
}
