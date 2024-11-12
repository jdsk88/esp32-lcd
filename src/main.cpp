#define AA_FONT_SMALL "Aleo-Regular-PL"

#include <WiFi.h>
#include <WiFiClientSecure.h>

const char *ssid = "";      // your network SSID (name)
const char *password = ""; // your network password

#include <iostream>

#include <FS.h>
#include <LittleFS.h>

#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI(); // Initialize the display

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  // Wait for the connection
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  // Once connected, print the IP address
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  tft.init();
  tft.setRotation(3); // Adjust rotation (0-3) to match your display orientation

  if (!LittleFS.begin())
  {
    Serial.println("An Error has occurred while mounting LittleFS :(");
    return;
  }
  Serial.println("LittleFS is available!");
  if (LittleFS.exists("/Aleo-Regular-PL.vlw"))
  {
    Serial.println("Font Aleo-Regular-PL is exist od disk!");
  }

  String fileName = "Aleo-Regular-PL";
  tft.loadFont(fileName, LittleFS);
  tft.showFont(2000);

  tft.fillScreen(TFT_RED);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Hello, ESP32", 10, 10, 4); // Display "Hello, ESP32!" at x=10, y=10
  tft.drawString("Zażółć gęślą jaźń Zażółć gęślą jaźń", 10, 50, 4);
  tft.drawString(WiFi.localIP().toString().c_str(), 10, 75, 4);
  tft.drawString("§1234567890-=qwertyuiop[]asdfghjkl;'`zxcvbnm,./ąćęłńóśźżĄĆĘŁŃÓŚŹŻ£!@#$%^&*()_+QWERTYUIOP{}ASDFGHJKL:|~ZXCVBNM<>?1234567890", 10, 100, 6);

  tft.setTextSize(1);

  String longText = R"(Litwo! Ojczyzno moja! Ty jesteś jak zdrowie;
Ile cię trzeba cenić, ten tylko się dowie;
Kto cię stracił. Dziś piękność twą w całej ozdobie
Widzę i opisuję, bo tęsknię po tobie.)";

  int x = 10;
  int y = 10;
  int lineHeight = 20;
  int screenWidth = tft.width();

  tft.drawString(longText, 10, 150, 6);
}

void loop()
{
}