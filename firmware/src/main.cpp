#include <app.h>
#include <Ticker.h>
//gps configuration
SoftwareSerial gpsSerial(GPS_RX,GPS_TX);
AqaGps gpsSensor(gpsSerial);
// plantower pm configuration
SoftwareSerial plantower_serial(P_TOWER_RX, P_TOWER_TX);
AqaPlantower plantowerSensor(plantower_serial);
// DHT
AqaDht dhtSensor;
//HC06
//SoftwareSerial hc06(1,3);
// Wifi
AqaWifi the_wifi(5000);// aqawifi(int i) initializes a ticker callback. doesnt work with ping
//--------- variables to point to the data of the sensors
gpsData * gpsInfo;
plantowerData * plantowerInfo;
dht11Data * dhtInfo;

//---leds
AqaLeds aqa_leds;

// Filesystem
filesystem _fs;

bool system_connected = false;

DoubleResetDetector drd(DRD_TIMEOUT, DRD_ADDRESS);

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    yield();
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void readLog() {
  DMSG_STR("Reading log ...");
  _fs.file = SPIFFS.open("datalog.txt", "r");
  if(readPosition().toInt() > 0) _fs.file.seek(readPosition().toInt(),SeekSet);
  DMSG_STR("Initial position " + readPosition());
  String line = "", line2send;
  int linesCnt = 0;
  String device,lat,lng,date,hour,altitude,course,speed,humidity,temperature,pm1,pm25,pm10;
  String y,m,d,h,mi,s;
  int Year,Month,Day,Hour,Minute,Second;
  if (!_fs.file) DMSG_STR("file open failed");  // Check for errors
  
  while (_fs.file.available()) {
    yield();
    wdt_disable();
    // Read all the data from the file and display it

    char c = _fs.file.read();
    int field;
    if(c == '\r') {
      if(!line.endsWith("NULL")) {
        //pm10
        pm10 = line;
        //DMSG("pm10=");DMSG(line);DMSG(" ");DMSG_STR(field);

        linesCnt ++;

        line2send += device + STR_COMMA + F("id=") + device + F(" lat=") + lat + F(",lng=") + lng + F(",altitude=") + altitude + F(",course=") + course + F(",speed=") + speed + F(",humidity=") + humidity + F(",temperature=") + temperature + F(",pm1=") + pm1 + F(",pm25=") + pm25 + F(",pm10=") + pm10 + F(" ") + date + F("\n");

        if(linesCnt == 40) { // que pasa si la última tanda tiene menos de 50 líneas??
          DMSG_STR(linesCnt);
          //DMSG(line2send);
          // DMSG_STR("Free Memory: "+String(ESP.getFreeHeap()));
          savePosition((String) _fs.file.position());
          DMSG_STR("File position "+ String(_fs.file.position())); // La posición de memoria donde va leyendo el archivo, almacenarla para continuar desde acá
          aqaHttp::post2Influx("http://aqa.unloquer.org:8086/write?db=aqamobile&precision=s", line2send);
          line2send = "";
          linesCnt = 0;
        }
      }

      // Discard the \n, which is the next byte

      field = 0;
      _fs.file.read();
      line = "";
    } else {
      if(c == ',') {
        
        switch(field) {
        case 0:
          //device
          device = line;
          //DMSG("device=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 1:
          //lat
          lat = line;
          //DMSG("lat=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 2:
          //lng
          lng = line;
          //DMSG("lng=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 3:
          //date
          date = line;
          // DMSG("date=");DMSG(line);DMSG(" ");DMSG_STR(field);

          break;
        case 4:
          //hour// altitude 
          altitude = line;
          //DMSG("altitude=");DMSG(line);DMSG(" ");DMSG_STR(field);
          /*         s = getValue(line, ':', 2);
                     mi = getValue(line, ':', 1);
                     h = getValue(line, ':', 0);
                     Hour = h.toInt();
                     Minute = mi.toInt();
                     Second = s.toInt();*/
          break;
        case 5:
          //course
          course = line;
          //DMSG("course=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 6:
          //speed
          speed = line;
          //DMSG("speed=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 7:
          //humidity
          humidity = line;
          //DMSG("humidity=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 8:
          //temperature
          temperature = line;
          //DMSG("temperature=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 9:
          // pm1
          pm1 = line;
          //    DMSG("pm1=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 10:
          //pm25
          pm25 = line;
          //        DMSG("pm25=");DMSG(line);DMSG(" ");DMSG_STR(field);
          yield();
          break;
        case 11:
          //pm10
          pm10 = line;
          //          DMSG("pm10=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
          //default:
          
        }
        line = "";
        field++;
      } else {line += String(c);}
    }
    wdt_enable(1000);
  }

}


Ticker reset_ticker;
void tick() {
  if(!WiFi.isConnected()) {
    DMSG_STR("restarting system");
    digitalWrite(D0, LOW); delay(100); // from here https://github.com/esp8266/Arduino/issues/1622#issuecomment-347165350
  }
}
void setup() {
  //hc06.begin(9600);
  pinMode(D0, OUTPUT); digitalWrite(D0, HIGH); // https://github.com/esp8266/Arduino/issues/1622#issuecomment-347165350
  Serial.begin(9600);
  
  SPIFFS.begin();
  _fs.fs_info_print();
  gpsSerial.begin(GPS_BAUDS);
  plantower_serial.begin(P_BAUDS);

  dhtSensor.setup();
  aqa_leds.setupLeds();
  
  reset_ticker.attach(600,tick);
  DMSG_STR("\nStarting ...");

  // point to the right addresses :3
  dhtInfo = dhtSensor.getDhtData();
  plantowerInfo = plantowerSensor.getPlantowerData();
  gpsInfo = gpsSensor.getGpsData();
  //fs_info_print();
  //set up networking
#ifdef MOBILE
  DMSG_STR("MOVIL");
  if(drd.detectDoubleReset()) {
    DMSG_STR("connecting to network...");

    the_wifi.init_connections();
    readLog();
    _fs.fs_delete_file();
    savePosition("0");
  }
#else
  DMSG_STR("FIJO");
  the_wifi.init_connections();
#endif

  // check connected modules directive -> all .sensorOk() together
  //checkConnectedModules(10000);
  DMSG_STR("reached check timeout");
  /* if(checkConnectedModules(50000)){
     DMSG_STR("CHECKED");

     }else{
     DMSG_STR("didn't check");
     }*/

}


void loop() {

  gpsSensor.handleGpsData();
  yield();
  plantowerSensor.handlePlantowerData();
  yield();
  dhtSensor.handleDhtData();
  yield();
 
  wdt_reset();
  //  the_wifi.check_connections();
  aqa_leds.ledParticulateQuality(*plantowerInfo);

#ifdef MOBILE
  if( gpsSensor.sensorOk() && plantowerSensor.sensorOk() && dhtSensor.sensorOk())
    {
      save();
      aqa_leds.ledParticulateQualityStreamming(*plantowerInfo);
    }
#else
  if(true/*plantowerSensor.sensorOk() && dhtSensor.sensorOk()*/)
    {
      //ready to send to the server
      DMSG_STR("ready to SAVE/UPLOAD");
      String frame = influxFrame();
      DMSG_STR(frame);
      yield();
      aqaHttp::post2Influx("http://aqa.unloquer.org:8086/write?db=aqa", frame);

      aqa_leds.ledParticulateQualityStreamming(*plantowerInfo);
    }else {

    DMSG("gps:  ");
    DMSG(gpsSensor.sensorOk());
    DMSG("internet:  ");
    DMSG(the_wifi.internetOk());
    DMSG("plantower:  ");
    DMSG(plantowerSensor.sensorOk());
    DMSG("dht :  ");
    DMSG_STR(dhtSensor.sensorOk());
  }
#endif
  yield();
}

String readPosition() {
  char filename [] = "position.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  fs::File file = SPIFFS.open(filename, "r");
  if (!file) {
    DMSG_STR("file open failed");   // Check for errors
    return "-1";
  }
  String p = file.readString();
  return p;
}

void savePosition(String position) {
  char filename [] = "position.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  fs::File file = SPIFFS.open(filename, "w+");
  if (!file) {
    DMSG_STR("file open failed");   // Check for errors
    return;
  }

  //DMSG_STR("Dentro de saveposition " + position);
  file.println(position);
  file.close();
}

void save() {
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  fs::File file = SPIFFS.open(filename, "a+");        // Open a file for reading and writing (appending)
  if (!file) {
    DMSG_STR("file open failed");   // Check for errors
    return;
  }

  String frame = csvFrame();
  DMSG_STR(frame);
  file.println(frame);
  file.close();
}

String csvFrame() {
  /* CSV is ordered as:
     "id","epochtime","lat","lng","altitude","course","speed","humidity",
     "temperature","pm1","pm25","pm10"
  */

  // First datum is the sensor_id
  String frame = SENSOR_ID + STR_COMMA;

  // Add GPS data
  char strlat[25],strlng[25];
  dtostrf(gpsInfo->lat, 3, 6, strlat);
  dtostrf(gpsInfo->lng, 3, 6, strlng);

  frame += gpsInfo->epoch_time + STR_COMMA; //refactored to epoch time
  frame += strlat + STR_COMMA;
  frame += strlng + STR_COMMA;
  frame += gpsInfo->altitude + STR_COMMA;
  frame += gpsInfo->course + STR_COMMA;
  frame += gpsInfo->speed + STR_COMMA;

  //Add DHT11 data
  if(dhtSensor.sensorOk()) {
    frame += dhtInfo->humidity + STR_COMMA;
    frame += dhtInfo->temperature + STR_COMMA;
  } else {
    frame += STR_NULL + STR_COMMA + STR_NULL + STR_COMMA;
  }

  // Add Plantower data
  if(plantowerSensor.sensorOk()) {
    frame += plantowerInfo->pm1 + STR_COMMA;
    frame += plantowerInfo->pm25 + STR_COMMA;
    frame += plantowerInfo->pm10;
  } else {
    frame += STR_NULL + STR_COMMA + STR_NULL + STR_COMMA + STR_NULL;
  }

  return frame;
}

String influxFrame() {
  /* CSV is ordered as:
     "id","lat","lng","date","time","altitude","course","speed","humidity",
     "temperature","pm1","pm25","pm10"
  */

  // First datum is the sensor_id
  String frame = SENSOR_ID + STR_COMMA + F("id=") + SENSOR_ID +  STR_SPACE;

  // Add GPS data
  char strlat[25],strlng[25];

  dtostrf(gpsInfo->lat, 3, 6, strlat);
  dtostrf(gpsInfo->lng, 3, 6, strlng);
  frame += F("lat=");
#ifdef FIXED_LAT
  frame += FIXED_LAT + STR_COMMA; // hard coded latitude lat
#else
  frame += strlat + STR_COMMA;
#endif

  frame += F("lng=");
#ifdef FIXED_LON
  frame += FIXED_LON + STR_COMMA;// hard coded longitude lng
#else
  frame += strlng + STR_COMMA;
#endif
  frame += F("altitude=");
  frame += gpsInfo->altitude + STR_COMMA;
  frame += F("course=");
  frame += gpsInfo->course + STR_COMMA;
  frame += F("speed=");
  frame += gpsInfo->speed + STR_COMMA;

  //Add DHT11 data

  frame += F("humidity=");
  frame += dhtInfo->humidity + STR_COMMA;
  frame += F("temperature=");
  frame += dhtInfo->temperature + STR_COMMA;

  // Add Plantower data

  frame += F("pm1=");
  frame += plantowerInfo->pm1 + STR_COMMA;
  frame += F("pm25=");
  frame += plantowerInfo->pm25 + STR_COMMA;
  frame += F("pm10=");
  frame += plantowerInfo->pm10;

  return frame;

}

void checkConnectedModules(unsigned long timeout) {

  DMSG_STR("starting to check.......");
  unsigned long start = millis();
  DMSG_STR("value starting millis....."+start);
  wdt_disable();

  /*if(plantowerSensor.sensorOk()) {

    DMSG_STR("hell yes");
    }else{
    DMSG_STR("sensor not ready");
    }

    delay(timeout);
    DMSG_STR("reached timeout");*/
  do {

    plantowerSensor.handlePlantowerData();
    if(plantowerSensor.sensorOk()) {
      system_connected = true;
      DMSG_STR("sensor  CHECKEDDDDDDDDDDDD");
      break;

    }else{
      DMSG_STR("not plantowerOK");
    }

    DMSG_STR("checked for connected sensors");


  }while(millis() - start < timeout);
  wdt_enable(1000);
}
