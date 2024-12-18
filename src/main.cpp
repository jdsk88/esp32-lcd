// Button widget demo, requires SPI display with touch screen

// Requires widget library here:
// https://github.com/Bodmer/TFT_eWidget

#include <TFT_eSPI.h>    // Hardware-specific library
#include <TFT_eWidget.h> // Widget library
#include <FS.h>
#include <bb_captouch.h>
#include "main-variables.h"
#include "Free_Fonts.h"
#include "Buttons.h"

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library
BBCapTouch bbct;
int i;
TOUCHINFO ti;

#define REPEAT_CAL false

ButtonWidget btnU1 = ButtonWidget(&tft);
ButtonWidget btnD1 = ButtonWidget(&tft);
ButtonWidget btnU2 = ButtonWidget(&tft);
ButtonWidget btnD2 = ButtonWidget(&tft);
ButtonWidget btnU3 = ButtonWidget(&tft);
ButtonWidget btnD3 = ButtonWidget(&tft);

// Create an array of button instances to use in for() loops
// This is more useful where large numbers of buttons are employed
ButtonWidget *btn[] = {&btnU1, &btnD1, &btnU2, &btnD2, &btnU3, &btnD3};
;
uint8_t buttonCount = sizeof(btn) / sizeof(btn[0]);

void setup()
{
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF17); // FSI9

  // LED's
  pinMode(LED_R, OUTPUT);
  digitalWrite(LED_R, HIGH);
  pinMode(LED_G, OUTPUT);
  digitalWrite(LED_G, HIGH);
  pinMode(LED_B, OUTPUT);
  digitalWrite(LED_B, HIGH);

  // Calibrate the touch screen and retrieve the scaling factors
  // touch_calibrate();
  bbct.init(33, 32, 25, 21);
  int iTYPE = bbct.sensorType();
  bbct.setOrientation((tft.rotation * 90), 240, 320); // tft.rotation*90  ESP z prawej    (tft.rotation)
  // lebelLen = labelMid.length();
  initButtons();
  // Serial.println((int) lebelLen);
}

void loop()
{
  static uint32_t scanTime = millis();
  // uint16_t t_x = 9999, t_y = 9999; // To store the touch coordinates

  // Scan keys every 50ms at most
  if (millis() - scanTime >= SCAN_TIME)
  { // było 50ms
    // Pressed will be set true if there is a valid touch on the screen
    //    bool pressed = tft.getTouch(&t_x, &t_y);
    //    bool pressed = bbct.getSamples(&ti);
    scanTime = millis();
    for (uint8_t b = 0; b < buttonCount; b++)
    {
      //  if (pressed) {
      if (bbct.getSamples(&ti))
      {
        for (int i = 0; i < ti.count; i++)
        {

          if (btn[b]->contains((int)ti.x[i], (int)ti.y[i]))
          {
            btn[b]->press(true);
            btn[b]->pressAction();

            tft.setCursor(35, 12);
            tft.setTextColor(TFT_WHITE);
            tft.setTextSize(1);

            tft.fillRect(35, 0, 300, 13, TFT_BLACK);
            //          Serial.println((int) ti.x[i]);
            //          Serial.println((int) ti.y[i]);
            tft.print("X: ");
            tft.print(ti.x[i]);
            tft.print("  Y: ");
            tft.print(ti.y[i]);
          }
        }
      }
      else
      {
        btn[b]->press(false);
        btn[b]->releaseAction();
      }
    }
  }
}
/*
void touch_calibrate()
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  // check file system exists
  if (!LittleFS.begin()) {
    Serial.println("formatting file system");
    LittleFS.format();
    LittleFS.begin();
  }

  // check if calibration file exists and size is correct
  if (LittleFS.exists(CALIBRATION_FILE)) {
    if (REPEAT_CAL)
    {
      // Delete if we want to re-calibrate
      LittleFS.remove(CALIBRATION_FILE);
    }
    else
    {
      File f = LittleFS.open(CALIBRATION_FILE, "r");
      if (f) {
        if (f.readBytes((char *)calData, 14) == 14)
          calDataOK = 1;
        f.close();
      }
    }
  }

  if (calDataOK && !REPEAT_CAL) {
    // calibration data valid
    tft.setTouch(calData);
  } else {
    // data not valid so recalibrate
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(20, 0);
    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.println("Touch corners as indicated");

    tft.setTextFont(1);
    tft.println();

    if (REPEAT_CAL) {
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.println("Set REPEAT_CAL to false to stop this running again!");
    }

    tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.println("Calibration complete!");

    // store data
    File f = LittleFS.open(CALIBRATION_FILE, "w");
    if (f) {
      f.write((const unsigned char *)calData, 14);
      f.close();
    }
  }
}
*/