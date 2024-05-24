#include <SPI.h>
#include <TimeLib.h>
#include "structure.h"

struct tmSensors_t sensorsValues;

void setup(void) {
  Serial.begin(9600);
#ifdef SD
  setupSD();
#endif
  setupTemprature();
  setupScreen();
  setupPressure();
  setupDHT();
}

void loop() {
  sensorsValues.temperature = 24.45F;
  drawTemp(sensorsValues.temperature);
  struct tmTime_t *dt = &sensorsValues.datetime;
  if (getTime(dt)) { drawTime(sensorsValues.datetime); }

  drawPressure(sensorsValues.pression);
  sensorsValues.humidite = getHumidity();
  drawHumidity(sensorsValues.humidite);
#ifdef SD
  writeDatas(sensorsValues);
#endif
  delay(100);
}
