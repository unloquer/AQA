#include <app.h>


using namespace aqaGps;

//gpsData my_gps;
SoftwareSerial gpsSerial(GPS_RX,GPS_TX);
AqaGps gpsSensor(gpsSerial);
void setup() {

  Serial.begin(115200);
  
  gpsSerial.begin(GPS_BAUDS);
 /* Serial.println(my_gps.ready);
  String defines = STR_DOT;
  defines+=STR_COMMA;
  defines+=STR_SPACE;
  defines += STR_ZERO;
  defines += STR_SLASH;
  defines += STR_NULL;

  DMSG_STR(defines);*/

}


void loop() {

  gpsSensor.handleGpsData();
  yield();

}
