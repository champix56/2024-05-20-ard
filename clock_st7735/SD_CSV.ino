#include "config.h"
#ifdef SD_CSV
#include <SPI.h>
#include <SD.h>

#define SD_CSPIN 4
#define SD_DATA_FILENAME "datas.csv"
#define FILE_HEADER "date;time;temperature;pressure;humidity"
bool setupSD() {
  return SD.begin(SD_CSPIN);
}
void writeDatas(tmSensors_t t) {
  char buf[13] = "";
  bool alreadyExist = SD.exists(SD_DATA_FILENAME);
  File myFile = SD.open(SD_DATA_FILENAME, FILE_WRITE);
  if (!alreadyExist) myFile.println(FILE_HEADER);
  // date
  sprintf(buf, "20%.2d/%.2d/%.2d;", t.datetime.annee, t.datetime.mois, t.datetime.jour);
  myFile.print(buf);
  sprintf(buf, "%.2d:%.2d:%.2d;", t.datetime.heure, t.datetime.minute, t.datetime.seconde);
  myFile.print(buf);
  myFile.print(t.temperature);
  myFile.print(';');
  myFile.print(t.pression);
  myFile.print(';');
  myFile.println(t.humidite);
  myFile.close();
}
#endif