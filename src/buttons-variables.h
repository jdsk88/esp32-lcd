#include <Arduino.h>

String label[6] = {"Salon", "Kuchnia", "Jadalnia", "", "", ""};
uint8_t varOut[6] = {15, 20, 30, 35, 50, 80};
uint8_t varOld[6] = {0, 0, 0, 0, 0, 0};
uint8_t LbtnPress[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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

uint8_t outState[6] = {0, 0, 0, 0, 0, 0};
#define OUT_1 0
#define OUT_2 1
#define OUT_3 2
#define OUT_4 3
#define OUT_5 4
#define OUT_6 5

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

