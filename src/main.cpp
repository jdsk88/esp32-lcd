#define AA_FONT_SMALL "coolvetica-regular"

#include <iostream>

#include <FS.h>
#include <LittleFS.h>

#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI(); // Initialize the display

void setup()
{
  Serial.begin(115200);
  tft.init();
  tft.setRotation(3); // Adjust rotation (0-3) to match your display orientation

  std::string text = R"(Litwo! Ojczyzno moja! Ty jesteś jak zdrowie;
Ile cię trzeba cenić, ten tylko się dowie;
Kto cię stracił. Dziś piękność twą w całej ozdobie
Widzę i opisuję, bo tęsknię po tobie.)";

  std::cout << text << std::endl;

  if (!LittleFS.begin())
  {
    Serial.println("An Error has occurred while mounting LittleFS :(");
    return;
  }
  Serial.println("LittleFS is available!");
  if (LittleFS.exists("/coolvetica-regular.vlw"))
  {
    Serial.println("Font coolvetica-regular is exist od disk!");
  }

  String fileName = "coolvetica-regular";
  tft.loadFont(fileName, LittleFS);
  tft.showFont(2000);

  tft.fillScreen(TFT_RED);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Hello, ESP32", 10, 10, 4); // Display "Hello, ESP32!" at x=10, y=10
  tft.drawString("Zażółć gęślą jaźń Zażółć gęślą jaźń", 10, 50, 4);
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