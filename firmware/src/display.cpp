#include "app.h"
PlantowerData data;
SSD1306 display(0x3c, D4, D2);
void setupdisplay(){
  display.init();
}

void displayTempHumid(){
  float humidity;
  float temperature;
  display.clear();
  display.drawString(0, 4, "Humidity: " + String(humidity) + "%\t");
  display.drawString(0, 8, "Temp: " + String(temperature) + "C");

}
void displaypm(){
  float pm1 = data.pm1;
  float pm10 = data.pm10;
  float pm25 = data.pm25;
  display.clear();
  display.drawString(0, 12, "pm1: " + String(pm1));
  display.drawString(0, 16, "pm10: " + String(pm10));
  display.drawString(0, 20, "pm25: " + String(pm25));

}
void viewdisplay(){
  displayTempHumid();
  displaypm();
  display.display();
  delay(2000);
}
