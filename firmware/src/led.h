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
#define FASTLED_ESP8266_RAW_PIN_ORDER

#ifdef NUEVATARJETA

// Pines 16 y 14 no sirven para la librería fastled
#define NUM_LEDS 3
#define LED_PIN 4
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

#else

// Pines 16 y 14 no sirven para la librería fastled
#define NUM_LEDS 2
#define DI D3 //4 //D3  //0  // Si se usa la tarjeta wemos d1 mini se antepone la letra D a los pines
#define CI D2 //2 //D2  //4  // si se usa la roja de uber se unas los pines directamente
#define COLOR_ORDER GRB

#endif

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
