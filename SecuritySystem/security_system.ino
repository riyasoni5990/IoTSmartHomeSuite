#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
int PIR1_output = 5; // output of pir 1 sensor
int led1 = 13;       // led pin 1
int PIR2_output = 6; // output of pir  2sensor
int led2 = 12;       // led pin 2
void setup()
{
      pinMode(PIR1_output, INPUT); // setting pir output as arduino input
      pinMode(led1, OUTPUT);       // setting led as output
      pinMode(PIR2_output, INPUT); // setting pir output as arduino input
      pinMode(led2, OUTPUT);       // setting led as output
      Serial.begin(9600);          // serial communication between arduino and pc

      mySerial.begin(9600); // Setting the baud rate of GSM Module
      Serial.begin(9600);   // Setting the baud rate of Serial Monitor (Arduino)
      Serial.println("GSM SIM900A BEGIN");
}
void loop()
{
      if (digitalRead(5) == HIGH) // reading the data from the pir sensor
      {
            digitalWrite(13, HIGH); // setting led to high
            SendMessage1();
            Serial.println("motion detected at 1");
      }
      else
      {
            digitalWrite(13, LOW); // setting led to low
            Serial.println("scanning at 1");
      }
      if (digitalRead(6) == HIGH) // reading the data from the pir sensor
      {
            digitalWrite(12, HIGH); // setting led to high
            SendMessage2();
            Serial.println("motion detected at 2");
      }
      else
      {
            digitalWrite(12, LOW); // setting led to low
            Serial.println("scanning at 2");
      }
}
void SendMessage1()
{
      mySerial.println("AT+CMGF=1");                   // Sets the GSM Module in Text Mode
      delay(1000);                                     // Delay of 1000 milli seconds or 1 second
      mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace x with mobile number
      delay(1000);
      mySerial.println("Student  Activity Identified at 1"); // The SMS text you want to send
      delay(1000);
      mySerial.println((char)26); // ASCII code of CTRL+Z
      delay(10000);
}
void SendMessage2()
{
      mySerial.println("AT+CMGF=1");                   // Sets the GSM Module in Text Mode
      delay(1000);                                     // Delay of 1000 milli seconds or 1 second
      mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace x with mobile number
      delay(1000);
      mySerial.println("Student  Activity Identified at 2"); // The SMS text you want to send
      delay(1000);
      mySerial.println((char)26); // ASCII code of CTRL+Z
      delay(10000);
}
