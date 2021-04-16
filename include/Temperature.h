#include "Arduino.h"

extern RTC_DATA_ATTR float maxTemperature;
extern RTC_DATA_ATTR float minTemperature;
extern float humidity;
extern float temperature;
extern float topTemperature;
extern float bottomTemperature;
void temperatureMeasuringTask(void *);
