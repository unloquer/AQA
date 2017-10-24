#include "app.h"

#define DHTPIN 12     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

void setupDHT11() {
  dht.begin();
}

DHT11Data getDHT11Data() {
  DHT11Data data;
  data.temperature = isnan(dht.readTemperature()) ? -1 : dht.readTemperature();
  data.humidity = isnan(dht.readHumidity()) ? -1 : dht.readHumidity();;
  data.ready = 1;
  return data;
}
