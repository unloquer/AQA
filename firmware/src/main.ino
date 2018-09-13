#include <Arduino.h>
#include <app.h>
GPS my_gps;
void setup() {

  Serial.begin(115200);

  Serial.println(my_gps.ready);
  String defines = STR_DOT;
  defines+=STR_COMMA;
  defines+=STR_SPACE;
  defines += STR_ZERO;
  defines += STR_SLASH;
  defines += STR_NULL;

  DMSG_STR(defines);

}


void loop() {


}
