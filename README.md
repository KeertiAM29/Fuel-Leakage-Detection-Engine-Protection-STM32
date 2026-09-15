Fuel-Leakage-Detection-Engine-Protection-STM32
STM32-based fuel leakage detection and engine protection system using an MQ-3 gas sensor, ADC-based threshold detection, and automatic motor shutdown.

Fuel Leakage Detection and Engine Protection System using STM32
Overview
An embedded automotive safety system that detects fuel-related vapors using an MQ-3 gas sensor and automatically stops a DC motor representing the vehicle engine when the detected vapor concentration exceeds a predefined threshold.

Objective
To interface an MQ-3 gas sensor with the STM32 microcontroller and implement threshold-based fuel leakage detection with automatic engine shutdown and warning indication.

Hardware
STM32F103C8T6 Blue Pill
MQ-3 Gas Sensor
5–12 V DC Motor
Green LED
Red LED
330 Ω Resistors
Connecting Wires
Working
MQ-3 Sensor → ADC → STM32 → Threshold Decision → Motor / LED Control

During normal conditions, the motor remains running and the green LED indicates safe operation. When the vapor concentration exceeds the predefined threshold, the STM32 stops the motor, turns off the green LED, and activates the red LED as a warning.

Technologies Used
STM32F103C8T6
Embedded C
ADC
GPIO
Sensor Interfacing
Threshold-Based Control
Automotive Safety Monitoring
Results
The system successfully detected alcohol-based vapors used to simulate fuel leakage. When the detected vapor concentration exceeded the threshold, the red LED was activated and the DC motor was stopped to represent engine shutdown.

About
STM32-based fuel leakage detection and engine protection system using an MQ-3 gas sensor, ADC-based threshold detection, and automatic motor shutdown.

Resources
Readme
Activity
Stars
0 stars
Watchers
0 watching
Forks
0 forks
Report repository
Releases
No releases published
Packages
No packages published
Contributors
1
 (1)
@roopashree0204
roopashree0204Roopashree Pote
Footer
