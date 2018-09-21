#pragma once 
#ifndef _GPS_H
#define _GPS_H

#include<constants_defines.h>
#include <Arduino.h>
#include <Stream.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Time.h>
#include <TimeLib.h>

namespace aqaGps {

  typedef struct gpsData {

    int ready = 0;

//    String date;
   // String time;
    double altitude;
    double course;
    double speed;
    double lat;
    double lng;
    time_t epoch_time;
  };

  class AqaGps {

    public:
      AqaGps(Stream &out);
      // todo: implement timeouts
      // and states for querying data
      //bool timeout(void);
      void handleGpsData();

    private:

      bool sensorOk(void);
      void checkValidGps();
      bool _isSensorFullyFunctional;
      tmElements_t time_struct;
      gpsData data;
      TinyGPSPlus tinyGps;
      void _readGps(unsigned long timeout);
      Stream &_out;
      bool _timeout = false;


  };
}

#endif

