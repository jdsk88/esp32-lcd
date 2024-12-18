#include <cstdint>
#include "Buttons.h"
#include "main-variables.h"
#include "buttons-variables.h"
#include <TFT_eSPI.h>
#include <TFT_eWidget.h>

extern TFT_eSPI tft;
extern ButtonWidget btnU1;
extern ButtonWidget btnD1;
extern ButtonWidget btnU2;
extern ButtonWidget btnD2;
extern ButtonWidget btnU3;
extern ButtonWidget btnD3;

void grUp(uint16_t pos_x, uint16_t pos_y, uint32_t color)
{
  pos_y = pos_y - (BTN_H / 8); // pos_x = linia srodkowa przycisku np"BTN_LEFT_POS_X"    pos_y = linia pozioma przycisku np"BTN_POS_Y1"
  for (int z = 0; z <= 30; z = z + 10)
  {
    for (int i = 0; i <= 3; ++i)
    {
      tft.drawLine(pos_x - (BTN_W / 4), pos_y + i + z, pos_x, pos_y - (BTN_H / 6) + i + z, color);
      tft.drawLine(pos_x, pos_y - (BTN_H / 6) + i + z, pos_x + (BTN_W / 4), pos_y + i + z, color);
    }
  }
}

void rtUp(uint16_t pos_x, uint16_t pos_y, uint32_t color)
{
  for (int z = 0; z <= (BTN_H / 16) * 3; z = z + (BTN_H / 16))
  {
    tft.fillRect(pos_x - (BTN_W / 4), pos_y + (BTN_H / 4) - z - z, BTN_W / 2, (BTN_W / 10) + z, color);
  }
}
// Zestaw 1
void btnU1_pressAction(void)
{
  if (btnU1.justPressed())
  {
    btnU1.setPressTime(millis());
    varOld[OUT_1] = varOut[OUT_1];
    btnU1.drawSmoothButton(true);
    grUp(BTN_LEFT_POS_X, BTN_POS_Y1, TFT_BLACK);
  }
  if (btnU1.isPressed())
  {
    if (millis() >= btnU1.getPressTime() + (T_STEP))
    { // dla czasu skanowanie 50ms powinno być *2
      //        if (millis() >= 100 )
      if (varOut[OUT_1] >= 100)
      {
        varOut[OUT_1] = 100;
      }
      else
      {
        ++varOut[OUT_1];
        outState[OUT_1] = true;
        btnU1.setPressTime(millis());
        tft.fillRect(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y - 12, BTN_W, 14, TFT_BLACK);
        tft.setCursor(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y);
        if (outState[OUT_1])
        {
          tft.print("ON  ");
        }
        else
          tft.print("OFF ");
        if (outState[OUT_1])
          tft.print((int)varOut[OUT_1]);
        if (DEBUG)
          Serial.print("UP button just pressed > 200ms - outState: ");
        if (DEBUG)
          Serial.println((int)outState[OUT_1]);
        if (DEBUG)
          Serial.print("Press time = : ");
        if (DEBUG)
          Serial.println((int)millis() - btnU1.getPressTime());
        if (DEBUG)
          Serial.println((int)varOut[OUT_1]);
        digitalWrite(LED_B, !outState[OUT_1]);
      }
    }
  }
}

void btnU1_releaseAction(void)
{
  if (btnU1.justReleased())
  {
    btnU1.drawSmoothButton(false);
    grUp(BTN_LEFT_POS_X, BTN_POS_Y1, TFT_DARKGREY);
    if (millis() < btnU1.getPressTime() + T_STEP)
    { // dla czasu skanowanie 50ms powinno być T_STEP + 75
      if (varOld[OUT_1] == varOut[OUT_1])
      {
        if (!outState[OUT_1])
        {
          outState[OUT_1] = true;
        }
        else
          outState[OUT_1] = false;
      }
      if (varOut[OUT_1] < 1)
        outState[OUT_1] = false;
      tft.fillRect(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y - 12, BTN_W, 14, TFT_BLACK);
      tft.setCursor(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y);
      if (outState[OUT_1])
      {
        tft.print("ON  ");
      }
      else
        tft.print("OFF ");
      if (outState[OUT_1])
        tft.print((int)varOut[OUT_1]);
      digitalWrite(LED_B, !outState[OUT_1]);
      if (DEBUG)
        Serial.print("UP button just released < 200ms - outState: ");
      if (DEBUG)
        Serial.println((int)outState[OUT_1]);
      if (DEBUG)
        Serial.print("Press time = : ");
      if (DEBUG)
        Serial.println((int)millis() - btnU1.getPressTime());
    }
    if (DEBUG)
      Serial.print("UP button just released - outState: ");
    if (DEBUG)
      Serial.println((int)outState[OUT_1]);
    if (DEBUG)
      Serial.print("Press time = : ");
    if (DEBUG)
      Serial.println((int)millis() - btnU1.getPressTime());
    if (DEBUG)
      Serial.print((int)varOld[OUT_1]);
    if (DEBUG)
      Serial.print("    ");
    if (DEBUG)
      Serial.println((int)varOut[OUT_1]);
  }
}

void btnD1_pressAction(void)
{
  if (btnD1.justPressed())
  {
    btnD1.setPressTime(millis());
    varOld[OUT_1] = varOut[OUT_1];
  }
  if (btnD1.isPressed())
  {
    if (millis() >= btnD1.getPressTime() + (T_STEP))
    { // dla czasu skanowanie 50ms powinno być * 2
      if (varOut[OUT_1] == 0)
      {
        varOut[OUT_1] = 0;
      }
      else
      {
        --varOut[OUT_1];
        if (varOut[OUT_1] > 0)
        {
          outState[OUT_1] = true;
        }
        else
          outState[OUT_1] = false;
        btnD1.setPressTime(millis());
        tft.fillRect(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y - 12, BTN_W, 14, TFT_BLACK);
        tft.setCursor(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y);
        if (outState[OUT_1])
        {
          tft.print("ON  ");
        }
        else
          tft.print("OFF ");
        if (outState[OUT_1])
          tft.print((int)varOut[OUT_1]);
        if (DEBUG)
          Serial.print("DOWN button just pressed > 200ms - outState: ");
        if (DEBUG)
          Serial.println((int)outState[OUT_1]);
        if (DEBUG)
          Serial.print("Press time = : ");
        if (DEBUG)
          Serial.println((int)millis() - btnD1.getPressTime());
        if (DEBUG)
          Serial.println((int)varOut[OUT_1]);
        if (varOut[OUT_1] == 0)
          outState[OUT_1] = false;
        digitalWrite(LED_B, !outState[OUT_1]);
      }
    }
  }
}

void btnD1_releaseAction(void)
{
  if (btnD1.justReleased())
  {
    if (millis() < btnD1.getPressTime() + T_STEP)
    { // dla czasu skanowanie 50ms powinno być T_STEP + 75
      if (varOld[OUT_1] == varOut[OUT_1])
      {
        if (!outState[OUT_1])
        {
          outState[OUT_1] = true;
        }
        else
          outState[OUT_1] = false;
        if (varOut[OUT_1] < 1)
          outState[OUT_1] = false;
      }
      tft.fillRect(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y - 12, BTN_W, 14, TFT_BLACK);
      tft.setCursor(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y);
      if (outState[OUT_1])
      {
        tft.print("ON  ");
      }
      else
        tft.print("OFF ");
      if (outState[OUT_1])
        tft.print((int)varOut[OUT_1]);
      digitalWrite(LED_B, !outState[OUT_1]);
      if (DEBUG)
        Serial.print("DOWN button just released < 200ms - outState: ");
      if (DEBUG)
        Serial.println((int)outState[OUT_1]);
      if (DEBUG)
        Serial.print("Press time = : ");
      if (DEBUG)
        Serial.println((int)millis() - btnD1.getPressTime());
    }
    if (DEBUG)
      Serial.print("DOWN button just released - outState: ");
    if (DEBUG)
      Serial.println((int)outState[OUT_1]);
    if (DEBUG)
      Serial.print("Press time = : ");
    if (DEBUG)
      Serial.println((int)millis() - btnD1.getPressTime());
  }
}
//  Zestaw 2
void btnU2_pressAction(void)
{
  // if(DEBUG) Serial.println(btnU2.getState());
  if (btnU2.justPressed())
  {
    if (btnU2.getState())
    {
      btnU2.setPressTime(millis());
      Serial.print("U2 naciśnięty :  ");
      Serial.print(btnU2.getState());
      Serial.print("   ");
      Serial.println(millis());
    }
  }
  digitalWrite(LED_G, LOW);
}

void btnU2_releaseAction(void)
{
  // Not action
}
void btnD2_pressAction(void)
{
  if (btnD2.justPressed())
    digitalWrite(LED_G, HIGH);
}
void btnD2_releaseAction(void)
{
  // Not action
}
//   Zestaw 3
void btnU3_pressAction(void)
{
  if (btnU3.justPressed())
    digitalWrite(LED_R, LOW);
}
void btnU3_releaseAction(void)
{
  // Not action
}
void btnD3_pressAction(void)
{
  if (btnD3.justPressed())
    digitalWrite(LED_R, HIGH);
}
void btnD3_releaseAction(void)
{
  // Not action
}

void initButtons()
{

  btnU1.initButton(BTN_LEFT_POS_X, BTN_POS_Y1, BTN_W, BTN_H, TFT_WHITE, TFT_BLACK, TFT_WHITE, "", 1); // x, y, w, h, outline, fill, textcolor, label, textsize
  btnU1.setPressAction(btnU1_pressAction);
  btnU1.setReleaseAction(btnU1_releaseAction);
  btnU1.drawSmoothButton(false, 1, TFT_BLACK); // 3 is outline width, TFT_BLACK is the surrounding background colour for anti-aliasing
  grUp(BTN_LEFT_POS_X, BTN_POS_Y1, TFT_DARKGREY);
  tft.setCursor(LABEL_LEFT_POS_X - (label[OUT_1].length() * 5), LABEL_POS_Y); // 8 dla czcionki 12x8 4 przesunięcie o połowę tekstu - wyśrodkowanie
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(1);
  tft.print(String(label[OUT_1]));
  // wyswietlanie aktualnej wartości
  tft.fillRect(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y - 12, BTN_W, 14, TFT_BLACK);
  tft.setCursor(LABEL_LEFT_POS_X - (BTN_W / 2), VAR_POS_Y);
  tft.print(outState[OUT_1] ? "ON  " : "OFF ");
  if (outState[OUT_1])
    tft.print((int)varOut[OUT_1]);

  btnD1.initButton(BTN_LEFT_POS_X, BTN_POS_Y2, BTN_W, BTN_H, TFT_WHITE, TFT_BLACK, TFT_WHITE, "DOWN", 1);
  btnD1.setPressAction(btnD1_pressAction);
  btnD1.setReleaseAction(btnD1_releaseAction);
  btnD1.drawSmoothButton(false, 1, TFT_BLACK); // 3 is outline width, TFT_BLACK is the surrounding background colour for anti-aliasing

  // Zestaw 2
  btnU2.initButton(BTN_MID_POS_X, BTN_POS_Y1, BTN_W, BTN_H, TFT_WHITE, TFT_BLACK, TFT_WHITE, "", 1);
  btnU2.setPressAction(btnU2_pressAction);
  btnU2.setReleaseAction(btnU2_releaseAction);
  btnU2.drawSmoothButton(false, 1, TFT_BLACK); // 3 is outline width, TFT_BLACK is the surrounding background colour for anti-aliasing
  rtUp(BTN_MID_POS_X, BTN_POS_Y1, TFT_DARKGREY);

  btnD2.initButton(BTN_MID_POS_X, BTN_POS_Y2, BTN_W, BTN_H, TFT_WHITE, TFT_BLACK, TFT_WHITE, "DOWN", 1);
  btnD2.setPressAction(btnD2_pressAction);
  btnD2.setReleaseAction(btnD2_releaseAction);
  btnD2.drawSmoothButton(false, 1, TFT_BLACK); // 3 is outline width, TFT_BLACK is the surrounding background colour for anti-aliasing

  // zestaw 3
  btnU3.initButton(BTN_RIGHT_POS_X, BTN_POS_Y1, BTN_W, BTN_H, TFT_WHITE, TFT_BLACK, TFT_WHITE, "UP", 1);
  btnU3.setPressAction(btnU3_pressAction);
  btnU3.setReleaseAction(btnU3_releaseAction);
  btnU3.drawSmoothButton(false, 1, TFT_BLACK); // 3 is outline width, TFT_BLACK is the surrounding background colour for anti-aliasing

  btnD3.initButton(BTN_RIGHT_POS_X, BTN_POS_Y2, BTN_W, BTN_H, TFT_WHITE, TFT_BLACK, TFT_WHITE, "DOWN", 1);
  btnD3.setPressAction(btnD3_pressAction);
  btnD3.setReleaseAction(btnD3_releaseAction);
  btnD3.drawSmoothButton(false, 1, TFT_BLACK); // 3 is outline width, TFT_BLACK is the surrounding background colour for anti-aliasing
}
