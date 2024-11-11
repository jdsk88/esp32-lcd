#define AA_FONT_SMALL "coolvetica-regular"

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
}

void loop()
{
}
