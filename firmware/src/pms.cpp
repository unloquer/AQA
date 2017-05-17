#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <FS.h>
#include <Wire.h>

#include <ESP8266HTTPClient.h>
HTTPClient http;

/*
  LED Indicator config
*/
// https://github.com/FastLED/FastLED/wiki/ESP8266-notes
#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <FastLED.h>

// Pines 16 y 14 no sirven para la librería fastled

#define NUM_LEDS 2
#define DI 4
#define CI 2
CRGB leds[NUM_LEDS];


/*
  GPS connection:
  GPS GND --> ESP GND
  GPS Vcc --> ESP 3v3
  GPS Tx  --> ESP gpio12 (softserial Rx)
*/

TinyGPSPlus gps;
FSInfo fs_info;
static const int gpsRXPin = 13, gpsTXPin = 7;
//static const int gpsRXPin = 16, gpsTXPin = 7;
static const uint32_t GPSBaud = 9600;
SoftwareSerial ss(gpsRXPin, gpsTXPin);

static const int pmsRXPin = 12, pmsTXPin = 6;
//static const int pmsRXPin = 0, pmsTXPin = 6;
static const uint32_t PMSBaud = 9600;
SoftwareSerial pms(pmsRXPin,pmsTXPin);

//sensor de humedad
/*
  DHT 1 -> ESP 3v3
  DHT 2 -> ESP gpio13 -> R4.7K(amarillo, morado, rojo) -> ESP 3v3
  DHT 3 -> NC
  DHT 4 -> ESP GND
*/
#include "DHT.h"
#define DHTPIN 5     // what pin we're connected to
//#define DHTPIN 4

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

/*
  Sensor Plantower
 */
#define LENG 23   //0x42 + 23 bytes equal to 24 bytes -> 
//#define LENG 31   //0x42 + 31 bytes equal to 32 bytes
unsigned char buf[LENG];

int PM01Value=0;          //define PM1.0 value of the air detector module
int PM2_5Value=0;         //define PM2.5 value of the air detector module
int PM10Value=0;         //define PM10 value of the air detector module

char checkValue(unsigned char *thebuf, char leng) {
  char receiveflag=0;
  int receiveSum=0;

  for(int i=0; i<(leng-2); i++){
    receiveSum=receiveSum+thebuf[i];
  }
  receiveSum=receiveSum + 0x42;

  if(receiveSum == ((thebuf[leng-2]<<8)+thebuf[leng-1]))  //check the serial data 
    {
      receiveSum = 0;
      receiveflag = 1;
    }
  return receiveflag;
}

int transmitPM01(unsigned char *thebuf) {
  int PM01Val;
  PM01Val=((thebuf[3]<<8) + thebuf[4]); //count PM1.0 value of the air detector module
  return PM01Val;
}

//transmit PM Value to PC
int transmitPM2_5(unsigned char *thebuf) {
  int PM2_5Val;
  PM2_5Val=((thebuf[5]<<8) + thebuf[6]);//count PM2.5 value of the air detector module
  return PM2_5Val;
}

//transmit PM Value to PC
int transmitPM10(unsigned char *thebuf) {
  int PM10Val;
  PM10Val=((thebuf[7]<<8) + thebuf[8]); //count PM10 value of the air detector module  
  return PM10Val;
}

float get_termperature() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    //Serial.println("Failed to read from DHT sensor!");
    return -1;
  }
  return t;
}

float get_humidity() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read humidity
  float h = dht.readHumidity();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h)) {
    //Serial.println("Failed to read from DHT sensor!");
    return -1;
  }
  //Serial.print("Humidity: ");
  //Serial.print(h);

  return h;
}

void fs_info_print() {
  SPIFFS.info(fs_info);
  Serial.print("totalBytes ");Serial.println(fs_info.totalBytes);
  Serial.print("usedBytes ");Serial.println(fs_info.usedBytes);
  Serial.print("blockSize ");Serial.println(fs_info.blockSize);
  Serial.print("pageSize ");Serial.println(fs_info.pageSize);
  Serial.print("maxOpenFiles ");Serial.println(fs_info.maxOpenFiles);
  Serial.print("maxPathLength ");Serial.println(fs_info.maxPathLength);
}

long fs_total_space() {
  SPIFFS.info(fs_info);
  return fs_info.totalBytes;
  Serial.print("usedBytes ");Serial.println(fs_info.usedBytes);
}

long fs_available_space() {
  SPIFFS.info(fs_info);
  return fs_info.usedBytes;
}

static void smartdelay(unsigned long ms) {
  unsigned long start = millis();
  do
    {
      while (ss.available())
        gps.encode(ss.read());
    } while (millis() - start < ms);

}

void fs_delete_file() {
  // Assign a file name e.g. 'names.dat' or 'data.txt' or 'data.dat' try to use the 8.3 file naming convention format could be 'data.d'
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);

  if (SPIFFS.exists(filename)) SPIFFS.remove(filename); // First blu175.mail.live.com in this example check to see if a file already exists, if so delete it
}

void fs_read_file() {
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  File myDataFile = SPIFFS.open(filename, "a+");        // Open a file for reading and writing (appending)
  myDataFile = SPIFFS.open(filename, "r");              // Open the file again, this time for reading
  if (!myDataFile) Serial.println("file open failed");  // Check for errors
  while (myDataFile.available()) {
    Serial.write(myDataFile.read());                    // Read all the data from the file and display it
  }
  myDataFile.close();
}

void fs_read_line_by_line() {
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  File myDataFile = SPIFFS.open(filename, "a+");        // Open a file for reading and writing (appending)
  String l_line = "";
  myDataFile = SPIFFS.open(filename, "r");              // Open the file again, this time for reading
  if (!myDataFile) Serial.println("file open failed");  // Check for errors
  while (myDataFile.available()) {
    //A inconsistent line length may lead to heap memory fragmentation
    l_line = myDataFile.readStringUntil('\n');
    if (l_line == "") //no blank lines are anticipated
      break;
    //parse l_line here
    Serial.println(l_line);     // Read all the data from the file and display it
  }
  myDataFile.close();
}

void fs_write_frame(String frame) {
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  File myDataFile = SPIFFS.open(filename, "a+");        // Open a file for reading and writing (appending)
  if (!myDataFile)Serial.println("file open failed");   // Check for errors

  myDataFile.println(frame);
  myDataFile.close();
}

bool gps_data_available() {
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
    Serial.println("ENTRA");
    if (gps.encode(ss.read()))
      //displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
    {
      Serial.println(F("No GPS detected: check wiring."));
      while(true);
    }
}

// void gps_get_valid_position() {
//   //gps.f_get_position(&flat, &flon, &age);
// }
String slash = "/";
String comma = ",";
String invalid = "INVALID";
String cero = "0";
String dospuntos = ":";
String punto = ".";

void read_pms_data() {
  if(pms.find(0x42)){    //start to read when detect 0x42
    pms.readBytes(buf,LENG);
    // for(int i=0; i< LENG; i++) {
    //   Serial.print(buf[i]);Serial.print("|");
    // }
    // Serial.println();


    if(buf[0] == 0x4d){
      if(checkValue(buf,LENG)){
        PM01Value=transmitPM01(buf); //count PM1.0 value of the air detector module
        PM2_5Value=transmitPM2_5(buf);//count PM2.5 value of the air detector module
        PM10Value=transmitPM10(buf); //count PM10 value of the air detector module 
      }
    }
  }
}

int server_request() {

  String url = "http://104.131.1.214:3000/api/SensorEvents";
  http.begin(url);
  http.addHeader("Content-Type", "application/csv");
  //http.addHeader("X-Auth-Token", AUTH_TOKEN);
  int content_length =0;

  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);
  File myDataFile = SPIFFS.open(filename, "a+");        // Open a file for reading and writing (appending)
  content_length = myDataFile.size();

  http.addHeader("Content-Length", String(content_length));
  int httpCode = http.POST((String) myDataFile);
  if(httpCode > 0) {
    String payload = http.getString();
    Serial.println(payload);
  }
  else {
    Serial.print("[HTTP] failed, error: ");Serial.println(http.errorToString(httpCode).c_str());
  }
  http.end();

  return httpCode;
}


void setup() {
  Serial.begin(115200); // Cambia para conectar directamente el PMS, hay que desconectarlo para subir un programa
  Serial.println("Starting...");
  ss.begin(GPSBaud);
  pms.begin(PMSBaud);
  pms.setTimeout(1500);    //set the Timeout to 1500ms, longer than the data transmission periodic time of the sensor

  SPIFFS.begin();

  dht.begin();

  FastLED.addLeds<LPD8806, DI, CI>(leds, NUM_LEDS);

  delay(500);
  //fs_read_file();
  fs_info_print();
}

void loop()
{
  // Read humidity
  float h = get_humidity();
  // Read temperature as Celsius
  float t = get_termperature();
  //GPS
  wdt_disable();
  smartdelay(5000);
  //displayInfo();
  String frame;

  if (gps.location.isValid())
    {
      char outstrlat[25],outstrlng[25];
      dtostrf(gps.location.lat(), 3, 6, outstrlat);
      dtostrf(gps.location.lng(), 3, 6, outstrlng);
      frame +=  outstrlat + comma + outstrlng + comma;
    }
  else
    {
      frame += invalid+comma+invalid+comma;
    }

  if (gps.date.isValid())
    {
      frame += gps.date.month() + slash + gps.date.day() + slash + gps.date.year()+ comma;
    }
  else
    {
      frame += invalid+comma;
    }

  if (gps.time.isValid())
    {
      if (gps.time.hour() < 10) frame += cero;
      frame += gps.time.hour();
      frame += dospuntos;
      if (gps.time.minute() < 10) frame += cero;
      frame += gps.time.minute();
      frame += dospuntos;
      if (gps.time.second() < 10) frame += cero;
      frame += gps.time.second();
      frame += punto;
      if (gps.time.centisecond() < 10) frame += cero;
      frame += gps.time.centisecond() + comma;
    }
  else
    {
      frame += invalid+comma;
    }


  if(gps.altitude.isValid()) {
    frame += gps.altitude.meters() + comma;
  }
  else
    {
      frame += invalid+comma;
    }

  if(gps.course.isValid())
    {
      frame += gps.course.deg() + comma;
    }
  else {
    frame += invalid+comma;
  }

  if(gps.speed.isValid()){
    frame += gps.speed.kmph() + comma;
  }
  else {
    frame += invalid + comma;
  }

  frame += h +comma + t +comma;

  read_pms_data();

  if(PM2_5Value < 13 ) leds[0] = leds[1] =CRGB::Red;
  if(PM2_5Value >= 13 && PM2_5Value < 35) leds[0] = leds[1] =CRGB::Yellow;
  if(PM2_5Value >= 35 && PM2_5Value < 55) leds[0] = leds[1] =CRGB::OrangeRed;
  if(PM2_5Value >= 55) leds[0] = leds[1] =CRGB::Green;
  FastLED.show();
  //delay(1000);
  //leds[0] = leds[1] = CRGB::Black;
  //FastLED.show();

  frame += PM01Value + comma + PM2_5Value + comma + PM10Value;
  Serial.println(frame);
  fs_write_frame(frame);
  //fs_delete_file();

  wdt_enable(1000);
}
