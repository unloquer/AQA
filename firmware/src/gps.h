#pragma once 
#ifndef _GPS_H
#define _GPS_H

#include <Arduino.h>
#include <TinyGPS++.h>

class GPS {

  public:

    int ready = 0;

    String date;
    String time;
    double altitude;
    double course;
    double speed;
    double lat;
    double lng;

};

#endif

