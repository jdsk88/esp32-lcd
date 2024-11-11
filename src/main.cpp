#include <Arduino.h>
#include <TFT_eSPI.h> // Graphics and font library for ILI9341

TFT_eSPI tft = TFT_eSPI(); // Create TFT instance

void setup()
{
  tft.init();
  tft.setRotation(1); // Set orientation if needed (0-3)
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(0, 0);
  tft.println("Hello, ESP32 with 2.8\" LCD!");
}

void loop()
{
  // Additional drawing code here, e.g., tft.fillRect, tft.drawLine, etc.
}
