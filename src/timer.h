#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

typedef struct
{
    uint32_t interval_ms;
    uint32_t last_run;
} Timer;

void timer_init(Timer* t, uint32_t interval_ms);
int timer_expired(Timer* t);

#endif