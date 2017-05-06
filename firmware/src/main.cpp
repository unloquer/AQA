#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <FS.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>

/*
  Components:
  ADS1115
  D1 1N4004 (Cathode to A0, Anode to Pin 3 for arduino - choose different pin for ESP8266)
  R1 3k3    (VDD to A0)
  R2 240R   (A0 to A1)
  R3 1K     (A1 to A2)
  R4 1K     (A2 to A3)
  Connections:
  VDD ---- +5, R1 (VDD to A0)
  GND ---- Gound
  SCL ---- Arduino Uno A5 or ESP8266 Pin 5
  SDA ---- Arduino Uno A4 or ESP8266 Pin 4
  ADDR --- GND
  ALRT --- Digital Pin 2
  A0 ----- R1, D1(Cathode to A0, Anode to Pin 3), R2
  A1 ----- R2, R3
  A2 ----- R3, R4
  A3 ----- R4, GND
 */

Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
int ledPower = 10;   //Connect 3 led driver pins of dust sensor to Arduino D6 
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float multiplier;

// SHARP SENSOR VARIABLES
int dust_analog;
float dust_voltage;  // measured
float concSHARP;     // calculated
int samples = 100;   // with delay of 100ms in between

/*
  GPS connection:
  GPS GND --> ESP GND
  GPS Vcc --> ESP 3v3
  GPS Tx  --> ESP gpio12 (softserial Rx)
 */

TinyGPSPlus gps;
FSInfo fs_info;
static const int RXPin = 12, TXPin = 7;
static const uint32_t GPSBaud = 9600;

SoftwareSerial ss(RXPin, TXPin);


//sensor de humedad
/*
  DHT 1 -> ESP 3v3
  DHT 2 -> ESP gpio13 -> R4.7K(amarillo, morado, rojo) -> ESP 3v3
  DHT 3 -> NC
  DHT 4 -> ESP GND
 */
#include "DHT.h"
#define DHTPIN 13     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

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

char checkValue(unsigned char *thebuf, char leng)
{
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

int transmitPM01(unsigned char *thebuf)
{
  int PM01Val;
  PM01Val=((thebuf[3]<<8) + thebuf[4]); //count PM1.0 value of the air detector module
  return PM01Val;
}

//transmit PM Value to PC
int transmitPM2_5(unsigned char *thebuf)
{
  int PM2_5Val;
  PM2_5Val=((thebuf[5]<<8) + thebuf[6]);//count PM2.5 value of the air detector module
  return PM2_5Val;
}

//transmit PM Value to PC
int transmitPM10(unsigned char *thebuf)
{
  int PM10Val;
  PM10Val=((thebuf[7]<<8) + thebuf[8]); //count PM10 value of the air detector module  
  return PM10Val;
}

//

void fs_read_file();

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
  //Serial.print(" Temperature: ");
  //Serial.print(t);
  //Serial.println(" *C ");

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

static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do
    {
      while (ss.available())
        gps.encode(ss.read());
    } while (millis() - start < ms);

}

void fs_write_data() {
    // Assign a file name e.g. 'names.dat' or 'data.txt' or 'data.dat' try to use the 8.3 file naming convention format could be 'data.d'
  char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);

  if (SPIFFS.exists(filename)) SPIFFS.remove(filename); // First blu175.mail.live.com in this example check to see if a file already exists, if so delete it

  File myDataFile = SPIFFS.open(filename, "a+");        // Open a file for reading and writing (appending)
  if (!myDataFile)Serial.println("file open failed");   // Check for errors

  myDataFile.println("ABCDEFGHIJKLMNOPQRSTUVWXYZ");     // Write some data to it (26-characters)
  myDataFile.println(3.141592654);
  Serial.println(myDataFile.size());                    // Display the file size (26 characters + 4-byte floating point number + 6 termination bytes (2/line) = 34 bytes)
  myDataFile.close();                                   // Close the file

  myDataFile = SPIFFS.open(filename, "r");              // Open the file again, this time for reading
  if (!myDataFile) Serial.println("file open failed");  // Check for errors
  while (myDataFile.available()) {
    Serial.write(myDataFile.read());                    // Read all the data from the file and display it
  }
  myDataFile.close();                                   // Close the file
  Serial.println(fs_available_space());
  Serial.println(fs_total_space());
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
}

void fs_write_frame(String frame)
{
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
  if(Serial.find(0x42)){    //start to read when detect 0x42
    Serial.readBytes(buf,LENG);
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

  // static unsigned long OledTimer=millis();
  // if (millis() - OledTimer >=1000)
  //   {
  //     OledTimer=millis();

  //     Serial.print("PM1.0: ");
  //     Serial.print(PM01Value);
  //     Serial.println("  ug/m3");

  //     Serial.print("PM2.5: ");
  //     Serial.print(PM2_5Value);
  //     Serial.println("  ug/m3");

  //     Serial.print("PM1 0: ");
  //     Serial.print(PM10Value);
  //     Serial.println("  ug/m3");
  //     Serial.println();
  //   }
}

void setup()
{
  Serial.begin(9600); // Cambia para conectar directamente el PMS, hay que desconectarlo para subir un programa
  Serial.println("Starting...");
  Serial.setTimeout(1500);    //set the Timeout to 1500ms, longer than the data transmission periodic time of the sensor
  ss.begin(GPSBaud);
  SPIFFS.begin();
  pinMode(ledPower,OUTPUT);
  ads.begin();
  multiplier = ads.voltsPerBit()*1000.0F;           // Gets the millivolts per bit
  dht.begin();

  //delay(500);
  //fs_read_file();
  //fs_info_print();
}

void loop()
{
  // READ SHARP SENSOR
  dust_voltage = 0;
  for (int i=0;i<samples;i++) {
    digitalWrite(ledPower,LOW); // power on the LED
    delayMicroseconds(samplingTime);
    voMeasured = 1000.0F*ads.readADC_SingleEnded_V(0); // read the dust voltage
    delayMicroseconds(deltaTime);
    digitalWrite(ledPower,HIGH); // turn the LED off
    delayMicroseconds(sleepTime);
    dust_voltage += voMeasured ;  // voltage 0-5V
    delay(100);
  }
  dust_voltage = dust_voltage / samples;

  // CALCULATE SHARP RESULTS
  concSHARP = 0.172*dust_voltage-0.1;        // density microgram/m3
  if (concSHARP > 500) concSHARP = 500;

  // PRINT SHARP DATA TO SERIAL
  //Serial.print(dust_voltage);
  //Serial.print("\t\t");
  //Serial.println(concSHARP);

  // Read humidity
  float h = get_humidity();
  // Read temperature as Celsius
  float t = get_termperature();
  //GPS
  wdt_disable();
  smartdelay(500);
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

  frame += h +comma + t +comma+ concSHARP + comma;

  read_pms_data();
  frame += PM01Value + comma + PM2_5Value + comma + PM10Value;
  //Serial.println(frame);
  fs_write_frame(frame);
  //fs_delete_file();
  wdt_enable(1000);

}
