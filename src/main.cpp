#include <Arduino.h>
#include <FreeRTOS.h>
#include "ButtonTask.h"
#include "AirConditioner.h"
#include "Watering.h"
#include "Display.h"
#include "Sleep.h"
#include "Clock.h"
#include "Pinout.h"

Preferences preferences;
SemaphoreHandle_t mutex = NULL;

void setup()
{
  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_SLOW_MEM, ESP_PD_OPTION_ON);
  Serial.begin(115200);
  preferences.begin("Greenhouse");
  mutex = xSemaphoreCreateMutex();

  xTaskCreate(displayTask, "display", configMINIMAL_STACK_SIZE + 5000, NULL, 20, NULL);
  xTaskCreate(temperatureMeasuringTask, "measure temp", configMINIMAL_STACK_SIZE + 5000, NULL, 10, NULL);
  xTaskCreate(flowMeasuringTask, "measure flow", configMINIMAL_STACK_SIZE + 5000, NULL, 10, NULL);
  xTaskCreate(floatSwitchTask, "float switch", configMINIMAL_STACK_SIZE + 1000, NULL, 1000, NULL);
  xTaskCreate(buttonTask, "button", configMINIMAL_STACK_SIZE + 5000, NULL, 10, NULL);
  xTaskCreate(wateringTask, "watering", configMINIMAL_STACK_SIZE + 5000, NULL, 11, NULL);
  xTaskCreate(airConditioningTask, "ac", configMINIMAL_STACK_SIZE + 5000, NULL, 10, NULL);
  xTaskCreate(clockTask, "clock", configMINIMAL_STACK_SIZE + 5000, NULL, 20, NULL);
  Serial.printf("Setup complete\n");
}

void loop()
{
  vTaskDelay(500/portTICK_PERIOD_MS);
  if (!working)
  {
    goToSleep();
  }
}