#ifndef REPORTER_H
#define REPORTER_H

void reporter_send_data(float temp, float hum, float dist);
void reporter_send_warning(float dist);

#endif
