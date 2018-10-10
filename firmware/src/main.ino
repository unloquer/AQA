#include <app.h>


using namespace aqaGps;
using namespace aqaPlantower;
using namespace aqaDht;
using namespace aqaWifi;
using namespace aqaLeds;
//gps configuration
SoftwareSerial gpsSerial(GPS_RX,GPS_TX);
AqaGps gpsSensor(gpsSerial);
// plantower pm configuration
SoftwareSerial plantower_serial(P_TOWER_RX, P_TOWER_TX);
AqaPlantower plantowerSensor(plantower_serial);
// DHT
AqaDht dhtSensor;
// Wifi
AqaWifi the_wifi(5000);// aqawifi(int i) initializes a ticker callback. doesnt work with ping
//--------- variables to point to the data of the sensors
gpsData * gpsInfo;
plantowerData * plantowerInfo;
dht11Data * dhtInfo; 

//---leds
AqaLeds aqa_leds;

const String SENSOR_ID = "estacion floresta"; // change with your id
int INIT = 1;
// const int DEBUG = 0;
const int READ_LOG = 1;
const int DELETE_LOG = 1;
const int SEND_LOG = 0;
const int SEND_RECORD = 1;

DoubleResetDetector drd(DRD_TIMEOUT, DRD_ADDRESS);

FSInfo fs_info;
String readPosition();
void savePosition(String position);
void readLog();

void fs_info_print() {
  SPIFFS.info(fs_info);
  DMSG("totalBytes ");DMSG_STR(fs_info.totalBytes);
  DMSG("usedBytes ");DMSG_STR(fs_info.usedBytes);
  DMSG("blockSize ");DMSG_STR(fs_info.blockSize);
  DMSG("pageSize ");DMSG_STR(fs_info.pageSize);
  DMSG("maxOpenFiles ");DMSG_STR(fs_info.maxOpenFiles);
  DMSG("maxPathLength ");DMSG_STR(fs_info.maxPathLength);
}
void fs_delete_file() {
  //SPIFFS.format(); // descomentar esta línea si hay algo que no se puede borrar en la memoria flash
  // Assign a file name e.g. 'names.dat' or 'data.txt' or 'data.dat' try to use the 8.3 file naming convention format could be 'data.d'
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);

  if (SPIFFS.exists(filename)) SPIFFS.remove(filename); // First blu175.mail.live.com in this example check to see if a file already exists, if so delete it
}
void deleteLog() {
  DMSG_STR("Deleting log");
  SPIFFS.remove("datalog.txt");
}
void sendLog() {
  String url = "http://192.168.0.18:3000/api/v0/air.csv";
  aqaHttp::postCsvFile(url, "log");
}
void syncLog() {
  if(!INIT) { return; }
  INIT = 0;

  if(READ_LOG) {
    readLog();
  }

  if(SEND_LOG) {
    sendLog();
  }

  if(DELETE_LOG) {
    deleteLog();
  }
}
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
void fs_list_files(){
  Dir dir = SPIFFS.openDir("/");
  while (dir.next()) {
    DMSG(dir.fileName());
    File f = dir.openFile("r");
    DMSG_STR(f.size());
  }
}
void readLog() {
  DMSG_STR("Reading log ...");
  fs::File file = SPIFFS.open("datalog.txt", "r");
  if(readPosition().toInt() > 0) file.seek(readPosition().toInt(),SeekSet);
  DMSG_STR("Initial position " + readPosition());
  String line = "", line2send;
  int linesCnt = 0;
  String device,lat,lng,date,hour,altitude,course,speed,humidity,temperature,pm1,pm25,pm10;
  String y,m,d,h,mi,s;
  int Year,Month,Day,Hour,Minute,Second;
  if (!file) DMSG_STR("file open failed");  // Check for errors
  while (file.available()) {
    yield();
    wdt_disable();
    // Read all the data from the file and display it

    char c = file.read();
    int field;
    if(c == '\r') {
      if(!line.endsWith("NULL")) {
        //pm10
        pm10 = line;
        //DMSG("pm10=");DMSG(line);DMSG(" ");DMSG_STR(field);

        tmElements_t t;
        time_t t_of_day;
        t.Year = CalendarYrToTm(Year);
        t.Month = Month;
        t.Day = Day;
        t.Hour = Hour;
        t.Minute = Minute;
        t.Second = Second;
        //t.tm_isdst = -1;        // Is DST on? 1 = yes, 0 = no, -1 = unknown
        t_of_day = makeTime(t);
        //t_of_day = mktime(&t);

        linesCnt ++;

        line2send += device + STR_COMMA + F("id=") + device + F(" lat=") + lat + F(",lng=") + lng + F(",altitude=") + altitude + F(",course=") + course + F(",speed=") + speed + F(",humidity=") + humidity + F(",temperature=") + temperature + F(",pm1=") + pm1 + F(",pm25=") + pm25 + F(",pm10=") + pm10 + F(" ") + t_of_day + F("\n");

        if(linesCnt == 40) { // que pasa si la última tanda tiene menos de 50 líneas??
          DMSG_STR(linesCnt);
          //DMSG(line2send);
          // DMSG_STR("Free Memory: "+String(ESP.getFreeHeap()));
          savePosition((String) file.position());
          DMSG_STR("File position "+ String(file.position())); // La posición de memoria donde va leyendo el archivo, almacenarla para continuar desde acá
          aqaHttp::post2Influx("http://aqa.unloquer.org:8086/write?db=aqamobile&precision=s", line2send);
          line2send = "";
          linesCnt = 0;
        }
      }

      // Discard the \n, which is the next byte

      field = 0;
      file.read();
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
          //DMSG("date=");DMSG(line);DMSG(" ");DMSG_STR(field);
          y = getValue(line, '/', 2);
          d = getValue(line, '/', 1);
          m = getValue(line, '/', 0);
          Year=y.toInt();
          Month=m.toInt();
          Day=d.toInt();

          break;
        case 4:
          //hour
          hour = line;
          //DMSG("hour=");DMSG(line);DMSG(" ");DMSG_STR(field);
          s = getValue(line, ':', 2);
          mi = getValue(line, ':', 1);
          h = getValue(line, ':', 0);
          Hour = h.toInt();
          Minute = mi.toInt();
          Second = s.toInt();
          break;
        case 5:
          //altitude
          altitude = line;
          //DMSG("altitude=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 6:
          //course
          course = line;
          //DMSG("course=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 7:
          //speed
          speed = line;
          //DMSG("speed=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 8:
          //humidity
          humidity = line;
          //DMSG("humidity=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 9:
          //temperature
          temperature = line;
          //DMSG("temperature=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 10:
          //pm1
          pm1 = line;
          //DMSG("pm1=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 11:
          //pm25
          pm25 = line;
          //DMSG("pm25=");DMSG(line);DMSG(" ");DMSG_STR(field);
          break;
        case 12:
          //pm10
          pm10 = line;
          //DMSG("pm10=");DMSG(line);DMSG(" ");DMSG_STR(field);
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

void setup() {

  Serial.begin(115200);


  gpsSerial.begin(GPS_BAUDS);
  plantower_serial.begin(P_BAUDS);
  dhtSensor.setup();
  aqa_leds.setupLeds();

  DMSG_STR("\nStarting ...");

  SPIFFS.begin();
  // point to the right addresses :3
  dhtInfo = dhtSensor.getDhtData();
  plantowerInfo = plantowerSensor.getPlantowerData();
  gpsInfo = gpsSensor.getGpsData();
  fs_info_print();
  //set up networking

#ifdef MOBILE
  DMSG_STR("MOVIL");
  if(drd.detectDoubleReset()) {
    DMSG_STR("connecting to network...");

    the_wifi.init_connections();
    readLog();
    fs_delete_file();
    savePosition("0");
  }
#else
  DMSG_STR("FIJO");
  the_wifi.init_connections();
#endif

}


void loop() {


  gpsSensor.handleGpsData();
  plantowerSensor.handlePlantowerData();
  dhtSensor.handleDhtData();
  yield();
  the_wifi.check_connections();

  if( gpsSensor.sensorOk() && plantowerSensor.sensorOk() && dhtSensor.sensorOk() && the_wifi.internetOk() ) 
  {
    //ready to send to the server

    DMSG_STR("ready to SAVE/UPLOAD");

  }else {
  DMSG("got the info from pointer   ");
  DMSG_STR(dhtInfo->temperature);

    DMSG("gps:  ");
    DMSG(gpsSensor.sensorOk());
    DMSG("internet:  ");
    DMSG(the_wifi.internetOk());
    DMSG("plantower:  ");
    DMSG(plantowerSensor.sensorOk());
    DMSG("dht :  ");
    DMSG_STR(dhtSensor.sensorOk());
 }
 yield();
}




String readPosition() {
  char filename [] = "position.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  File file = SPIFFS.open(filename, "r");
  if (!file) {
    DMSG_STR("file open failed");   // Check for errors
    return "-1";
  }
  String p = file.readString();
  return p;
}

void savePosition(String position) {
  char filename [] = "position.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  File file = SPIFFS.open(filename, "w+");
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
  File file = SPIFFS.open(filename, "a+");        // Open a file for reading and writing (appending)
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
     "id","lat","lng","date","time","altitude","course","speed","humidity",
     "temperature","pm1","pm25","pm10"
  */

  // First datum is the sensor_id
  String frame = SENSOR_ID + STR_COMMA;

  // Add GPS data
  char strlat[25],strlng[25];
  dtostrf(gpsInfo->lat, 3, 6, strlat);
  dtostrf(gpsInfo->lng, 3, 6, strlng);

  frame += strlat + STR_COMMA;
  frame += strlng + STR_COMMA;
  frame += gpsInfo->epoch_time + STR_COMMA; //refactored to epoch time 
//  frame += gps.time + STR_COMMA;
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
  frame += strlat + STR_COMMA;
  //frame += 6.27 + STR_COMMA; // hard coded latitude lat 
  frame += F("lng=");
  frame += strlng + STR_COMMA;
  //frame += -75.62    + STR_COMMA;// hard coded longitude lng
  //frame += gps.date + STR_COMMA;
  //frame += gps.time + STR_COMMA;
  frame += F("altitude=");
  frame += gpsInfo->altitude + STR_COMMA;
  frame += F("course=");
  frame += gpsInfo->course + STR_COMMA;
  frame += F("speed=");
  frame += gpsInfo->speed + STR_COMMA;

  //Add DHT11 data
  //if
  frame += F("humidity=");
  frame += dhtInfo->humidity + STR_COMMA;
  frame += F("temperature=");
  frame += dhtInfo->temperature + STR_COMMA;
  // } else {
  //   frame += "humidity=" + STR_NULL + STR_COMMA + "temperature=" + STR_NULL + STR_COMMA;
  // }

  // Add Plantower data
  // if
  frame += F("pm1=");
  frame += plantowerInfo->pm1 + STR_COMMA;
  frame += F("pm25=");
  frame += plantowerInfo->pm25 + STR_COMMA;
  frame += F("pm10=");
  frame += plantowerInfo->pm10;
  // } else {
  //   frame += "pm1=" + STR_NULL + STR_COMMA + "pm25=" + STR_NULL + STR_COMMA + "pm10=" + STR_NULL;
  // }

  return frame;
}


