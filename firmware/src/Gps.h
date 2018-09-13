#pragma once 
#ifndef _GPS_H
#define _GPS_H

#include<constants_defines.h>
#include <Arduino.h>
#include <TinyGPS++.h>
#include <Stream.h>

class GPS {

  public:

    int ready = 35;

    String date;
    String time;
    double altitude;
    double course;
    double speed;
    double lat;
    double lng;

};

#endif

