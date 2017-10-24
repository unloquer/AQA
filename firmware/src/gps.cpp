#include "app.h"

TinyGPSPlus gpsParser;
SoftwareSerial gpsSerial(13, 7);

void setupGPS() {
  static const int gpsRXPin = 13, gpsTXPin = 7;
  static const uint32_t bauds = 9600;
  gpsSerial.begin(bauds);
}

void readGPS(unsigned long ms) {
  unsigned long start = millis();

  wdt_disable();

  do {
    while(gpsSerial.available()) {
      gpsParser.encode(gpsSerial.read());
    }
  } while (millis() - start < ms);

  wdt_enable(1000);
}

GPSData parseGPSData() {
  GPSData data;

  if (gpsParser.location.isValid()) {
    data.ready = 1;

    data.lat = gpsParser.location.lat();
    data.lng = gpsParser.location.lng();

    Serial.print("lat: ");
    Serial.println(data.lat);
    Serial.print("lng: ");
    Serial.println(data.lng);
  } else {
    data.ready = 0;
    Serial.println("GPS is not ready!");
    // return data;
  }

  if (gpsParser.date.isValid()) {
    data.date += gpsParser.date.month() + STR_SLASH + gpsParser.date.day() +
      STR_SLASH + gpsParser.date.year();
    Serial.println("date: "+data.date);
  }

  if (gpsParser.time.isValid()) {
    String timeStr = "";
    if (gpsParser.time.hour() < 10) timeStr += STR_ZERO;
    timeStr += gpsParser.time.hour();
    timeStr += STR_COLON;

    if (gpsParser.time.minute() < 10) timeStr += STR_ZERO;
    timeStr += gpsParser.time.minute();
    timeStr += STR_COLON;

    if (gpsParser.time.second() < 10) timeStr += STR_ZERO;
    timeStr += gpsParser.time.second();
    timeStr += STR_DOT;

    if (gpsParser.time.centisecond() < 10) timeStr += STR_ZERO;
    timeStr += gpsParser.time.centisecond();

    data.time = timeStr;
    Serial.print("time: ");
    Serial.println(data.time);
  }

  if(gpsParser.altitude.isValid()) {
    data.altitude = gpsParser.altitude.meters();
    Serial.print("altitude: ");
    Serial.println(data.altitude);
  }

  if(gpsParser.course.isValid()) {
    data.course = gpsParser.course.deg();
    Serial.print("course: ");
    Serial.println(data.course);
  }

  if(gpsParser.speed.isValid()) {
    data.speed = gpsParser.speed.kmph();
    Serial.print("speed: ");
    Serial.println(data.speed);
  }

  return data;
}

GPSData getGPSData() {
  readGPS(800);
  GPSData data = parseGPSData();
  return data;
}
