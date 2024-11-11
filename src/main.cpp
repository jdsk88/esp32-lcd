#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI(); // Initialize the display

void setup()
{
  tft.init();
  tft.setRotation(1); // Adjust rotation (0-3) to match your display orientation
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Hello, ESP32!", 10, 10, 4); // Display "Hello, ESP32!" at x=10, y=10
}

void loop()
{
  // Add animations or other display updates here
}
