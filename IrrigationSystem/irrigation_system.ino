int sensorPin = A0;
int sensorValue = 0;
int percent = 0;
String percentString = "0";
int stringLength = 0;
int Gled = 7;
int Rled = 6;

void setup()
{
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    pinMode(Gled, OUTPUT);
    pinMode(Rled, OUTPUT);
}

void loop()
{
    sensorValue = analogRead(sensorPin);
    percent = convertToPercent(sensorValue);
    percentString = String(percent);
    stringLength = percentString.length();
    Serial.print("sensorValue: ");
    Serial.print(sensorValue);
    Serial.print("  percent: ");
    Serial.print(percent);
    Serial.print("%");
    Serial.println("");
    if (percent >= 60)
    {
        digitalWrite(Rled, LOW);
        digitalWrite(Gled, HIGH);
        Serial.println("Moisture Range:greater than 80%");
        delay(1000);
    }
    else
    {
        digitalWrite(Gled, LOW);
        digitalWrite(Rled, HIGH);
        Serial.println("Moisture Range:less than 80%");
        delay(1000);
    }

    delay(1000);
}

int convertToPercent(int value)
{
    int percentValue = 0;
    percentValue = map(value, 1023, 350, 0, 100);
    if (percentValue > 100)
        percentValue = 100;
    return percentValue;
}
