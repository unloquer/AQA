/*
  LED Indicator config
*/
// https://github.com/FastLED/FastLED/wiki/ESP8266-notes
#define FASTLED_ESP8266_RAW_PIN_ORDER

#include "app.h"

// Pines 16 y 14 no sirven para la librería fastled
#define NUM_LEDS 2
#define DI D3 //4  //0  // Si se usa la tarjeta wemos d1 mini se antepone la letra D a los pines
#define CI D2 //2 //4  // si se usa la roja de uber se unas los pines directamente
CRGB leds[NUM_LEDS];

void setupLeds() {
  FastLED.addLeds<LPD8806, DI, CI>(leds, NUM_LEDS);
}

void ledParticulateQuality(PlantowerData data) {
  int pm1 = data.pm1;
  int pm25 = data.pm25;
  int pm10 = data.pm10;

  CRGB alert = CRGB::Black;

  if(pm25 < 13) alert = CRGB::Red; // CRGB::Green; // Alert.ok
  if(pm25 >= 13 && pm25 < 35) alert = CRGB::OrangeRed; // Alert.notGood;
  if(pm25 >= 35 && pm25 < 55) alert = CRGB::Yellow; // Alert.bad;
  if(pm25 >= 55 && pm25 < 75) alert = CRGB::Green; // CRGB::Red; // Alert.dangerous;
  if(pm25 >= 75) alert = CRGB::Purple; // Alert.harmful;

  FastLED.setBrightness(millis() % 255);

  for(int i=0; i < 4; i++) {
    leds[0] = leds[1] = i%2 == 0 ? alert : CRGB::Black;
    FastLED.show();
    delay(300);
  }
}
  void ledParticulateQuality2(PlantowerData data) {
    int pm1 = data.pm1;
    int pm25 = data.pm25;
    int pm10 = data.pm10;

    CRGB alert = CRGB::Black;

    if(pm25 < 13) alert = CRGB::Red; // CRGB::Green; // Alert.ok
    if(pm25 >= 13 && pm25 < 35) alert = CRGB::OrangeRed; // Alert.notGood;
    if(pm25 >= 35 && pm25 < 55) alert = CRGB::Yellow; // Alert.bad;
    if(pm25 >= 55 && pm25 < 75) alert = CRGB::Green; // CRGB::Red; // Alert.dangerous;
    if(pm25 >= 75) alert = CRGB::Purple; // Alert.harmful;

    FastLED.setBrightness(millis() % 255);

    for(int i=0; i < 4; i++) {
      leds[0] = leds[1] = i%2 == 0 ? alert : CRGB::Black;
      FastLED.show();
      delay(100);
    }
}
