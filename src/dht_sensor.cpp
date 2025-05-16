#include "dht_sensor.h"
#include <stdlib.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE    DHT22 

DHT dht(DHTPIN, DHTTYPE);

static float temperature = 0.0;
static float humidity = 0.0;

void dht_init(void) 
{
    // Real sensor
    //dht.begin();
}

void dht_update(void)
{
    // Real data
    //temperature = dht.readTemperature();
    // humidity = dht.readHumidity();
    // Mock data
    temperature = 20.0 + (rand() % 100) / 10.0;
    humidity = 40.0 + (rand() % 100) / 10.0;
}

float getTemperature(void)
{
    return temperature;
}

float getHumidity(void)
{
    return humidity;
}

SensorInterface dhtSensor =
{
    .init = dht_init,
    .update = dht_update
};
