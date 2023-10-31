# IoT-Based Irrigation System
This README.md file explains the code for an IoT-based Irrigation system. This system monitors soil moisture using a soil moisture sensor and controls two LEDs to indicate the moisture level. The green LED (Gled) turns on when the soil moisture is above 60%, and the red LED (Rled) turns on when it's below or equal to 60%. This document provides an overview of the code and its functionality.

## Components
- Soil Moisture Sensor connected to analog pin A0.
- Green LED (Gled) connected to digital pin 7.
- Red LED (Rled) connected to digital pin 6.

## Setup and Configuration
1. Connect the soil moisture sensor and LEDs to your microcontroller as described in the code.
2. Ensure that you have the Arduino IDE or another compatible development environment.
3. Upload the code to your microcontroller.
4. Observe the LEDs to understand the moisture level in the soil.

## Code Explanation
1. The code starts by initializing variables, pins, and serial communication for debugging.
2. In the loop function:
- The soil moisture sensor value is read using analogRead.
- The convertToPercent function maps the sensor value to a percentage (0-100) representing soil moisture.
- The code prints the sensor value and percentage to the serial monitor for debugging.
- If the moisture level is greater than or equal to 60%, the green LED is turned on and the red LED is turned off, indicating sufficient moisture. Otherwise, the red LED is turned on, indicating low moisture.
3. The delay function is used to pause the program briefly to avoid rapid state changes.
4. The convertToPercent function maps the analog sensor value to a percentage scale, taking into account the range of values that the sensor produces.

## Usage
1. Connect the soil moisture sensor to the designated analog pin (A0) and the LEDs to the specified digital pins (6 and 7) on your microcontroller.
2. Upload the code to your microcontroller using the Arduino IDE.
3. Open the serial monitor to view the moisture sensor readings and moisture percentage.
4. Observe the LEDs:
- Green LED (Gled) indicates sufficient soil moisture (above 60%).
- Red LED (Rled) indicates low soil moisture (60% or below).

Feel free to modify and extend the code to suit your specific soil moisture monitoring and irrigation needs. Enjoy your IoT-based Irrigation System!
