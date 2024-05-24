#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

bool setupPressure(){
  return bmp.begin();

}

unsigned int getPressure(){
  return bmp.readPressure()/1000L;
}