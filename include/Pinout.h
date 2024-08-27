#pragma once
#include <FreeRTOS.h>

#define RELAY_ON HIGH
#define RELAY_OFF LOW

#define HYGRO_1 GPIO_NUM_36
#define HYGRO_2 GPIO_NUM_39
#define HYGRO_3 GPIO_NUM_34
#define HYGRO_4 GPIO_NUM_35
#define AREA_POTI_1 GPIO_NUM_32
#define AREA_POTI_2 GPIO_NUM_33
#define AREA_POTI_3 GPIO_NUM_25
#define AREA_POTI_4 GPIO_NUM_26
#define AREA_SOLENOID_1 GPIO_NUM_5 
#define AREA_SOLENOID_2 GPIO_NUM_17
#define AREA_SOLENOID_3 GPIO_NUM_16
#define AREA_SOLENOID_4 GPIO_NUM_4

#define FLOW_METER GPIO_NUM_27

#define WATER_AVAILABLE GPIO_NUM_23

#define PUMP GPIO_NUM_12
#define HEATER GPIO_NUM_21
#define FAN GPIO_NUM_12

#define SNAIL_MONITOR GPIO_NUM_18
#define SNAIL_FENCE GPIO_NUM_19

#define BUTTON GPIO_NUM_2

extern SemaphoreHandle_t mutex;
extern SemaphoreHandle_t wateringMutex;
