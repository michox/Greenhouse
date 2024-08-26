#pragma once
#include "Pinout.h"

extern bool snail_fence_short_circuit;

class SnailFenceController {
public:
    SnailFenceController();
    void init();
private:
    void check_short_circuit();
    void activate_fence();
    void deactivate_fence();
    void set_fence_state(bool state);
    bool read_snail_monitor();
};

extern SnailFenceController snailFenceController;
