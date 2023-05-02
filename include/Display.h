#pragma once
#include "OLEDDisplayUi.h"

enum Frames{
    SCREEN_OFF,
    ALERT_FRAME,
    MAIN_FRAME,
    AREA_FRAME_0,
    AREA_FRAME_1,
    AREA_FRAME_2,
    AREA_FRAME_3,
    TEMPERATURE_FRAME,
    CLOCK_FRAME,

    FRAME_COUNT
};

extern OLEDDisplayUi ui;
void displayTask(void *);
