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
//importamos o incluimos las librerias necesarias
// que algunas veces no hay que intstalarlas
#define DEBUG
#define NUEVATARJETA // si no es nueva  o tiene la tarjeta roja con todo incluido se comenta esta linea
//definimos el modo de la tarjeta si es nueva o tiene la tarjeta roja con todo incluido o sino  no se comenta
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
//esta es la id de tu sensor cambiala

const String STR_COMMA = ",";
const String STR_SLASH = "/";
const String STR_DOT = ".";
const String STR_COLON = ":";
const String STR_NULL = "NULL";
const String STR_ZERO = "0";
const String STR_SPACE = " ";
//declaramos unas variables  como string o palablas que son costantes que no cambian
typedef struct {
  String ssid;
  String password;
  int ip[4];
} WifiConfig;
/*los datos definidos o puestos  en typedef struct  son  los nesarios para
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
/*los datos definidos o puestos  en typedef struct  son  los nesarios para
recojer cada dato proporcionado por el gps
y luego es nombrado  GPSData*/
typedef struct {
  String name;
 int data;
  void read() {
    DMSG_STR("I read!"+data);
  }
} Sensor;
/*los datos definidos o puestos  en typedef struct  son  los nesarios para
recojer los y crear
crear name como una palabra
      data como un numero entero
recojer  la funcion vacia (que no de vuelve datos) read()
y imprimir  I read y un numero que es la variable "data"
y luego es nombrado  sensor*/
typedef struct {
  int ready = 0;

  float temperature;
  float humidity;
} DHT11Data;
/*los datos definidos o puestos  en typedef struct  son  los nesesarios para
que el dht (el que mide la temperatura y humedad) recoja datos  y cree la
varible ready que es un numero entero que lee  los varibles  y los valores del dht son un numero
decimal la humedad y la temperatura que son llamados humidity y temperature
 que  es un numero decimal y luego es nombrado  DHTData*/

typedef struct {
  int ready = 0;

  int pm1;
  int pm25;
  int pm10;
} PlantowerData;
/*los datos definidos o puestos  en typedef struct  son  los nesesarios para
que el sensor de particulas (el que mide canbtidad y tamño de particulas)
 recoja datos de  de un el tamaño (particulas por millon)pm1 este es el
 y lo mismo con pm25 que seria el tamaño de particulas 2.5 que es la mas
  peligrosa no sola mente lee esa tembien la pm10
y luego es nombrado  plantowerData*/
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
/*invocamos las funciones vacias que no devuelven nada  pero reciven valores*/
GPSData getGPSData();
DHT11Data getDHT11Data();
PlantowerData getPlantowerData();
/*invocamos las funciones que devuelven un tipo de dato que es
 propio de su clase (porfavor si  me equivoque corrijanme)*/
String csvFrame();
String influxFrame();
/*invocamos las funciones que devuelven un tipo de dato que son
 palabras como "shjdflkhnlf" y "xnlddhndhln"
o letras  juntas  si a eso sele pude llamar pabras*/
void save();
/*invocamos la funcion vacia que no devuelven nada */
int postCsvFile(String url, String filename);
int postCsv(String url, String csv);
int post2Influx(String url, String load);
/*invocamos la funcion de tipo entero que retorna   y recive unos
parametros adicionales que  son almacenados dentro de la funcion */

void ledParticulateQuality(PlantowerData data);
void ledParticulateQualityStreamming(PlantowerData data);
void ledParticulateQualityStream(PlantowerData data);
/*invocamos la funcion vacia que no devuelven nada  que recive unos
parametros adicionales que  son almacenados dentro de la funcion */


/*diferencia entre void y int (si me equivoco corijanme)
void no se pone return y no retorna nada
int retorna las varibles que tu le pongas return y puede estar limitado
a una retornar una varible
 http://www.forosdelweb.com/f96/diferencias-entre-void-e-int-582370/*/
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
