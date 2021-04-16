#include "Arduino.h"

extern RTC_DATA_ATTR float maxTemperature;
extern RTC_DATA_ATTR float minTemperature;
extern float humidity;
extern float temperature;

void temperatureMeasuringTask(void *);
