char data = 0;
const int button = 2;
const int led = 3;
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>
SoftwareSerial mySerial(9, 10);
SoftwareSerial gpsSerial(3, 4); // rx,tx
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
TinyGPS gps; // create gps object
char msg;
char call;
double lat = 27.112123;
double lon = 35.233223;
void setup()
{
    mySerial.begin(9600);  // Setting the baud rate of GSM Module
    Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
    gpsSerial.begin(9600); // connect gps sensor
    lcd.begin(16, 2);
    Serial.println("GSM SIM900A BEGIN");
    Serial.println("Enter character for control option:");
    Serial.println("h : to disconnect a call");
    Serial.println("i : to receive a call");
    Serial.println("s : to send message");
    Serial.println("c : to make a call");
    Serial.println("e : to redial");
    Serial.println();
    delay(100);
    pinMode(button, INPUT_PULLUP);
    pinMode(led, OUTPUT);
}
void loop()
{
    while (gpsSerial.available())
    {                                     // check for gps data
        if (gps.encode(gpsSerial.read())) // encode gps data
        {
            gps.f_get_position(&lat, &lon); // get latitude and longitude
            // display position
            lcd.clear();
            lcd.setCursor(1, 0);
            lcd.print("GPS Signal");
            // Serial.print("Position: ");
            // Serial.print("Latitude:");
            // Serial.print(lat,6);
            // Serial.print(";");
            // Serial.print("Longitude:");
            // Serial.println(lon,6);
            lcd.setCursor(1, 0);
            lcd.print("LAT:");
            lcd.setCursor(5, 0);
            lcd.print(lat);
            // Serial.print(lat);
            // Serial.print(" ");
            lcd.setCursor(0, 1);
            lcd.print(",LON:");
            lcd.setCursor(5, 1);
            lcd.print(lon);
        }
    }
    String latitude = String(lat, 6);
    String longitude = String(lon, 6);
    Serial.println(latitude + ";" + longitude);
    delay(1000);
    if (Serial.available() > 0)
        switch (Serial.read())
        {
        case 's':
            SendMessage();
            break;
        case 'c':
            MakeCall();
            break;
        case 'h':
            HangupCall();
            break;
        case 'e':
            RedialCall();
            break;
        case 'i':
            ReceiveCall();
            break;
        }
    int button_state = digitalRead(button);
    if ((button_state == LOW) & (data == '0'))
    {
        SendMessage1();
        delay(2000);
        SendMessage2();
        delay(2000);
        SendMessage3();
        delay(2000);
        SendMessage_Police();
        delay(2000);
        ReceiveMessage1();
        data = msg;
        if (data == 'y')
        {
            MakeCall_1();
        }
        else
        {
            ReceiveMessage2();
            data = msg;
            if (data == 'y')
            {
                MakeCall_2();
            }
            else
            {
                ReceiveMessage3();
                data = msg;
                if (data == 'y')
                {
                    MakeCall_3();
                }
            }
        }
    }
}
void SendMessage_Police()
{
    mySerial.println("AT+CMGF=1");                   // Sets the GSM Module in Text Mode
    delay(1000);                                     // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("HELP ME ! HELP ME!"); // The SMS text you want to send
    delay(100);
    mySerial.println("Latitude:"); // The SMS text you want to send
    delay(100);
    mySerial.println("lat"); // The SMS text you want to send
    delay(100);
    mySerial.println("Longitude:"); // The SMS text you want to send
    delay(100);
    mySerial.println("lon"); // The SMS text you want to send
    delay(100);
    mySerial.println((char)50); // ASCII code of CTRL+Z
    delay(1000);
}
void SendMessage1()
{
    mySerial.println("AT+CMGF=1");                   // Sets the GSM Module in Text Mode
    delay(1000);                                     // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("HELP ME ! HELP ME!"); // The SMS text you want to send
    delay(100);
    mySerial.println("Latitude:"); // The SMS text you want to send
    delay(100);
    mySerial.println("lat"); // The SMS text you want to send
    delay(100);
    mySerial.println("Longitude:"); // The SMS text you want to send
    delay(100);
    mySerial.println("lon"); // The SMS text you want to send
    delay(100);
    mySerial.println("If You can help me Now...after checking my location then send me 'Y' other than 'N'"); // The SMS text you want to send
    delay(100);
    mySerial.println((char)50); // ASCII code of CTRL+Z
    delay(1000);
}
void SendMessage2()
{
    mySerial.println("AT+CMGF=1");                   // Sets the GSM Module in Text Mode
    delay(1000);                                     // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("HELP ME ! HELP ME!"); // The SMS text you want to send
    delay(100);
    mySerial.println("Latitude:"); // The SMS text you want to send
    delay(100);
    mySerial.println("lat"); // The SMS text you want to send
    delay(100);
    mySerial.println("Longitude:"); // The SMS text you want to send
    delay(100);
    mySerial.println("lon"); // The SMS text you want to send
    delay(100);
    mySerial.println("If You can help me Now...after checking my location then send me 'Y' other than 'N'"); // The SMS text you want to send
    delay(100);
    mySerial.println((char)50); // ASCII code of CTRL+Z
    delay(1000);
}
void SendMessage3()
{
    mySerial.println("AT+CMGF=1");                   // Sets the GSM Module in Text Mode
    delay(1000);                                     // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("HELP ME ! HELP ME!"); // The SMS text you want to send
    delay(100);
    mySerial.println("Latitude:"); // The SMS text you want to send
    delay(100);
    mySerial.println("lat"); // The SMS text you want to send
    delay(100);
    mySerial.println("Longitude:"); // The SMS text you want to send
    delay(100);
    mySerial.println("lon"); // The SMS text you want to send
    delay(100);
    mySerial.println("If You can help me Now...after checking my location then send me 'Y' other than 'N'"); // The SMS text you want to send
    delay(100);
    mySerial.println((char)50); // ASCII code of CTRL+Z
    delay(1000);
}
void ReceiveMessage1()
{
    mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
    delay(1000);
    if (mySerial.available() > 0)
    {
        msg = mySerial.read();
        Serial.print(msg);
    }
}
void ReceiveMessage2()
{
    mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
    delay(1000);
    if (mySerial.available() > 0)
    {
        msg = mySerial.read();
        Serial.print(msg);
    }
}
void ReceiveMessage3()
{
    mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
    delay(1000);
    if (mySerial.available() > 0)
    {
        msg = mySerial.read();
        Serial.print(msg);
    }
}
void MakeCall_1()
{
    mySerial.println("ATD+91xxxxxxxxxx;");      // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
    Serial.println("Calling to first person "); // print response over serial port
    delay(1000);
}
void MakeCall_2()
{
    mySerial.println("ATD+91xxxxxxxxxx;");       // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
    Serial.println("Calling to second person "); // print response over serial port
    delay(1000);
}
void MakeCall_3()
{
    mySerial.println("ATD+91xxxxxxxxxx;");      // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
    Serial.println("Calling to third person "); // print response over serial port
    delay(1000);
}
