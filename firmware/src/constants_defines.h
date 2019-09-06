#ifndef _CONSTANTS_DEFINES_H
#define _CONSTANTS_DEFINES_H
#include <Arduino.h>

#define DEBUG
#define NUEVATARJETA
//#define MOBILE
#define FIXED_WIFI

#ifndef MOBILE
#define FIXED_LAT "6.200022"
#define FIXED_LON "-75.505357"
#endif

const String SENSOR_ID = "aqa_id"; // change with your id
// WiFi parameters

#ifdef FIXED_WIFI
const String SSID = "WIFI_SSID";
const String PASSWORD = "WIFI_PASSWORD";

//------ Http uint16_t HTTP_TIMEOUT = 1000 * 60;

//
//----DOUBLE RESET DETECTOR
// Number of seconds after reset during which a
// subseqent reset will be considered a double reset.
#define DRD_TIMEOUT 100
// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0

//---pin and softwareSerial stuff definition
//---- for the gps
#define GPS_RX 13
#define GPS_TX 7
#define GPS_BAUDS 9600

//---pin and softwareSerial stuff definition
//---- for the pm sensor
#define P_BUF_LENG 31   //0x42 + 23 bytes equal to 24 bytes ->
#define P_TOWER_RX D2
#define P_TOWER_TX 6
#define P_BAUDS 9600

//-- DHT stuff
#define DHTPIN D3
#define DHTTYPE DHT11

// LEDs stuff
#define FASTLED_ESP8266_RAW_PIN_ORDER

#ifdef NUEVATARJETA
// Pines 16 y 14 no sirven para la librería fastled
#define NUM_LEDS 2
#define LED_PIN D1 //D0
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

#else
// Pines 16 y 14 no sirven para la librería fastled
#define NUM_LEDS 2
#define DI D3 //4 //D3  //0  // Si se usa la tarjeta wemos d1 mini se antepone la letra D a los pines
#define CI D2 //2 //D2  //4  // si se usa la roja de uber se unas los pines directamente
#define COLOR_ORDER GRB
#endif


//-- define special chars
const String STR_COMMA  = ",";
const String STR_SLASH =  "/";
 const String STR_DOT =  ".";
const String STR_COLON = ":";
const String STR_NULL = "NULL";
const String  STR_ZERO  = "0";
const String STR_SPACE  = " ";
// ----
// debugging
#ifdef  DEBUG
#define DMSG(args...)       Serial.print(args)
#define DMSGf(args...)      Serial.printf(args)
#define DMSG_STR(str)       Serial.println(str)
#else
#define DMSG(args...)
#define DMSGf(args...)
#define DMSG_STR(str)
#endif 
//--------

#endif
