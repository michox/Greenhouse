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
    if (read_snail_monitor()) {
        snail_fence_short_circuit = true;
    }
}

void SnailFenceController::activate_fence() {
    gpio_hold_en(SNAIL_FENCE);  // Keep the fence active during sleep
}

void SnailFenceController::deactivate_fence() {
    gpio_hold_dis(SNAIL_FENCE);
}


void SnailFenceController::set_fence_state(bool state) {
    digitalWrite(SNAIL_FENCE, state ? HIGH : LOW);
}

bool SnailFenceController::read_snail_monitor() {
    set_fence_state(HIGH);
    int voltage = digitalRead(SNAIL_MONITOR);
    return voltage;  
}

SnailFenceController snailFenceController;