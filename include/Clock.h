#include "pcf8563.h"
#include "ESP32Time.h"

extern PCF8563_Class rtc;
extern ESP32Time systemTime;

#define RESET_HOUR 20

void clockTask(void *);