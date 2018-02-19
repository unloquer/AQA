#include "app.h"

int INIT = 1;
const int DEBUG = 0;
const int READ_LOG = 1;
const int DELETE_LOG = 1;
const int SEND_LOG = 0;
const int SEND_RECORD = 1;

GPSData gps;
DHT11Data dht11;
PlantowerData plantower;
PlantowerData plantowerData;

FSInfo fs_info;


void fs_info_print() {
  SPIFFS.info(fs_info);
  Serial.print("totalBytes ");Serial.println(fs_info.totalBytes);
  Serial.print("usedBytes ");Serial.println(fs_info.usedBytes);
  Serial.print("blockSize ");Serial.println(fs_info.blockSize);
  Serial.print("pageSize ");Serial.println(fs_info.pageSize);
  Serial.print("maxOpenFiles ");Serial.println(fs_info.maxOpenFiles);
  Serial.print("maxPathLength ");Serial.println(fs_info.maxPathLength);
}

void fs_delete_file() {
  //SPIFFS.format(); // descomentar esta línea si hay algo que no se puede borrar en la memoria flash
  // Assign a file name e.g. 'names.dat' or 'data.txt' or 'data.dat' try to use the 8.3 file naming convention format could be 'data.d'
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);

  if (SPIFFS.exists(filename)) SPIFFS.remove(filename); // First blu175.mail.live.com in this example check to see if a file already exists, if so delete it
}

#include <DoubleResetDetector.h>

// Number of seconds after reset during which a 
// subseqent reset will be considered a double reset.
#define DRD_TIMEOUT 100

// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0

DoubleResetDetector drd(DRD_TIMEOUT, DRD_ADDRESS);
void readLog();

// void readLog() {
//   Serial.println("Reading log ...");
//   File file = SPIFFS.open("datalog.txt", "r");
//   String line = "";
//   if (!file) Serial.println("file open failed");  // Check for errors
//   while (file.available()) {
//     wdt_disable();
//     // Read all the data from the file and display it

//     char c = file.read();
//     if(c == '\r') {
//       if(!line.endsWith("NULL")) {
//         Serial.println("Posting: "+line);
//         if(SEND_RECORD) {
//           postCsv("http://45.55.34.88:3000/api/v0/air.csv", line);
//         }
//       }

//       // Discard the \n, which is the next byte
//       file.read();
//       line = "";
//     } else {
//       line += String(c);
//     }
//     wdt_enable(1000);
//   }
// }

void deleteLog() {
  Serial.println("Deleting log");
  SPIFFS.remove("datalog.txt");
}

void sendLog() {
  String url = "http://192.168.0.18:3000/api/v0/air.csv";
  postCsvFile(url, "log");
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

void fs_list_files(){
  Dir dir = SPIFFS.openDir("/");
  while (dir.next()) {
    Serial.print(dir.fileName());
    File f = dir.openFile("r");
    Serial.println(f.size());
  }
}

#include <stdio.h>
//#include <time.h>
#include <Time.h>

//https://arduino.stackexchange.com/questions/1013/how-do-i-split-an-incoming-string#1033
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void readLog() {
  Serial.println("Reading log ...");
  fs::File file = SPIFFS.open("datalog.txt", "r");
  String line = "", line2send;

  String device,lat,lng,date,hour,altitude,course,speed,humidity,temperature,pm1,pm25,pm10;
  String y,m,d,h,mi,s;
  int Year,Month,Day,Hour,Minute,Second;
  if (!file) Serial.println("file open failed");  // Check for errors
  while (file.available()) {
    wdt_disable();
    // Read all the data from the file and display it

    char c = file.read();
    int field;
    if(c == '\r') {
      if(!line.endsWith("NULL")) {
        //pm10
        pm10 = line;
        //Serial.print("pm10=");Serial.print(line);Serial.print(" ");Serial.println(field);

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

        line2send = device + STR_COMMA + "id=" + device + " lat=" + lat + ",lng=" + lng + ",altitude=" + altitude + ",course=" + course + ",speed=" + speed + ",humidity=" + humidity + ",temperature=" + temperature + ",pm1=" + pm1 + ",pm25=" + pm25 + ",pm10=" + pm10 + " "+ t_of_day;

        post2Influx("http://aqa.unloquer.org:8086/write?db=mydb&precision=s", line2send);
        Serial.println(line2send);
        Serial.println("Free Memory: "+String(ESP.getFreeHeap()));

        line2send = "";
        //Serial.println(SecondsSince1970(2017,03,22,23,00,12));

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
          //Serial.print("device=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 1:
          //lat
          lat = line;
          //Serial.print("lat=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 2:
          //lng
          lng = line;
          //Serial.print("lng=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 3:
          //date
          date = line;
          //Serial.print("date=");Serial.print(line);Serial.print(" ");Serial.println(field);
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
          //Serial.print("hour=");Serial.print(line);Serial.print(" ");Serial.println(field);
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
          //Serial.print("altitude=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 6:
          //course
          course = line;
          //Serial.print("course=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 7:
          //speed
          speed = line;
          //Serial.print("speed=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 8:
          //humidity
          humidity = line;
          //Serial.print("humidity=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 9:
          //temperature
          temperature = line;
          //Serial.print("temperature=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 10:
          //pm1
          pm1 = line;
          //Serial.print("pm1=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 11:
          //pm25
          pm25 = line;
          //Serial.print("pm25=");Serial.print(line);Serial.print(" ");Serial.println(field);
          break;
        case 12:
          //pm10
          pm10 = line;
          //Serial.print("pm10=");Serial.print(line);Serial.print(" ");Serial.println(field);
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
  Serial.println("\nStarting ...");

  SPIFFS.begin();
  setupLeds();
  setupGPS();
  setupPlantower();
  setupDHT11();
  //fs_delete_file();  // descomentar para borrar la memoria
  fs_info_print();
  //fs_list_files();

  // METER UN DEFINE MOBILE
  // if (drd.detectDoubleReset()) {
  //   Serial.println("Connecting to network ...");
  setupWifi();
  //   readLog();
  //   fs_delete_file();
  // }
  //   WiFi.mode(WIFI_AP); 
  //reportWiFi(30);
}

int i = 0;

void loop() {

  if (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    ESP.reset();
    return;
  }

  gps = getGPSData();
  plantower = getPlantowerData();
  dht11 = getDHT11Data();
    if(plantower.ready) {
      plantowerData = plantower;
      if(plantowerData.ready) {
        ledParticulateQuality(plantowerData);
        //reportWifi( plantower.pm25);
        if(gps.ready) {
          //save();
          ledParticulateQualityStreamming(plantowerData);
          String frame = influxFrame();
          Serial.println(frame);
          //post2influx("http://159.203.187.96:8086/write?db=aqaTest", frame);
          post2Influx("http://aqa.unloquer.org:8086/write?db=aqa", frame);
          i++;
        }
      }
    }
    //drd.loop();

  if(i == 200){
    ESP.reset();
    i = 0;
  }
}

void save() {
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  File file = SPIFFS.open(filename, "a+");        // Open a file for reading and writing (appending)
  if (!file) {
    Serial.println("file open failed");   // Check for errors
    return;
  }

  String frame = csvFrame();
  Serial.println(frame);
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
  dtostrf(gps.lat, 3, 6, strlat);
  dtostrf(gps.lng, 3, 6, strlng);

  frame += strlat + STR_COMMA;
  frame += strlng + STR_COMMA;
  frame += gps.date + STR_COMMA;
  frame += gps.time + STR_COMMA;
  frame += gps.altitude + STR_COMMA;
  frame += gps.course + STR_COMMA;
  frame += gps.speed + STR_COMMA;

  //Add DHT11 data
  if(dht11.ready) {
    frame += dht11.humidity + STR_COMMA;
    frame += dht11.temperature + STR_COMMA;
  } else {
    frame += STR_NULL + STR_COMMA + STR_NULL + STR_COMMA;
  }

  // Add Plantower data
  if(plantower.ready) {
    frame += plantower.pm1 + STR_COMMA;
    frame += plantower.pm25 + STR_COMMA;
    frame += plantower.pm10;
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
  String frame = SENSOR_ID + STR_COMMA + "id=" + SENSOR_ID +  STR_SPACE;

  // Add GPS data
  char strlat[25],strlng[25];
  dtostrf(gps.lat, 3, 6, strlat);
  dtostrf(gps.lng, 3, 6, strlng);
  frame += "lat=";
  frame += strlat + STR_COMMA;
  frame += "lng=";
  frame += strlng + STR_COMMA;
  //frame += gps.date + STR_COMMA;
  //frame += gps.time + STR_COMMA;
  frame += "altitude=";
  frame += gps.altitude + STR_COMMA;
  frame += "course=";
  frame += gps.course + STR_COMMA;
  frame += "speed=";
  frame += gps.speed + STR_COMMA;

  //Add DHT11 data
  //if
    frame += "humidity=";
    frame += dht11.humidity + STR_COMMA;
    frame += "temperature=";
    frame += dht11.temperature + STR_COMMA;
  // } else {
  //   frame += "humidity=" + STR_NULL + STR_COMMA + "temperature=" + STR_NULL + STR_COMMA;
  // }

  // Add Plantower data
    // if
    frame += "pm1=";
    frame += plantower.pm1 + STR_COMMA;
    frame += "pm25=";
    frame += plantower.pm25 + STR_COMMA;
    frame += "pm10=";
    frame += plantower.pm10;
  // } else {
  //   frame += "pm1=" + STR_NULL + STR_COMMA + "pm25=" + STR_NULL + STR_COMMA + "pm10=" + STR_NULL;
  // }

  return frame;
}
