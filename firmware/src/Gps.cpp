
#include<Arduino.h>
#include <constants_defines.h>
#include <TinyGPS++.h>
#include<Gps.h>
using namespace aqaGps;


AqaGps::AqaGps(Stream &out) : _out(out)
{

}



void AqaGps::aqaGpsSetup()
{

}

void  AqaGps::_readGps(unsigned long timeout)
{
  unsigned long start = millis();
  wdt_disable(); 
  
  do {
    while(_out.available()) {

//      DMSG_STR();
      tinyGps.encode(_out.read());
    }
  }while (millis() - start < timeout);

  wdt_enable(1000);
}

void AqaGps::handleGpsData()
{

  _readGps(800);
  gpsData data;

  yield();
  if(tinyGps.location.isValid()){
    data.lat = tinyGps.location.lat();
    data.lng = tinyGps.location.lng();

    DMSG("lat:  ");
     DMSG(data.lat);DMSG(STR_SPACE);
    DMSG("long: ");
    DMSG_STR(data.lng);

  }else {
    DMSG_STR("gsp not ready!");
  }

  if(tinyGps.date.isValid()) {

    data.date += tinyGps.date.month() + STR_SLASH + tinyGps.date.day() +
      STR_SLASH + tinyGps.date.year();
    DMSG_STR("date :"+data.date);
  }

}
