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

void ledParticulateQuality(aqaPlantower::plantowerData data);
void ledParticulateQualityStreamming(aqaPlantower::plantowerData data);
void ledParticulateQualityStream(aqaPlantower::plantowerData data);
