#pragma once

#ifndef _CONSTANTS_DEFINES_H
#define _CONSTANTS_DEFINES_H
#include <Arduino.h>

#define NUEVATARJETA

 
#define DEBUG

//---pin and softwareSerial stuff definition
//
#define GPS_RX 13
#define GPS_TX 7
#define GPS_BAUDS 9600

//
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
