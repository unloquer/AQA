#include <aqaDht.h>

DHT dht(DHTPIN,DHTTYPE);

/*AqaDht::AqaDht(Stream &out) : _out(out) {

}*/
AqaDht::AqaDht() {

}

void AqaDht::setup() {

  dht.begin();

}

void AqaDht::_readDht(unsigned long timeout) {
  unsigned long start = millis();
  wdt_disable();

  do {

    if(!isnan(dht.readTemperature())) data.temperature = dht.readTemperature();
    if(!isnan(dht.readHumidity())) data.humidity = dht.readHumidity();

  }while (millis() - start < timeout);

//  wdt_enable(1000);
  wdt_reset();
}
void AqaDht::checkValues() {

  if(!isnan(dht.readTemperature()) && !isnan(dht.readHumidity())) {
    _isSensorFullyFunctional = true;
  } else {
    _isSensorFullyFunctional = false;
  }
  
}
bool AqaDht::sensorOk(void) {
  return _isSensorFullyFunctional;
}

void AqaDht::handleDhtData() {

  _readDht(1000);
  yield();
  checkValues();
  if(_isSensorFullyFunctional) {

  DMSG("validated ambientXD: ");
  DMSG(STR_SPACE);
  DMSG("temperature:  ");
  DMSG(data.temperature);
  DMSG(STR_SPACE);
  DMSG("humidity: ");
  DMSG_STR(data.humidity);
  
  
      

  }

}
dht11Data * AqaDht::getDhtData(void) {
  return &data;
}
