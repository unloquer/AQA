/* #include <ESP8266WiFi.h> */
/* #include <ESP8266WiFiMulti.h> */
/* #include <ESP8266HTTPClient.h> */
/* #include <ESP8266WebServer.h> */
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncWiFiManager.h>
#include <ESP8266HTTPClient.h>
//#include <SPIFFSEditor.h>
#include <FS.h>
#include <FastLED.h>
#include "DHT.h"
//#include <ESP8266WiFi.h>

const String SENSOR_ID = "volker0001";

const String STR_COMMA = ",";
const String STR_SLASH = "/";
const String STR_DOT = ".";
const String STR_COLON = ":";
const String STR_NULL = "NULL";
const String STR_ZERO = "0";
const String STR_SPACE = " ";

typedef struct {
  String ssid;
  String password;
  int ip[4];
} WifiConfig;

typedef struct {
  int ready = 0;

  String date;
  String time;
  double altitude;
  double course;
  double speed;
  double lat;
  double lng;
} GPSData;

typedef struct {
  String name;
  int data;
  void read() {
    Serial.println("I read!"+data);
  }
} Sensor;

typedef struct {
  int ready = 0;

  float temperature;
  float humidity;
} DHT11Data;

typedef struct {
  int ready = 0;

  int pm1;
  int pm25;
  int pm10;
} PlantowerData;

typedef struct {
  GPSData gps;
  DHT11Data dht11;
  PlantowerData plantower;
} AirData;

void setupWifi();
//void reportWifi();
void setupGPS();
void setupPlantower();
void setupDHT11();
void setupLeds();

GPSData getGPSData();
DHT11Data getDHT11Data();
PlantowerData getPlantowerData();

String csvFrame();
String influxFrame();
void save();
int postCsvFile(String url, String filename);
int postCsv(String url, String csv);
int post2Influx(String url, String load);


void ledParticulateQuality(PlantowerData data);
void ledParticulateQualityStream(PlantowerData data);

/*class GPSSensor {
  private:
  int readTime;

  public:
  GPSSensor();
  GPSData data;
  // SoftwareSerial serial;
  SoftwareSerial *_serial;
  // GPSSensor(SoftwareSerial *ss);
  // GPSSensor(const int rx, const int tx);
  void begin();
  // void _begin();
  void read();
  // void _read();
  };*/
