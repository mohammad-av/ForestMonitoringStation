#include "task_manager.h"
#include "dht_sensor.h"
#include "ultrasonic_sensor.h"

void c_setup(void)
{
    dhtSensor.init();
    ultrasonicSensor.init();
    task_manager_init();
}

void c_loop(void)
{
    task_manager_run();
}