# Forest Environment Monitoring Station (ESP32)

A modular and non-blocking firmware for an ESP32-based forest environment monitoring station. The system continuously measures environmental parameters such as 
temperature, humidity, and obstacle distance, sending the data over UART in JSON format.

---

#  Features

-  Measure temperature and humidity (DHT22) every 2 seconds
-  Measure obstacle distance (SRF05) every 100 milliseconds
-  Send full JSON reports via UART every 5 seconds
-  Send immediate warnings if obstacle distance is below 30 cm
-  Modular and clean software architecture
-  Non-blocking, timer-based task management (millis-based)
-  JSON log output via Serial Monitor

---

# Software Architecture
+-----------------------------+
| main.cpp/.c                 |
| Arduino setup() / loop()    |
+-------------+---------------+
              |
              v
+-------------+---------------+
| task_manager.c               |
| Manages task scheduling      |
+-------------+---------------+
      |                  |
      v                  v
+------------+ +------------------+
| dht_sensor | | ultrasonic_sensor |
+------------+ +------------------+
              |
              v
        +------------+
        | reporter    |
        +------------+

# Project Structure
src/
├── main.cpp → Arduino setup() and loop()
├── main.c → c_setup() and c_loop()
├── task_manager.c/.h → Task scheduling and timers
├── timer.c/.h → Simple software timers (millis-based)
├── dht_sensor.cpp/.h → DHT22 management module
├── ultrasonic_sensor.c/.h → SRF05 management module
├── reporter.c/.h → JSON logging and UART reporting
├── sensor_interface.h → Sensor interface definition
platformio.ini → PlatformIO project configuration

# Requirements:
- ESP32 DevKit V1 board  
- PlatformIO IDE (VS Code extension)  
- Adafruit DHT sensor library

Add this to `platformio.ini`:
monitor_speed = 115200
build_flags = 
	-std=gnu99
	-Wall
	-Wextra
	-Wno-unused-parameter
lib_deps = adafruit/DHT sensor library@^1.4.6

# Hardware Setup
`DHT20`:
| Pin  | ESP32  |
| ---- |  ----- |
| VCC  | 3.3V   |
| GND  | GND    |
| DATA | GPIO 2 |

`SRF05`:
| Pin  | ESP32                                          |
| ---- | ---------------------------------------------- |
| VCC  | 5V                                             |
| GND  | GND                                            |
| Trig | GPIO 13                                        |
| Echo | GPIO 12 (use voltage divider or level shifter) |

# Example Serial Output
{"temperature": 25.10,"humidity": 45.20 , "distance": 57.40}
{"warning": "object detected!", "distance": 26.10}

# Future Improvements
Smarter logs (status classification and event counting)
SD card data logging module
Additional sensors (gas, light,...)
