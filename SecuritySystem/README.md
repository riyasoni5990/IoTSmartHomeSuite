# IoT-Based Security System
This code is for an IoT-based security system that uses PIR (Passive Infrared) sensors to detect motion and sends a notification via a GSM module. The system consists of two PIR sensors (PIR1 and PIR2), each with an associated LED (LED1 and LED2), and a GSM module for sending alerts via SMS.

## Components:
1. Arduino board
2. PIR sensors (2)
3. LEDs (2)
4. GSM Module (e.g., SIM900A)
5. Power supply for the GSM module
6. Connecting wires

## Libraries:
- SoftwareSerial

## Code Explanation:
1. Initialization:
- The code begins by including the necessary library, SoftwareSerial, for communication with the GSM module. It initializes two PIR sensors (PIR1 and PIR2) and their corresponding LEDs (LED1 and LED2), sets up serial communication with the PC, and configures the GSM module's baud rate.

2. Main Loop:
- The loop() function continuously monitors the PIR sensors for motion. If motion is detected by PIR1 or PIR2, the corresponding LED is turned on, and an SMS notification is sent using the GSM module. The system logs messages to the serial monitor for debugging.

3. SMS Notification Functions:
- Two functions, SendMessage1() and SendMessage2(), are responsible for sending SMS notifications. They use AT commands to configure the GSM module in text mode, specify the recipient's phone number, and send a predefined message indicating student activity at the respective sensor.

Feel free to modify and extend the code to suit your specific needs. Enjoy your IoT-based Security System!
