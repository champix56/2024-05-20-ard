/**************
lib pour ds18b20
***************/
#define TEMP_ERROR -1000.0F
#include <OneWire.h>
#include <DallasTemperature.h>
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
/**
* fonction d'inititalisation des sensors OneWire DS18B20
*/
void setupTemprature() {
  sensors.begin();
}
/**
* fonction pour recuperer la temperature depuis un DS18B20
* @returns {float} valeur de temperature en degres °C
*/
float getTemperature() {
  sensors.requestTemperatures();
  float tmp = sensors.getTempCByIndex(0);
  if (tmp != DEVICE_DISCONNECTED_C) {
    return tmp;
  } else {
    return TEMP_ERROR;
  }
}