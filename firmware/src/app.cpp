/*#include "app.h"

GPSSensor *gps;

void setup() {
  Serial.begin(115200);
  delay(1000);

  static const int gpsRXPin = 13, gpsTXPin = 7;
  static const uint32_t GPSBaud = 9600;

  // SoftwareSerial gpsSerial(gpsRXPin, gpshTXPin);
  // GPSSensor gpsSensor(&gpsSerial);

  // GPSSensor gpsSensor(gpsRXPin, gpsRXPin);

  GPSSensor gpsSensor = GPSSensor();

  gpsSensor.begin();
  gps = &gpsSensor;
}

void loop() {
  // Serial.print(".");
  wdt_disable(); // Disable watchdog
  gps->read();
  // ;
  delay(1000);
  Serial.print("-");
  // Serial.println(gps->data.lat);
  // Serial.println(gps->data.lng);
}
*/
