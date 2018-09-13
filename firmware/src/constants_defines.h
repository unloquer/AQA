#pragma once

#ifndef _CONSTANTS_DEFINES_H
#define _CONSTANTS_DEFINES_H
#include <Arduino.h>

#define NUEVATARJETA

 
#define DEBUG


//
//-- define special chars
#define STR_COMMA  ","
#define STR_SLASH  "/"
#define STR_DOT  "."
#define STR_COLON  ":"
#define STR_NULL  "NULL"
#define STR_ZERO  "0"
#define STR_SPACE  " "
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
