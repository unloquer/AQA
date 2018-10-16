#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266HTTPClient.h>
#include "WiFiManager.h"
#include <ESP8266WebServer.h>
#include <TinyGPS++.h>
#include <Hash.h>
#include <SoftwareSerial.h>
/* #include <ESPAsyncTCP.h> */
/* #include <ESPAsyncWebServer.h> */
/* #include <ESPAsyncWiFiManager.h> */
/* #include <ESP8266HTTPClient.h> */
//#include <SPIFFSEditor.h>
#include <FS.h>
#include <FastLED.h>
#include "DHT.h"
//impotamos o incluimos las librerias nesarias
#define DEBUG
#define NUEVATARJETA // si no es nueva se comenta esta linea
//definimos el modo de la tarjeta si es nueva o sino
#ifdef DEBUG
#define DMSG(args...)       Serial.print(args)
#define DMSGf(args...)      Serial.printf(args)
#define DMSG_STR(str)       Serial.println(str)
#else
#define DMSG(args...)
#define DMSGf(args...)
#define DMSG_STR(str)
#endif


const String SENSOR_ID = "volker0023"; // change this with your sensor ID
//esta es la ide de tu sensor cambiala

const String STR_COMMA = ",";
const String STR_SLASH = "/";
const String STR_DOT = ".";
const String STR_COLON = ":";
const String STR_NULL = "NULL";
const String STR_ZERO = "0";
const String STR_SPACE = " ";
//declaramos unas varibles  como string o palablas
typedef struct {
  String ssid;
  String password;
  int ip[4];
} WifiConfig;
/*los datos definodos o puetos  en typedef struct  son  los nesarios para
estableser la coneccion a internet para conectarse con las bases de datos
y luego es nombrado  Wificonfig*/
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
/*los datos definodos o puetos  en typedef struct  son  los nesarios para
recojer cada dato proprcionado por el gps
y luego es nombrado  GPSData*/
typedef struct {
  String name;
 int data;
  void read() {
    DMSG_STR("I read!"+data);
  }
} Sensor;
/*los datos definodos o puetos  en typedef struct  son  los nesarios para
recojer los y crear
crear name como una palabra
      data como un numero entero
recojer  la funcion vacia (que no de vuelve datos) read()
y imprimir  I read y un numero que es datos
y luego es nombrado  sensor*/
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
void ledParticulateQualityStreamming(PlantowerData data);
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
