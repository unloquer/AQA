/*
  LED Indicator config
*/
// https://github.com/FastLED/FastLED/wiki/ESP8266-notes
#define FASTLED_ESP8266_RAW_PIN_ORDER

#include "app.h"

#ifdef NUEVATARJETA

// Pines 16 y 14 no sirven para la librería fastled
#define NUM_LEDS 3
#define LED_PIN 4
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
  FastLED.setBrightness(64);
  FastLED.setDither(0);
}

void ledParticulateQuality(PlantowerData data) {
  int pm1 = data.pm1;
  int pm25 = data.pm25;
  int pm10 = data.pm10;

  CRGB alert = CRGB::Black;
 
if(pm25 < 13){
     //alert = CRGB::Green; // CRGB::Green; // Alert.ok
      int color=255*pm25/13;
       alert = CRGB(0,color,0);
       DMSG_STR(color);
   }
  if(pm25 >= 13 && pm25 < 35) {
    //  alert = CRGB::Gold; // Alert.notGood;
      int color=255*pm25/35;
       alert = CRGB(255,color,0);
       DMSG_STR(color);
    }
  if(pm25 >= 35 && pm25 < 55) {
      //alert = CRGB::OrangeRed; // Alert.bad;
      int color=150*pm25/55;
       alert = CRGB(255,color,0);
       DMSG_STR(color);
    }
  if(pm25 >= 55 && pm25 < 75) {
    //alert = CRGB::DarkRed; // CRGB::Red; // Alert.dangerous;
      int color=255*pm25/75;
       alert = CRGB(color,0,0);
       DMSG_STR(color);
  }
  if(pm25 >= 75 && pm25 < 255)  {
    //alert = CRGB::Purple;  // CRGB::Purple; // Alert.VeryDangerous;
      int color=180*pm25/255;
       alert = CRGB(175,0,color);
       DMSG_STR(color);
  }


  leds[0] = leds[1] = leds[2] = alert;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(300);
  leds[0] = leds[1] = leds[2]= CRGB::Black;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(300);
  leds[0] = leds[1] = leds[2]= alert;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(300);
  leds[0] = leds[1] = leds[2]= CRGB::Black;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(300);
  leds[0] = leds[1] = leds[2]= alert;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(300);
  leds[0] = leds[1] = leds[2]= CRGB::Black;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(300);


void ledParticulateQualityStreamming(PlantowerData data) {
  int pm1 = data.pm1;
  int pm25 = data.pm25;
  int pm10 = data.pm10;

  CRGB alert = CRGB::Black;

  leds[0] = leds[1] = leds[2]= alert;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(100);
  leds[0] = leds[1] = leds[2]= CRGB::Black;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(100);
  leds[0] = leds[1] = leds[2]= alert;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(100);
  leds[0] = leds[1] = leds[2]= CRGB::Black;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(100);
  leds[0] = leds[1] = leds[2]= alert;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(100);
  leds[0] = leds[1] = leds[2]= CRGB::Black;
  FastLED.delay(10);
  FastLED.show();
  FastLED.delay(100);

}

