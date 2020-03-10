#include <P_tower.h>

AqaPlantower::AqaPlantower(Stream &out) : _out(out)
{

}

char AqaPlantower::checkValue(unsigned char *thebuf, char leng) {
  char receiveflag = 0;
  int receiveSum = 0;

  for(int i=0; i<(leng-2); i++) {
    receiveSum = receiveSum + thebuf[i];
  }
  receiveSum = receiveSum + 0x42;

  if(receiveSum == ((thebuf[leng-2]<<8) + thebuf[leng-1])) {
    receiveSum = 0;
    receiveflag = 1;
    _isSensorFullyFunctional = true;
  }else {
    _isSensorFullyFunctional = false;
  }

  return receiveflag;
  
}

int AqaPlantower::parsePM01(unsigned char *thebuf) {

  return  ((thebuf[3]<<8) + thebuf[4]); //count PM1.0 value of the air detector module

}
int AqaPlantower::parsePM2_5(unsigned char *thebuf) {

  return  ((thebuf[5] << 8) + thebuf[6]);//count PM2.5 value of the air detector module
}
int AqaPlantower::parsePM10(unsigned char *thebuf) {

  return  ((thebuf[7] << 8) + thebuf[8]); //count PM10 value of the air detector module
}

bool AqaPlantower::sensorOk(void) {

  return _isSensorFullyFunctional;
}

void AqaPlantower::_readPlantower(unsigned long timeout) {
  unsigned long start = millis();
  wdt_disable();

  do {
    if(_out.find(0x42)) {

      _out.readBytes(buf, P_BUF_LENG);

      if(buf[0] == 0x4d) {
        if(checkValue(buf, P_BUF_LENG)){
          DMSG_STR("value checked");
          data.pm1 = parsePM01(buf);
          data.pm10 = parsePM10(buf);
          data.pm25 = parsePM2_5(buf);
          yield();
        }

      }
    }
  } while (millis() - start < timeout);

//  wdt_enable(1000);
  wdt_reset();

  DMSG("PM2.5:  ");
  DMSG(data.pm25);
  DMSG_STR("  ug/m3");
  DMSG("PM1:  ");
  DMSG(data.pm10);
  DMSG_STR("  ug/m3");
  DMSG("PM1:  ");
  DMSG(data.pm1);
  DMSG_STR("  ug/m3");
  

}

void AqaPlantower::handlePlantowerData() {
  _readPlantower(1000);
  yield();
}

plantowerData * AqaPlantower::getPlantowerData(void) {
  return &data;
}
