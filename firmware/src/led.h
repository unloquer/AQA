#pragma once
#ifndef _AQA_LED_H
#define _AQA_LED_H

#include <constants_defines.h>
#include <P_tower.h>
#include <FastLED.h>
#include <Arduino.h>
/*
  LED Indicator config
*/
// https://github.com/FastLED/FastLED/wiki/ESP8266-notes

class AqaLeds {

public: 
  void setupLeds();

  void ledParticulateQuality(plantowerData data);
  void ledParticulateQuality2(plantowerData data);
  void ledParticulateQualityStreamming(plantowerData data);

private:
  CRGB leds[NUM_LEDS];

};





#endif
