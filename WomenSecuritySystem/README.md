# IoT Women Security System
This project is an IoT-based Women Security system that utilizes an Arduino, a GSM module, a GPS module, and various sensors to enhance women's safety. The system can send distress messages to predefined contacts, make calls, and provide location information in case of an emergency.

## Overview
The IoT-based Women Security system is designed to ensure the safety of women in case of an emergency. It can send distress messages to predefined contacts with location information and make calls to alert emergency contacts. The system also displays GPS coordinates on an LCD screen.

## Components
- Arduino
- GSM Module (SIM900A)
- GPS Module
- LiquidCrystal Display (LCD)
- Button
- LED
- Various sensors and peripherals

## Setup
1. Connect the components as follows:
- GSM Module: Connect TX and RX pins to Arduino pins 9 and 10.
- GPS Module: Connect RX and TX pins to Arduino pins 3 and 4.
- LCD: Connect using A0 to A5 pins.
- Button: Connect to pin 2.
- LED: Connect to pin 3.
2. Ensure the necessary libraries are installed:
LiquidCrystal.h
SoftwareSerial.h
TinyGPS.h
3. Replace +91xxxxxxxxxx with the actual phone numbers you want to send messages or make calls to in the code.
4. Upload the code to the Arduino.

## Usage
1. The system will continuously monitor the GPS data and display the latitude and longitude on the LCD screen.
2. Pressing the button will trigger the system to send multiple distress messages and attempt to make calls to emergency contacts.
3. If someone responds with 'Y' to the distress messages, the system will make corresponding calls to emergency contacts.
4. The system can also be controlled via serial commands:
- 's': Send a distress message with location.
- 'c': Make a call to emergency contacts.
- 'h': Hang up a call.
- 'e': Redial a call.
- 'i': Receive a call.

## Code Explanation
1. The code is structured into setup and loop functions. Here are some key points:
2. The setup function initializes the GSM, GPS, and LCD modules, sets up pins, and displays instructions for controlling the system via serial communication.
3. The loop function continuously checks for GPS data, displays it on the LCD, and listens for serial commands to trigger various actions.
4. There are several functions for sending distress messages (SendMessage1, SendMessage2, SendMessage3, SendMessage_Police), receiving messages (ReceiveMessage1, ReceiveMessage2, ReceiveMessage3), and making calls (MakeCall_1, MakeCall_2, MakeCall_3).

## Contributors
Riya Soni 

Feel free to add your name and contact information to the list of contributors if you make contributions to this project.
