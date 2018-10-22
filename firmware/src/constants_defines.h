#pragma once

#ifndef _CONSTANTS_DEFINES_H
#define _CONSTANTS_DEFINES_H
#include <Arduino.h>

#define NUEVATARJETA

 
#define DEBUG
#define NUEVATARJETA
#define MOBILE

//------ http

const uint16_t HTTP_TIMEOUT = 1000 * 60;
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
#define P_TOWER_RX 5
#define P_TOWER_TX 6
#define P_BAUDS 9600

//-- DHT stuff
#define DHTPIN 12//D6//
#define DHTTYPE DHT11

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
