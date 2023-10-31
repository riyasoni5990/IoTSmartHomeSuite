#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <ArduinoOTA.h>
#define BLYNK_PRINT Serial
#include <ESP8266HTTPClient.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "mBh3nKXXTxJVZj84zgiZUW_m-XyBleNH";
const long utcOffsetInSeconds = 19800;
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
const char *ssid = "GITS";
const char *password = "";
byte arduino_mac[] = {0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED};
IPAddress device_ip(172, 16, 6, 8);
IPAddress dns_ip(8, 8, 8, 8);
IPAddress gateway_ip(172, 16, 17, 1);
IPAddress subnet_mask(255, 255, 0, 0);
unsigned long time_1 = 0;
unsigned long time_2 = 0;
void turnoffall(int deviceno)
{
    HTTPClient http;
    char offcommand[] = "[\"1\"]";
    if (deviceno == 1)
    {
        http.begin("http://188.166.206.43/mBh3nKXXTxJVZj84zgiZUW_m-XyBleNH/update/D4");
    }
    else
    {
        http.begin("http://188.166.206.43/mBh3nKXXTxJVZj84zgiZUW_m-XyBleNH/update/D0");
    }
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.PUT(offcommand);
    http.end();
}
void setup()
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.config(device_ip, dns_ip, gateway_ip, subnet_mask);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        delay(5000);
        ESP.restart();
    }
    ArduinoOTA.setHostname("Smart-Home-GITS");

    ArduinoOTA.setPassword("Security123");

    ArduinoOTA.onStart([]()
                       {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem"; });
    ArduinoOTA.onEnd([]() {});
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {});
    ArduinoOTA.onError([](ota_error_t error)
                       {
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed"); });
    ArduinoOTA.begin();
    // Setup Blynk
    Blynk.config(auth);
    while (Blynk.connect() == false)
    {
    }
    turnoffall(1);
    turnoffall(2);
    timeClient.begin();
}

void Blynk_Delay(int milli)
{
    if (millis() > time_1 + milli)
    {
        time_1 = millis();
        Blynk.run();
    }
}
void loop()
{
    ArduinoOTA.handle();
    timeClient.update();
    if (timeClient.getHours() > 16 || (timeClient.getHours() == 16 && timeClient.getMinutes() >= 15) || timeClient.getHours() < 8 || (timeClient.getHours() == 8 && timeClient.getMinutes() <= 45) || timeClient.getDay() == 0)
    {
        if (millis() > time_2 + 60000)
        {
            time_2 = millis();
            turnoffall(1);
            turnoffall(2);
        }
    }
    Blynk_Delay(3000);
}
