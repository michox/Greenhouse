#pragma once
#include "WateringArea.h"
#include <vector>

extern std::vector<WateringArea> areas;

extern RTC_DATA_ATTR float spentWaterVolume1;
extern RTC_DATA_ATTR float spentWaterVolume2;
extern RTC_DATA_ATTR float spentWaterVolume3;
extern RTC_DATA_ATTR float spentWaterVolume4;

void wateringTask(void *);