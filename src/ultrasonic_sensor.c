#include "ultrasonic_sensor.h"
#include "Arduino.h"
#include <stdlib.h>

#define TRIG_PIN 13
#define ECHO_PIN 12

static float distance = 0.0;

void ultrasonic_init(void)
{
    // Real sensor
    //pinMode(TRIG_PIN, OUTPUT);
    //pinMode(ECHO_PIN, INPUT);
}

void ultrasonic_update(void)
{
    // Real data
    /*
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms time out for max 5m distance
    distance = (duration * 0.0343) / 2.0;
    */
    // Mock data
    distance = 20.0 + (rand() % 500) / 10.0;
}

float getDistance(void) {
    return distance;
}

SensorInterface ultrasonicSensor =
{
    .init = ultrasonic_init,
    .update = ultrasonic_update
};
