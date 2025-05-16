#include <Arduino.h>

extern "C" {
    void c_setup(void);
    void c_loop(void);
}

void setup() {
    Serial.begin(115200);
    c_setup();
}

void loop() {
    c_loop();
}