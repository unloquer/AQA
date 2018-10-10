
#include <led.h>
using namespace aqaLeds;

void AqaLeds::setupLeds() {
  #ifdef NUEVATARJETA
  FastLED.addLeds<LED_TYPE,LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  #else
  FastLED.addLeds<LPD8806, DI, CI, COLOR_ORDER>(leds, NUM_LEDS);
  #endif
}

void AqaLeds::ledParticulateQuality(aqaPlantower::plantowerData data) {
  int pm1 = data.pm1;
  int pm25 = data.pm25;
  int pm10 = data.pm10;

  CRGB alert = CRGB::Black;

  if(pm25 < 13) alert = CRGB::Green; // CRGB::Green; // Alert.ok
  if(pm25 >= 13 && pm25 < 35) alert = CRGB::Gold; // Alert.notGood;
  if(pm25 >= 35 && pm25 < 55) alert = CRGB::OrangeRed; // Alert.bad;
  if(pm25 >= 55 && pm25 < 75) alert = CRGB::DarkRed; // CRGB::Red; // Alert.dangerous;
  if(pm25 >= 75) alert = CRGB::Purple; // Alert.harmful;

  FastLED.setBrightness(millis() % 255);

  for(int i=0; i < 4; i++) {
    #ifdef NUEVATARJETA
    leds[0] = leds[1] = leds[2] = i%2 == 0 ? alert : CRGB::Black;
    #else
    leds[0] = leds[1] = i%2 == 0 ? alert : CRGB::Black;
    #endif
    FastLED.show();
    delay(300);
  }
}

  void AqaLeds::ledParticulateQuality2(aqaPlantower::plantowerData data) {
    int pm1 = data.pm1;
    int pm25 = data.pm25;
    int pm10 = data.pm10;

    CRGB alert = CRGB::Black;

    if(pm25 < 13) alert = CRGB::Green; // CRGB::Green; // Alert.ok
    if(pm25 >= 13 && pm25 < 35) alert = CRGB::OrangeRed; // Alert.notGood;
    if(pm25 >= 35 && pm25 < 55) alert = CRGB::Yellow; // Alert.bad;
    if(pm25 >= 55 && pm25 < 75) alert = CRGB::Red; // CRGB::Red; // Alert.dangerous;
    if(pm25 >= 75) alert = CRGB::Purple; // Alert.harmful;

    FastLED.setBrightness(millis() % 255);

    for(int i=0; i < 4; i++) {
      #ifdef NUEVATARJETA
      leds[0] = leds[1] = leds[2] = i%2 == 0 ? alert : CRGB::Black;
      #else
      leds[0] = leds[1] = i%2 == 0 ? alert : CRGB::Black;
      #endif
      FastLED.show();
      delay(100);
    }
}

void AqaLeds::ledParticulateQualityStreamming(aqaPlantower::plantowerData data) {
  int pm1 = data.pm1;
  int pm25 = data.pm25;
  int pm10 = data.pm10;

  CRGB alert = CRGB::Black;

  if(pm25 < 13) alert = CRGB::Green; // CRGB::Green; // Alert.ok
  if(pm25 >= 13 && pm25 < 35) alert = CRGB::OrangeRed; // Alert.notGood;
  if(pm25 >= 35 && pm25 < 55) alert = CRGB::Yellow; // Alert.bad;
  if(pm25 >= 55 && pm25 < 75) alert = CRGB::Red; // CRGB::Red; // Alert.dangerous;
  if(pm25 >= 75) alert = CRGB::Purple; // Alert.harmful;

  FastLED.setBrightness(millis() % 255);

  for(int i=0; i < 4; i++) {
    #ifdef NUEVATARJETA
    leds[0] = leds[1] = leds[2] =  i%2 == 0 ? alert : CRGB::Black;
    #else
    leds[0] = leds[1] = i%2 == 0 ? alert : CRGB::Black;
    #endif
    FastLED.show();
    delay(30);
  }
}
