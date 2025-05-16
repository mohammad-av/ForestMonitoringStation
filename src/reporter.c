#include "reporter.h"
#include "Arduino.h"


void reporter_send_data(float temp, float hum, float dist)
{
    printf("{\"temperature\": %.2f,\"humidity\": %.2f , \"distance\": %.2f}\n",temp,hum, dist);
}

void reporter_send_warning(float dist)
{
    printf("{\"warning\": \"object detected!\", \"distance\": %.2f}\n", dist);
}
