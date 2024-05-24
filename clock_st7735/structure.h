#ifndef _STRUCT_H_
#define _STRUCT_H_

struct tmTime_t {
  uint8_t annee, mois, jour;
  uint8_t heure, minute, seconde;
};
struct tmSensors_t {
  struct tmTime_t datetime;
  float temperature;
  uint16_t pression;
  float humidite;
};

union u_tmSensor {
  tmSensors_t tsensor;
  uint8_t arrBytes[sizeof(struct tmSensors_t)];
};
#endif