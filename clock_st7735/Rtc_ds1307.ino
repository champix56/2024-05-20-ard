#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include "structure.h"
tmElements_t tm;
void setupRtc() {
}
bool getTime(struct tmTime_t *time) {
  if (RTC.read(tm)) {
    time->annee = y2kYearToTm(tm.Year);
    time->mois = tm.Month;
    time->jour = tm.Day;
    time->heure = tm.Hour;
    time->minute = tm.Minute;
    time->seconde = tm.Second;
    return true;
    //return &tm;
  } else {
    time = NULL;
    return false;
  }
}
void debugTime() {
  Serial.print("Ok, Time = ");
  print2digits(tm.Hour);
  Serial.write(':');
  print2digits(tm.Minute);
  Serial.write(':');
  print2digits(tm.Second);
  Serial.print(", Date (D/M/Y) = ");
  Serial.print(tm.Day);
  Serial.write('/');
  Serial.print(tm.Month);
  Serial.write('/');
  Serial.print(tmYearToCalendar(tm.Year));
  Serial.println();
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}