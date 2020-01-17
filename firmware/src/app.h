#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <aqaWifi.h>
#include <constants_defines.h>
#include <Gps.h>
#include <P_tower.h>
#include <aqaDht.h>
#include <http.h>
#include <led.h>
//----------------
#include <FS.h>
#include <filesystem.h>
#include <DoubleResetDetector.h>
#include <GDBStub.h>


//----- TODO: frame class --> data formater for different interfaces

String csvFrame();
String influxFrame();
void save();
String readPosition();
void savePosition(String position);
// function to check module hook up
void checkConnectedModules(unsigned long timeout);

