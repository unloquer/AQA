#include "app.h"
DHT11Data dht11;
SSD1306 display(0x3c, D4, D2);
void setupdisplay(){
  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
}

void displayTempHumid(){
  dht11 = getDHT11Data();
  float humidity = dht11.humidity;
  float temperature = dht11.temperature;
  display.clear();
  display.drawString(0, 0, "Humidity: " + String(humidity) + "%\t");
  display.drawString(0, 16, "Temp: " + String(temperature) + "C");

}
void viewdisplay(){
  displayTempHumid();
  display.display();
  delay(2000);
}
