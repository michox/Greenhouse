#include "Sleep.h"

int working = 0;

void goToSleep()
{
    Serial.println("good night");
    esp_sleep_enable_ext0_wakeup(BUTTON, 0);

    esp_sleep_enable_timer_wakeup(SAMPLE_INTERVAL);
    //Go to sleep now
    esp_deep_sleep_start();
}