#include <app.h>


using namespace aqaGps;
using namespace aqaPlantower;
using namespace aqaDht;

//gps configuration
SoftwareSerial gpsSerial(GPS_RX,GPS_TX);
AqaGps gpsSensor(gpsSerial);
// plantower pm configuration
SoftwareSerial plantower_serial(P_TOWER_RX, P_TOWER_TX);
AqaPlantower plantowerSensor(plantower_serial);
// DHT
AqaDht dhtSensor;

void setup() {

  Serial.begin(115200);
  
  gpsSerial.begin(GPS_BAUDS);
  plantower_serial.begin(P_BAUDS);
  dhtSensor.setup();

}


void loop() {

  gpsSensor.handleGpsData();
  plantowerSensor.handlePlantowerData();
  dhtSensor.handleDhtData();
  yield();

}
