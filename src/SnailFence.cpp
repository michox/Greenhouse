#include "SnailFence.h"
#include <Arduino.h>

// Global variable to track short circuit status
bool snail_fence_short_circuit = false;

SnailFenceController::SnailFenceController() {
    // Constructor (if needed)
}

void SnailFenceController::init() {
    // Setup the pin modes
    pinMode(SNAIL_FENCE, OUTPUT);
    pinMode(SNAIL_MONITOR, INPUT);

    // Check for initial short circuit
    check_short_circuit();
    if (snail_fence_short_circuit) {
        deactivate_fence();
    }
    else{
        activate_fence();
    }
}

void SnailFenceController::check_short_circuit() {
    if (read_snail_monitor() == LOW) {
        snail_fence_short_circuit = true;
    }
    else
        snail_fence_short_circuit = false;
}

void SnailFenceController::activate_fence() {
    set_fence_state(HIGH);
}

void SnailFenceController::deactivate_fence() {
    
    set_fence_state(LOW);
}


void SnailFenceController::set_fence_state(bool state) {
    gpio_hold_dis(SNAIL_FENCE); //disable pad holding
    digitalWrite(SNAIL_FENCE, state ? HIGH : LOW);
    gpio_hold_en(SNAIL_FENCE); //enable pad holding so that the signal is held during deep sleep.

}

bool SnailFenceController::read_snail_monitor() {
    set_fence_state(HIGH);
    int voltage = digitalRead(SNAIL_MONITOR);
    return voltage;  
}

SnailFenceController snailFenceController;