#ifndef _STRUCT_H_
#define _STRUCT_H_
struct {
  uint8_t annee,mois,jour;
  float temperature;
  uint16_t pression; 
} tmSensors_t;
typedef tmSensor struct tmSensors_t;
#endif