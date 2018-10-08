#include <app.h>


using namespace aqaGps;
using namespace aqaPlantower;
using namespace aqaDht;
using namespace aqaWifi;

//gps configuration
SoftwareSerial gpsSerial(GPS_RX,GPS_TX);
AqaGps gpsSensor(gpsSerial);
// plantower pm configuration
SoftwareSerial plantower_serial(P_TOWER_RX, P_TOWER_TX);
AqaPlantower plantowerSensor(plantower_serial);
// DHT
AqaDht dhtSensor;
// Wifi
AqaWifi the_wifi(5000);

void setup() {

  Serial.begin(115200);
  

  gpsSerial.begin(GPS_BAUDS);
  plantower_serial.begin(P_BAUDS);
  dhtSensor.setup();

  the_wifi.init_connections();

}


void loop() {

  gpsSensor.handleGpsData();
  plantowerSensor.handlePlantowerData();
  dhtSensor.handleDhtData();
  yield();
 the_wifi.check_connections();

 if( gpsSensor.sensorOk() && plantowerSensor.sensorOk() && dhtSensor.sensorOk() && the_wifi.internetOk() ) 
 {
 //ready to send to the server

    DMSG_STR("ready to SAVE/UPLOAD");

 }else {
 DMSG("gps:  ");
 DMSG(gpsSensor.sensorOk());
 DMSG("internet:  ");
 DMSG(the_wifi.internetOk());
 DMSG("plantower:  ");
 DMSG(plantowerSensor.sensorOk());
 DMSG("dht :  ");
 DMSG_STR(dhtSensor.sensorOk());
 }
 yield();
}
