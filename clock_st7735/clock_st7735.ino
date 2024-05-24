#include <SPI.h>
#include <TimeLib.h>


void setup(void) {
  Serial.begin(9600);
  setupTemprature();
  setupScreen();
  setupPressure();
}

void loop() {
  // float temp=getTemperature();
  float temp=24.45F;
 drawTemp(temp);
 tmElements_t* t=getTime();
 if(t!=NULL)drawTime(*t);
  drawPressure(getPressure());
  delay(100);
}
