
#include "DHT.h"

#define DHTPIN 4       // Uncomment whatever type you're using!
#define DHTTYPE DHT11  // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setupDHT() {
  dht.begin();
}
float getHumidity() {
  return dht.readHumidity();
}