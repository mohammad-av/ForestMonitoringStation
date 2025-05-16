#include "task_manager.h"
#include "timer.h"
#include "dht_sensor.h"
#include "ultrasonic_sensor.h"
#include "reporter.h"
#include "Arduino.h"

static Timer dhtTimer;
static Timer ultraTimer;
static Timer reportTimer;

void task_manager_init(void)
{
    timer_init(&dhtTimer, 2000);
    timer_init(&ultraTimer, 100);
    timer_init(&reportTimer, 5000);
}

void task_manager_run(void)
{
    if (timer_expired(&dhtTimer))
    {
        dhtSensor.update();
    }

    if (timer_expired(&ultraTimer))
    {
        ultrasonicSensor.update();

        float distance = getDistance();
        if (distance < 30.0f)
        {
            reporter_send_warning(distance);
        }
    }

    if (timer_expired(&reportTimer))
    {
        reporter_send_data(getTemperature(), getHumidity(), getDistance());
    }
}
