/*String  labelLeft_1 = "Salon";
String  labelMid_1 = "Kuchnia";
String  labelRight_1  = "Jadalnia";
String  labelLeft_2 = "";
String  labelMid_2  = "";
String  labelRight_2  = "";
String  labelLeft_3 = "";
String  labelMid_3  = "";
String  labelRight_3  = "";
//uint8_t varLeft_1  = 15;
uint8_t varMid_1 = 20;
uint8_t varRight_1  = 30;
uint8_t varLeft_2  = 25;
uint8_t varMid_2 = 40;
uint8_t varRight_2  = 55;
uint8_t varLeft_3  = 35;
uint8_t varMid_3 = 18;
uint8_t varRight_3  = 99;
//uint8_t varOld = 0; */

#include "Free_Fonts.h"
#include <Arduino.h>
#include <TFT_eSPI.h>    // Hardware-specific library
#include <TFT_eWidget.h> // Widget library

extern TFT_eSPI tft;

extern String label[6];
// extern String label[6] = {"Salon", "Kuchnia", "Jadalnia", "", "", ""};
/*
uint8_t btnState[6] = {0,0,0,0,0,0};

*/
extern uint8_t varOut[6];
extern uint8_t varOld[6];
extern uint8_t LbtnPress[12]; 

// extern uint8_t varOut[6] = {15, 20, 30, 35, 50, 80};
// extern uint8_t varOld[6] = {0, 0, 0, 0, 0, 0};
// extern uint8_t LbtnPress[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // long btn press
#define B1U 0
#define B1D 1
#define B2U 2
#define B2D 3
#define B3U 4
#define B3D 5
#define B4U 6
#define B4D 7
#define B5U 8
#define B5D 9
#define B6U 10
#define B6D 11

extern uint8_t outState[6];
#define OUT_1 0
#define OUT_2 1
#define OUT_3 2
#define OUT_4 3
#define OUT_5 4
#define OUT_6 5

#define DEBUG 1
#define T_STEP 200
#define SCAN_TIME 50

#define BTN_W tft.width() / 4
#define BTN_H BTN_W
#define BTN_COUNT 3 // 3 komplety przycisków UP/DOWN
#if BTN_COUNT == 3
#define BTN_LEFT_POS_X (tft.width() / 4) - 20 // w środku długosci przycisku
#define BTN_MID_POS_X tft.width() / 2
#define BTN_RIGHT_POS_X (tft.width() / 2) + (tft.width() / 4) + 20
#define BTN_POS_Y1 (tft.height() / 4) + 30                      // górny przycisk
#define BTN_POS_Y2 (tft.height() / 2) + (tft.height() / 4) + 10 // dolny przycisk
#define LABEL_LEFT_POS_X BTN_LEFT_POS_X
#define LABEL_MID_POS_X BTN_MID_POS_X
#define LABEL_RIGHT_POS_X BTN_RIGHT_POS_X
#define LABEL_POS_Y BTN_POS_Y2 - (BTN_H / 2) - 4
#define VAR_MID_POS_X BTN_MID_POS_X
#define VAR_POS_Y BTN_POS_Y1 - (BTN_H / 2) - 4
#endif
#define LED_R 4
#define LED_G 16
#define LED_B 17

extern ButtonWidget btnU1;
extern ButtonWidget btnD1;
extern ButtonWidget btnU2;
extern ButtonWidget btnD2;
extern ButtonWidget btnU3;
extern ButtonWidget btnD3;