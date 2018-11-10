/*
  LED Indicator config
*/
// https://github.com/FastLED/FastLED/wiki/ESP8266-notes
#define FASTLED_ESP8266_RAW_PIN_ORDER

#include "app.h"

#ifdef NUEVATARJETA

// Pines 16 y 14 no sirven para la librería fastled
#define NUM_LEDS 64
#define LED_PIN D2
#define LED_TYPE WS2812B
CRGB leds[NUM_LEDS];
#define COLOR_ORDER GRB

#else

// Pines 16 y 14 no sirven para la librería fastled
#define NUM_LEDS 2
#define DI D3 //4 //D3  //0  // Si se usa la tarjeta wemos d1 mini se antepone la letra D a los pines
#define CI D2 //2 //D2  //4  // si se usa la roja de uber se unas los pines directamente
CRGB leds[NUM_LEDS];
#define COLOR_ORDER GRB

#endif

void setupLeds() {
  #ifdef NUEVATARJETA
  FastLED.addLeds<LED_TYPE,LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  #else
  FastLED.addLeds<LPD8806, DI, CI, COLOR_ORDER>(leds, NUM_LEDS);
  #endif
  // https://github.com/FastLED/FastLED/issues/659
  // https://github.com/FastLED/FastLED/wiki/FastLED-Temporal-Dithering
  FastLED.setDither(0);
  FastLED.setBrightness(32);
}

void ledParticulateQuality(PlantowerData data) {
  int pm1 = data.pm1;
  int pm25 = data.pm25;
  int pm10 = data.pm10;

  CRGB alert = CRGB::Black;

  if(pm25 < 12) alert = CRGB::Green; // CRGB::Green; // Alert.ok
  if(pm25 >= 12 && pm25 < 35) alert = CRGB::Gold; // Alert.notGood;
  if(pm25 >= 35 && pm25 < 55) alert = CRGB::OrangeRed; // Alert.bad;
  if(pm25 >= 55 && pm25 < 150) alert = CRGB::DarkRed; // CRGB::Red; // Alert.dangerous;
  if(pm25 >= 150 && pm25 < 250) alert = CRGB::Purple; // CRGB::Purple; // Alert.VeryDangerous;
  if(pm25 >= 250) alert = CRGB::Brown; // Alert.harmful;

  //FastLED.setBrightness(millis() % 255);

  for(int i=0; i < 4; i++) {
    for(int j=0; j < NUM_LEDS; j++) leds[j] = i%2 == 0 ? alert : CRGB::Black;
    FastLED.delay(10);
    FastLED.show();
    FastLED.delay(300);
  }
}

void ledParticulateQualityStreamming(PlantowerData data) {
  int pm1 = data.pm1;
  int pm25 = data.pm25;
  int pm10 = data.pm10;

  CRGB alert = CRGB::Black;

  if(pm25 < 12) alert = CRGB::Green; // CRGB::Green; // Alert.ok
  if(pm25 >= 12 && pm25 < 35) alert = CRGB::Gold; // Alert.notGood;
  if(pm25 >= 35 && pm25 < 55) alert = CRGB::OrangeRed; // Alert.bad;
  if(pm25 >= 55 && pm25 < 150) alert = CRGB::DarkRed; // CRGB::Red; // Alert.dangerous;
  if(pm25 >= 150 && pm25 < 250) alert = CRGB::Purple; // CRGB::Purple; // Alert.VeryDangerous;
  if(pm25 >= 250) alert = CRGB::Chocolate; // Alert.harmful;

  FastLED.setBrightness(millis() % 255);

  for(int i=0; i < 4; i++) {
    for(int j=0; j < NUM_LEDS; j++) leds[j] = i%2 == 0 ? alert : CRGB::Black;
    FastLED.delay(10);
    FastLED.show();
    FastLED.delay(100);
  }
}
