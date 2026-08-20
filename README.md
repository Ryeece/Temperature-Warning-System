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

First the DHT11 takes the temperature reading, then it sends the data to the Mega and the Mega processes the reading using the uploaded code and displays the temperature on the LCD. If the temperature threshold is exceeded the warning LED turns on and a warning message is displayed on the LCD. Finally the function `isnan()` is used to detect an invalid sensor reading which activates the warning LED and error message on the LCD.

## Breadboard Prototype
The system was first built and tested on a breadboard before being transferred into the custom Arduino Mega shield PCB design.

The temperature threshold was temporarily set to 29.8°C so the high-temperature warning could be tested at room temperature.

- Normal operation — LCD shows live temperature and Normal temp, LED off:

<img width="485" height="418" alt="Normal operation" src="https://github.com/user-attachments/assets/fe96e190-a4d9-4b99-ac2d-5ec7e6bef2c7" />

- High-temperature warning — LCD shows TEMP TOO HIGH, warning LED on:

<img width="519" height="418" alt="High-temperature warning" src="https://github.com/user-attachments/assets/78f6b438-1282-4f8d-8de5-5e1e760caea6" />

- Sensor fault — LCD shows the sensor error message, warning LED on:

<img width="485" height="426" alt="Sensor fault" src="https://github.com/user-attachments/assets/3776b65e-7e59-48ca-ad5a-70ac5dcb2880" />

## Testing and Fault Handling

| Test | Expected Result | Result |
|---|---|---|
| Temperature below threshold | LED off and normal-temperature message displayed on the LCD | Pass |
| Temperature above threshold | LED on and high-temperature warning message displayed on the LCD | Pass |
| DHT11 signal disconnected | Warning LED on and sensor error message displayed on the LCD | Pass |
| Battery-powered operation | System operates without the laptop connection | Pass |

To test the `isnan()` fault handling, I deliberately disconnected the DHT11 signal.

## PCB Design

The PCB was designed as an Arduino Mega shield so it could plug directly into the Mega.

- A 16-pin header was added for the 16×2 LCD and a 3-pin header for the DHT11
- The LED, 220 Ω resistor and 10 kΩ potentiometer were placed on the shield
- The breadboard prototype was used to help plan the PCB layout
- ERC and DRC were used to check the design
- The final layout was checked in KiCad's 3D Viewer

KiCad schematic:

<img width="995" height="630" alt="KiCad schematic" src="https://github.com/user-attachments/assets/e7f6db50-3395-4979-85ab-742f3f90b226" />

KiCad PCB layout:

<img width="1014" height="542" alt="KiCad PCB layout" src="https://github.com/user-attachments/assets/fc13e170-69f7-49f1-b91a-5bb3717faa6d" />

3D view of the PCB Mega shield:

<img width="627" height="556" alt="3D view of the PCB Mega shield" src="https://github.com/user-attachments/assets/edd0cc0d-a606-4631-9a60-22abe778bf9d" />

The Mega-template header footprints mainly establish the correct physical positions. In place of the female headers, male headers will be soldered underneath the physical PCB to allow connection to the Mega 2560, and female headers will be soldered on top for removable connections for the DHT11 and LCD.

## Problems Encountered and Fixes

| Problem | Cause | Fix |
|---|---|---|
| External LED did not light | Both LED legs were connected to the same breadboard node | Repositioned the LED so each leg was connected to a different node |
| LCD displayed dark blocks instead of text | D7 was connected incorrectly | Corrected the LCD wiring so D7 connected to the correct LCD pin |
| Invalid DHT11 reading | Sensor communication failed when the signal was disconnected | Added `isnan()` fault detection, an LCD error message and warning LED activation |
| KiCad ERC/DRC warnings | Unused and duplicated connections in the Arduino Mega template | Used No Connect flags, `PWR_FLAG`s and intentional exclusions where appropriate |

## Final Result

The DHT11 live temperature measurement was displayed on the LCD with a warning LED and high-temperature message when the temperature threshold was exceeded. The sensor fault detection worked by activating the warning LED and displaying an error message on the LCD. The system operated independently using battery power. The custom Mega shield PCB design was completed and checked with ERC and DRC, but the physical PCB manufacturing/soldering is still pending.

## Project Files

- [Arduino Code](code/Temperature%20Warning%20System.ino)
- [KiCad PCB Files](pcb/)
- [Project Report](documentation/Temperature%20Warning%20system%20report.pdf)

## Future Improvements

A temperature-controlled fan could be added that uses PWM (Pulse Width Modulation) based on the temperature, allowing the cooling rate to increase or decrease when needed.

To ensure the system never needs a temperature threshold code change again, some user-adjustable buttons to alter the threshold could be added.

The manufacturing and soldering of the custom PCB need to be completed.

Eventually, the Arduino Mega can be replaced with a microcontroller mounted directly on the PCB.

