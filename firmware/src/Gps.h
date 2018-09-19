#pragma once 
#ifndef _GPS_H
#define _GPS_H

#include<constants_defines.h>
#include <Arduino.h>
#include <Stream.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

namespace aqaGps {

  typedef struct gpsData {

    int ready = 0;

    String date;
    String time;
    double altitude;
    double course;
    double speed;
    double lat;
    double lng;
  };

  class AqaGps {

    public:
      AqaGps ();
      AqaGps(Stream &out);
      bool timeout(void);
      void aqaGpsSetup();
      void handleGpsData();
      TinyGPSPlus tinyGps;

    private:

      void _readGps(unsigned long timeout);
      Stream &_out;
      bool _timeout = false;
//     SoftwareSerial gpsSerial(GPS_RX,GPS_TX);


  };
}

#endif

