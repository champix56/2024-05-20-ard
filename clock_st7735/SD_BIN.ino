#ifdef SD_BIN
#include "structure.h"
#include <SPI.h>
#include <SD.h>

#define SD_CSPIN 4
#define SD_DATA_FILENAME "datas.bin"

bool setupSD() {
  SD.begin(SD_CSPIN);
}
void writeDatas(tmSensors_t t) {
  File monFichier = SD.open(SD_DATA_FILENAME, FILE_WRITE);
  union u_tmSensor ut;
  ut.tsensor = t;
  // for(int i=0;i< sizeof(struct tmSensors_t);i++){
  //    monFichier.write(ut.arrBytes[i]);
  // }
  monFichier.write((char *)ut.arrBytes, sizeof(struct tmSensors_t));
  monFichier.close();
}
void getSDLastDatas(tmSensors_t *t) {
  File monFichier = SD.open(SD_DATA_FILENAME, FILE_READ);
  union u_tmSensor ut;
  for (unsigned int i = 0; i < sizeof(struct tmSensors_t); i++) {
    ut.arrBytes[i] = monFichier.read();
  }
  *t = ut.tsensor;

  monFichier.close()
}
#endif