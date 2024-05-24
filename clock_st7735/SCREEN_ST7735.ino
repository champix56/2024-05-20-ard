/**************
lib pour le tft
***************/
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>
#include "SCREEN_POSITIONS.h"
#include "structure.h"
// For the breakout board, you can use any 2 or 3 pins.
// These pins will also work for the 1.8" TFT shield.
#define TFT_CS 10
#define TFT_RST 9  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setupScreen() {
  tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab
  Serial.println(F("Initialized"));
  // tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  drawStatic();
}
void drawStatic() {

  tft.setTextSize(1);
  tft.setCursor(10, 15);
  tft.print("Temperature");
  tft.setCursor(10, PRESS_POS_Y - 12);
  tft.print("Pression");
  tft.setCursor(PRESS_WIDTH + PRESS_POS_X, PRESS_POS_Y);
  tft.print("KPa");
  tft.setCursor(10, RH_POS_Y - 12);
  tft.print("Humidité");
  tft.setCursor(RH_WIDTH + RH_POS_X, RH_POS_Y);

  tft.print("%");
  tft.fillRect(0, 0, 128, 9, ST77XX_RED);
}
void drawTime(struct tmTime_t tm) {
  char buf[11] = "";
  sprintf(buf, "%d:%d:%02d", tm.heure, tm.minute, tm.seconde);
  tft.setTextColor(0xFFFF);
  tft.setTextSize(1);
  tft.setCursor(TIME_POS_X, TIME_POS_Y);
  tft.fillRect(TIME_POS_X, TIME_POS_Y, TIME_WIDTH, 8, ST77XX_RED);
  tft.print(buf);
  sprintf(buf, "%d/%d/%4d", tm.jour, tm.mois, tm.annee);
  tft.setCursor(DATE_POS_X, DATE_POS_Y);
  tft.fillRect(DATE_POS_X, DATE_POS_Y, DATE_WIDTH, 8, ST77XX_RED);
  tft.print(buf);
}
void drawTemp(float temp) {
  tft.setCursor(30, 27);
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);

  // tft.fillRect(30,27 uint16_t color)
  tft.print(temp);
}
void drawPressure(uint16_t press) {
  tft.setCursor(PRESS_POS_X, PRESS_POS_Y);
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.fillRect(PRESS_POS_X, PRESS_POS_Y, PRESS_WIDTH, 15, ST7735_BLACK);
  tft.print(press);
}
void drawHumidity(float humidite) {
  tft.setCursor(RH_POS_X, RH_POS_Y);
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.fillRect(RH_POS_X, RH_POS_Y, RH_WIDTH, 15, ST7735_BLACK);
  tft.print(humidite);
}