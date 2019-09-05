#pragma once 
#ifndef _AQA_DHT_H
#define _AQA_DHT_H

#include<constants_defines.h>
#include <Arduino.h>
#include <Stream.h>
#include <DHT.h>

typedef struct dht11Data {

  int ready = 0;

  //    String date;
  // String time;
  float temperature;
  float humidity;
};

class AqaDht {

public:
  //      AqaDht(Stream &out);
  AqaDht();
  // todo: implement timeouts
  // and states for querying data
  //bool timeout(void);
  void handleDhtData();
  void setup();
  float getTemperature(void);
  float getHumidity(void);

  bool sensorOk(void);
  dht11Data * getDhtData(void);
private:

  void checkValues();
  bool _isSensorFullyFunctional;
  dht11Data data;
  void _readDht(unsigned long timeout);
  //      Stream &_out;
  bool _timeout = false;


};

#endif

