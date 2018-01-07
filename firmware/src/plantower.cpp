#ifndef APP
#define APP
#include "app.h"
#endif

// #define LENG 23   //0x42 + 23 bytes equal to 24 bytes ->
#define LENG 31   //0x42 + 23 bytes equal to 24 bytes ->
unsigned char buf[LENG];

int PM01Value = 0;          //define PM1.0 value of the air detector module
int PM2_5Value = 0;         //define PM2.5 value of the air detector module
int PM10Value = 0;         //define PM10 value of the air detector module

SoftwareSerial pmsSerial(5, 6);

char checkValue(unsigned char *thebuf, char leng) {
  char receiveflag = 0;
  int receiveSum = 0;

  for(int i=0; i<(leng-2); i++) {
    receiveSum = receiveSum + thebuf[i];
  }
  receiveSum = receiveSum + 0x42;

  if(receiveSum == ((thebuf[leng-2]<<8) + thebuf[leng-1])) {
    receiveSum = 0;
    receiveflag = 1;
  }

  return receiveflag;
}

int parsePM01(unsigned char *thebuf) {
  int PM01Val;
  PM01Val = ((thebuf[3]<<8) + thebuf[4]); //count PM1.0 value of the air detector module
  return PM01Val;
}

//transmit PM Value to PC
int parsePM2_5(unsigned char *thebuf) {
  int PM2_5Val;
  PM2_5Val = ((thebuf[5] << 8) + thebuf[6]);//count PM2.5 value of the air detector module
  return PM2_5Val;
}

//transmit PM Value to PC
int parsePM10(unsigned char *thebuf) {
  int PM10Val;
  PM10Val = ((thebuf[7] << 8) + thebuf[8]); //count PM10 value of the air detector module
  return PM10Val;
}


PlantowerData readPlantower(unsigned long ms) {
  PlantowerData data;

  unsigned long start = millis();
  wdt_disable();

  do {
    //while(pmsSerial.available()) {
    if(pmsSerial.find(0x42)) {    //start to read when detect 0x42
      //Serial.println("has 0x42");
      pmsSerial.readBytes(buf,LENG);

      if(buf[0] == 0x4d){
        //Serial.println("has 0x4d");
        if(checkValue(buf,LENG)){
          Serial.println("value checked");
          PM01Value = parsePM01(buf); //count PM1.0 value of the air detector module
          PM2_5Value = parsePM2_5(buf);//count PM2.5 value of the air detector module
          PM10Value = parsePM10(buf); //count PM10 value of the air detector module

          data.ready = 1;
          data.pm1 = PM01Value;
          data.pm10 = PM10Value;
          data.pm25 = PM2_5Value;
        }
      }
    }
    // }
  } while (millis() - start < ms);

  wdt_enable(1000);

  Serial.print("PM1.0: ");
  Serial.print(PM01Value);
  Serial.println(" ug/m3");

  Serial.print("PM2.5: ");
  Serial.print(PM2_5Value);
  Serial.println(" ug/m3");

  Serial.print("PM1 0: ");
  Serial.print(PM10Value);
  Serial.println(" ug/m3");
  Serial.println();

  return data;
}

void setupPlantower() {
  static const int pmsRXPin = 12, pmsTXPin = 6;
  static const uint32_t bauds = 9600;
  pmsSerial.begin(bauds);
}

PlantowerData getPlantowerData() {
  PlantowerData data = readPlantower(1000);
  return data;
}
