#ifndef _P_TOWER_H
#define _P_TOWER_H

#include <constants_defines.h>
#include <Arduino.h>
#include <Stream.h>

typedef struct plantowerData {

  int ready = 0;

  //    String date;
  // String time;
  int pm1;
  int pm25;
  int pm10;
};

class AqaPlantower {

public:
  AqaPlantower(Stream &out);
  // todo: implement timeouts
  // and states for querying data
  //bool timeout(void);
  void handlePlantowerData();
  bool sensorOk(void);
  plantowerData * getPlantowerData(void);

private:

  void checkValidPlantower();
  bool _isSensorFullyFunctional;
  plantowerData data;
  void _readPlantower(unsigned long timeout);
  Stream &_out;
  bool _timeout = false;
  unsigned char buf[P_BUF_LENG];
  char checkValue(unsigned char *thebuf, char leng);
  int parsePM01(unsigned char *thebuf);
  int parsePM2_5(unsigned char *thebuf);
  int parsePM10(unsigned char *thebuf);


};

#endif
