# Temperature-Warning-System
Embedded temperature monitoring and warning system using an Arduino Mega 2560, DHT11, 16×2 LCD, and custom KiCad shield PCB
## Overview
Using the Arduino Mega I measured the temperature with a DHT11 sensor and had the live temperature reading displayed on the 16×2 LCD. When the set temperature threshold was exceeded a warning LED turns on with a warning message on the 16×2 LCD. For sensor faults the warning LED turns on with a check sensor message on the 16×2 LCD. Finally a custom Mega shield PCB was designed in KiCad.
## Features
- Live temperature measurement
- Temperature threshold warning
- Sensor fault detection
- LCD status messages
- Standalone battery operation
- Custom PCB shield
## Hardware Used
- ELEGOO Arduino Mega 2560
- DHT11 temperature and humidity module
- 1602A V2.0 16×2 LCD
- 10 kΩ potentiometer
- LED
- 220 Ω resistor
- Breadboard
- Jumper wires
- Battery power supply
- Custom Arduino Mega shield PCB designed in KiCad to replace the breadboard and jumper wires
## System Operation
First the DHT11 takes the temperature reading, then it sends the data to the Mega and using the code uploaded on the Mega it displays the temperature on the LCD. If the temperature threshold is exceeded the warning LED turns on and a warning message is displayed on the LCD. And finally the function `isnan()` is used to detect an invalid sensor reading which activates the warning LED and error message on the LCD.
## Testing and Fault Handling

## PCB Design
## Problems Encountered and Fixes
## Final Result
## Future Improvements
