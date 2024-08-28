#include "Sleep.h"
#include "Watering.h"

int working = 0;

void goToSleep()
{
    Serial.println("good night");
    // preferences.putFloat("Water1", spentWaterVolume1);
    // preferences.putFloat("Water2", spentWaterVolume2);
    // preferences.putFloat("Water3", spentWaterVolume3);
    // preferences.putFloat("Water4", spentWaterVolume4);

    esp_sleep_enable_ext0_wakeup(BUTTON, 1);

    esp_sleep_enable_timer_wakeup(SAMPLE_INTERVAL);
    // Go to sleep now
    esp_deep_sleep_start();
}