#include "app.h"
// inclimos la librera central que es don donde se
#define DHTPIN 12     /*// what pin we're connected to
// declara toda tota las funciones y librerias
// al pin al que esta contado en gpio a el gpio12
// depende de la tarjeta el pin
// wemos https://cdn-images-1.medium.com/max/1288/1*YKc8KpAfMrlhrOLmNjdRwQ.png
// nodemcu https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwjw4MmQ1IzeAhVp0FkKHb3-B8IQjRx6BAgBEAU&url=https%3A%2F%2Fwww.teachmemicro.com%2Fnodemcu-pinout%2F&psig=AOvVaw2QNGWpnHxLAe3VN1ieW49R&ust=1539837576645757
//es recomedable dejarlo en ese pin*/
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22
//#define DHTTYPE DHT21   // DHT 21

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

void setupDHT11() {
  dht.begin();
}

DHT11Data getDHT11Data() {
  DHT11Data data;
  data.temperature = isnan(dht.readTemperature()) ? -1 : dht.readTemperature();
  data.humidity = isnan(dht.readHumidity()) ? -1 : dht.readHumidity();;
  data.ready = 1;
  return data;
}
