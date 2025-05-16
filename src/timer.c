#include "timer.h"
#include "Arduino.h"

void timer_init(Timer* t, uint32_t interval_ms)
{
    t->interval_ms = interval_ms;
    t->last_run = millis();
}

int timer_expired(Timer* t)
{
    uint32_t now = millis();
    if ((now - t->last_run) >= t->interval_ms) {
        t->last_run = now;
        return 1;
    }
    return 0;
}
