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

The system was initially tested on a breadboard to verify the temperature monitoring, warning LED, LCD messages and sensor fault detection before transferring the circuit to the custom PCB.

The manufactured PCB was then assembled and connected to the Arduino Mega 2560 to verify that the completed hardware operated correctly.

| Test | Expected Result | Result |
|------|-----------------|--------|
| Temperature below threshold | LED off and normal-temperature message displayed on the LCD | Pass |
| Temperature above threshold | LED on and high-temperature warning message displayed on the LCD | Pass |
| DHT11 signal disconnected | Warning LED on and sensor error message displayed on the LCD | Pass |
| Battery-powered operation | System operates without a laptop connection | Pass |
| Assembled PCB functionality | All components operate correctly through the custom PCB | Pass |

### Sensor Fault Detection

To test the `isnan()` fault handling, I deliberately disconnected the DHT11 signal. The Arduino detected the invalid sensor reading, activated the warning LED and displayed an error message on the LCD.

### Physical PCB Testing

After soldering the components and headers onto the manufactured PCB, the shield was connected to the Arduino Mega 2560.

The system operated successfully during its initial testing, with the LCD displaying live temperature readings and the warning LED responding to the programmed conditions.

The normal-temperature, high-temperature warning and sensor fault states were successfully tested using the assembled PCB.

The completed system was also tested using a standalone 9V battery connected to the Arduino's power input, confirming that it could operate without a computer connection.

No changes to the PCB design were required for the system to function. However, a possible intermittent solder connection was identified as an area for further inspection.

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

## PCB Manufacturing and Assembly

After completing the PCB design in KiCad, I generated the Gerber and drill files required for manufacturing. These files were uploaded to JLCPCB, where I ordered the custom two-layer PCB.

Once the manufactured boards arrived, I assembled the circuit by soldering the components and pin headers onto the PCB using the soldering facilities at university.

The completed PCB was then connected to the Arduino Mega 2560 and powered using a 9V battery through the Arduino's barrel jack.

During initial testing, I encountered a minor connectivity issue, potentially caused by a solder joint. However, the PCB operated successfully without requiring any modifications to the original design.

This was my first experience taking a PCB design through the complete process of manufacturing, physical assembly and functional testing.

**1. Manufactured PCB before assembly**

<img width="2939" height="1756" alt="abeaa23c-ff28-453b-9b34-27aee167287b" src="https://github.com/user-attachments/assets/2374e473-e207-4f60-a838-000f716533aa" />

**2. Assembled PCB**

<img width="2604" height="1516" alt="7457f3ca-184c-4f7e-a55a-f20ad012b804" src="https://github.com/user-attachments/assets/c8600566-cc69-4fc1-8701-a208054f75a2" />

**3. PCB underside and solder joints**

<img width="2558" height="1445" alt="24507200-7832-4bf4-92d5-ca6c81b51798" src="https://github.com/user-attachments/assets/33186b3a-9a65-4050-886d-782e24a9e84d" />

**4. Completed and operational system**

<img width="3280" height="1908" alt="14abddc6-8759-4831-aed0-3780acbb3313" src="https://github.com/user-attachments/assets/7e0f7d16-b539-445e-9135-867792e6095b" />

## Problems Encountered and Fixes

| Problem | Cause | Fix |
|---|---|---|
| External LED did not light | Both LED legs were connected to the same breadboard node | Repositioned the LED so each leg was connected to a different node |
| LCD displayed dark blocks instead of text | D7 was connected incorrectly | Corrected the LCD wiring so D7 connected to the correct LCD pin |
| Invalid DHT11 reading | Sensor communication failed when the signal was disconnected | Added `isnan()` fault detection, an LCD error message and warning LED activation |
| KiCad ERC/DRC warnings | Unused and duplicated connections in the Arduino Mega template | Used No Connect flags, `PWR_FLAG`s and intentional exclusions where appropriate |

## Final Result

The temperature warning system has been successfully developed, manufactured, assembled and tested.

After completing the circuit design and programming, I designed a custom Arduino Mega shield PCB using KiCad. The PCB was manufactured by JLCPCB, and I soldered all the components myself using the facilities at university.

Following assembly, the system operated successfully without requiring any PCB design modifications. A minor connectivity issue was encountered, potentially caused by a solder joint, but the system was able to function correctly.

The completed system successfully:

- Measures and displays live temperature readings on a 16×2 LCD.

- Detects temperatures exceeding the programmed threshold and displays a high-temperature warning.

- Detects sensor faults and displays an error message.

- Operates independently using a 9V battery connected to the Arduino Mega.

This project allowed me to develop practical skills in electronic circuit design, microcontroller programming, PCB design, soldering, troubleshooting and hardware testing. It was particularly rewarding to see a PCB I had independently designed operate successfully after manufacturing and assembly.

## Project Files

- [Arduino Code](code/Temperature%20Warning%20System.ino)
- [KiCad PCB Files](pcb/)
- [PCB Manufacturing Files (Gerber ZIP)](pcb/Temperature-Warning-System-Gerber-Files.zip.zip)
- [Project Report](documentation/Temperature%20Warning%20system%20report.pdf)

## Future Improvements

A temperature-controlled fan could be added, using PWM (Pulse Width Modulation) to automatically adjust the fan speed based on the measured temperature. This would allow the system to actively regulate temperature rather than simply provide a warning.

User-adjustable buttons could be implemented to allow the temperature warning threshold to be changed without modifying and uploading the Arduino code.

The power supply could be improved by replacing the 9V battery with a more efficient rechargeable power source, allowing the system to operate independently for longer periods.

A protective enclosure could also be designed to house the Arduino, custom PCB and other components, making the completed system more compact and suitable for practical use.
Eventually, the Arduino Mega can be replaced with a microcontroller mounted directly on the PCB.
