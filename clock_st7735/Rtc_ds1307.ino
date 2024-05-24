#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
tmElements_t tm;
void setupRtc() {
}
tmElements_t* getTime() {
  if (RTC.read(tm)) {
    return &tm;
  } else {
    return NULL;
  }
}