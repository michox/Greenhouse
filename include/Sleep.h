#include "Arduino.h"
#include "Pinout.h"
#include "FreeRTOS.h"

#define SAMPLE_INTERVAL (1000*1000*60*5) //microseconds

extern int working;

void goToSleep();