#define FS_NO_GLOBALS
//https://github.com/esp8266/Arduino/issues/1524
#ifndef APP
#define APP
#include "app.h"
#endif

#include <ArduinoJson.h>

/*
 * Micro SD Shield - Datalogger
 *
 * This example shows how to log data from an analog sensor
 * to an SD card using the SD library.
 *
 * The WeMos Micro SD Shield uses:
 * D5, D6, D7, D8, 3V3 and G
 *
 * The shield uses SPI bus pins:
 * D5 = CLK
 * D6 = MISO
 * D7 = MOSI
 * D8 = CS
 *
 * The WeMos D1 Mini has one analog pin A0.
 *
 * The SD card library uses 8.3 format filenames and is case-insensitive.
 * eg. IMAGE.JPG is the same as image.jpg
 *
 * created  24 Nov 2010
 * modified 9 Apr 2012 by Tom Igoe
 *
 * This example code is in the public domain.
 * https://github.com/esp8266/Arduino/blob/master/libraries/SD/examples/Datalogger/Datalogger.ino
 */
#include <SPI.h>
#include <SD.h>

const int chipSelect = D8;

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

fs::FSInfo fs_info;


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

/******************************************************************************
 * FunctionName : SecondsSince1900
 * Description  : Returns input date in seconds since 00:00 GMT JAN 01 1900 
 *                			No range verification! use with care!
 * Parameters   : year > 2015, month (1-12), day (1-31), hour (0-23), minute (0-59), second (0-59)
 * Returns      : Integer 32 bits 
 *******************************************************************************/
// Epoch time desde el 01-01-1970
// Adaptarla para que sea epoch time
uint32 SecondsSince1970(uint16 year, uint8 month, uint8 day, uint8 hour, uint8 minute, uint8 second)
{
	uint16 counter;
	uint16 yearcount,leapdays;
	uint32 daysfromepoch;
	uint16 daysUpToMonth[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	uint16 daysUpToMonthLeapYear[12] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

	// integer years from epoch 
	yearcount=year-1970;

	// get leapdays from epoch
	leapdays=0;
	for(counter=1970;counter<year;counter++)
	{
		if( ( ( counter%4==0) && (counter%100!=0)) || (counter%400==0 ) )         
		{
			leapdays++;
		}	
	}
	
	
	
	if( ( ( year%4==0) && (year%100!=0)) || (year%400==0 ) )         
	{
		daysfromepoch = yearcount*365 + leapdays + daysUpToMonthLeapYear[month-1]+(day-1);
	}
	else
	{
		daysfromepoch = yearcount*365 + leapdays + daysUpToMonth[month-1]+(day-1);
	}

	return( (daysfromepoch*86400)+(hour*3600)+(minute*60)+second );
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

        post2Influx("http://aqa.unloquer.org:8086/write?db=mydb&precision=s'", line2send);
        Serial.println(line2send);

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
  fs::Dir dir = SPIFFS.openDir("/");
  while (dir.next()) {
    Serial.print(dir.fileName());
    fs::File f = dir.openFile("r");
    Serial.println(f.size());
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("\nStarting ...");

  // Serial.print("Initializing SD card...");

  // // see if the card is present and can be initialized:
  // if (!SD.begin(chipSelect)) {
  //   Serial.println("Card failed, or not present");
  //   // don't do anything more:
  //   return;
  // }
  // Serial.println("card initialized.");

  SPIFFS.begin();
  setupLeds();
  setupGPS();
  setupPlantower();
  setupDHT11();
  //fs_delete_file();  // descomentar para borrar la memoria
  fs_info_print();
  //fs_list_files();

  if (drd.detectDoubleReset()) {
    Serial.println("Connecting to network ...");
    setupWifi();
    readLog();
    // syncLog();
  }
}

void savesdcard();

void loop() {
  gps = getGPSData();
  plantower = getPlantowerData();
  dht11 = getDHT11Data();

  if(plantower.ready) {
    plantowerData = plantower;
    if(plantowerData.ready) {
      ledParticulateQuality(plantowerData);
      if(gps.ready) {
        save();
      }
    }
  }

  drd.loop();
}

void savesdcard() {
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    String frame = csvFrame();
    dataFile.println(frame);
    dataFile.close();
    // print to the serial port too:
    Serial.println(frame);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

void save() {
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);

  fs::File file = SPIFFS.open(filename, "a+");        // Open a file for reading and writing (appending)
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

  // Add DHT11 data
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
