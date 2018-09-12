#pragma once

// debugging 
#define DEBUG
#define NUEVATARJETA

#ifdef DEBUG
#define DMSG(args...)       Serial.print(args)
#define DMSGf(args...)      Serial.printf(args)
#define DMSG_STR(str)       Serial.println(str)
#else
#define DMSG(args...)
#define DMSGf(args...)
#define DMSG_STR(str)
#endif
