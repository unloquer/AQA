
//#include<Arduino.h>
//#include <constants_defines.h>
#include <Gps.h>

AqaGps::AqaGps(Stream &out) : _out(out)
{

}



void  AqaGps::_readGps(unsigned long timeout)
{

  //if (!_out.available()) DMSG_STR("unavailable");

  unsigned long start = millis();
  wdt_disable(); 

  do {
    while(_out.available()) {

      //      DMSG_STR();
      tinyGps.encode(_out.read());
    }
  }while (millis() - start < timeout);

//  wdt_enable(1000);
  wdt_reset();
}

void AqaGps::handleGpsData()
{

  _readGps(800);
  yield();

  //checkValidGps();

  if(tinyGps.location.isValid()){
    // sensor fuuly functional
    data.lat = tinyGps.location.lat();
    data.lng = tinyGps.location.lng();

    /* DMSG("lat:  ");
       DMSG(data.lat);DMSG(STR_SPACE);
       DMSG("long: ");
       DMSG_STR(data.lng);*/

  }else {
    //    DMSG_STR("gsp not ready!");
  }

  /*  if(tinyGps.date.isValid()) {

      data.date += tinyGps.date.month() + STR_SLASH + tinyGps.date.day() +
      STR_SLASH + tinyGps.date.year();

  //    DMSG_STR("date :"+data.date);
  }
  if (tinyGps.time.isValid()) {
  String timeStr = "";
  if (tinyGps.time.hour() < 10) timeStr += STR_ZERO;
  timeStr += tinyGps.time.hour();
  timeStr += STR_COLON;

  if (tinyGps.time.minute() < 10) timeStr += STR_ZERO;
  timeStr += tinyGps.time.minute();
  timeStr += STR_COLON;

  if (tinyGps.time.second() < 10) timeStr += STR_ZERO;
  timeStr += tinyGps.time.second();
  timeStr += STR_DOT;

  if (tinyGps.time.centisecond() < 10) timeStr += STR_ZERO;
  timeStr += tinyGps.time.centisecond();

  data.time = timeStr;
  DMSG("time: ");
  DMSG_STR(data.time);
  }*/
  /////-------- handle epoch
  if(tinyGps.date.isValid() && tinyGps.time.isValid()) {


    time_struct.Year = CalendarYrToTm(tinyGps.date.year());
    time_struct.Month = tinyGps.date.month();
    time_struct.Day = tinyGps.date.day();
    time_struct.Hour = tinyGps.time.hour();
    time_struct.Minute = tinyGps.time.minute();
    time_struct.Second = tinyGps.time.second();

    data.epoch_time = makeTime(time_struct);
    yield();
    /*DMSG("epoch time: ");
      DMSG_STR(data.epoch_time);*/ 



  }
  if(tinyGps.altitude.isValid()) {
    data.altitude = tinyGps.altitude.meters();
    /*DMSG("altitude: ");
      DMSG_STR(data.altitude);*/
  }
  if(tinyGps.course.isValid()) {
    data.course = tinyGps.course.deg();
    /*DMSG("course: ");
      DMSG_STR(data.course);*/ 
  }
  if(tinyGps.speed.isValid()) {
    data.speed = tinyGps.speed.kmph();
    /* DMSG("speed: ");
       DMSG_STR(data.speed);*/ 
  }

  if(sensorOk()) {
    // receiving data from software serial &&
    // gps location is valid
    DMSG("lat:  ");
    DMSG(data.lat);DMSG(STR_SPACE);
    DMSG("long: ");
    DMSG_STR(data.lng);
    DMSG("epoch time: ");
    DMSG_STR(data.epoch_time);
    /*  DMSG("altitude: ");
        DMSG_STR(data.altitude);
        DMSG("course: ");
        DMSG_STR(data.course); 
        DMSG("speed: ");
        DMSG_STR(data.speed);*/ 
  }else {
    // DMSG_STR("Sensor NOT FULLY OK");
  }

  checkValidGps();
  yield();
}

// is sensor ok
bool AqaGps::sensorOk (void) {

  return _isSensorFullyFunctional;
}

void AqaGps::checkValidGps () {
  // this sensor is "functional" if its location is valid
  // neet to integrate connection to serial data: _out.available()
  if(tinyGps.location.isValid()) {
    _isSensorFullyFunctional = true;
  }
  /*  if (!_out.available()){
      DMSG_STR("sensor not connected");
      _isSensorFullyFunctional = false;
      }*/ 
  if(!tinyGps.location.isValid() && tinyGps.date.isValid()) {
    DMSG_STR("GPS GETTING LOCATION");
    DMSG_STR(data.epoch_time);
    _isSensorFullyFunctional = false;
  }
}

gpsData * AqaGps::getGpsData(void) {
  return &data;
}
