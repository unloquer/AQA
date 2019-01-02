#pragma once

#include <aqaWifi.h>
#include <Arduino.h>
#include <constants_defines.h>
#include <Gps.h>
#include <P_tower.h>
#include <aqaDht.h>
#include <http.h>
#include <led.h>
//----------------
#include <FS.h>
#include <DoubleResetDetector.h>
#include <GDBStub.h>


//----- TODO: frame class --> data formater for different interfaces

String csvFrame();
String influxFrame();
void save();
// function to check module hook up
void checkConnectedModules(unsigned long timeout);

/*void ledParticulateQuality(plantowerData data);
void ledParticulateQualityStreamming(plantowerData data);
void ledParticulateQualityStream(plantowerData data);*/
