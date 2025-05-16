#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include "sensor_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

extern SensorInterface dhtSensor;

float getTemperature(void);
float getHumidity(void);
void dht_init(void);
void dht_update(void);

#ifdef __cplusplus
}
#endif

#endif
