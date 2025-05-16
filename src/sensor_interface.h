#ifndef SENSOR_INTERFACE_H
#define SENSOR_INTERFACE_H

typedef struct
{
    void (*init)(void);
    void (*update)(void);
} SensorInterface;

#endif
