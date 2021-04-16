#include "Rtc_Pcf8563.h"
#include "ESP32Time.h"

extern Rtc_Pcf8563 rtc;
extern ESP32Time systemTime;

#define RESET_HOUR 5

void clockTask(void *);