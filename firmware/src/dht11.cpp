#include "app.h"
// inclimos la librera central que es don donde se
#define DHTPIN 12     /*// what pin we're connected to
// declara toda las funciones y librerias
// al pin al que esta conectado en gpio a el gpio12
// depende de la tarjeta el pin
// wemos https://cdn-images-1.medium.com/max/1288/1*YKc8KpAfMrlhrOLmNjdRwQ.png
// nodemcu https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwjw4MmQ1IzeAhVp0FkKHb3-B8IQjRx6BAgBEAU&url=https%3A%2F%2Fwww.teachmemicro.com%2Fnodemcu-pinout%2F&psig=AOvVaw2QNGWpnHxLAe3VN1ieW49R&ust=1539837576645757
//es recomedable dejarlo en ese pin*/
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22
//#define DHTTYPE DHT21   // DHT 21
/* solo si tienes otro dht descomentas (// esto es lo que
hace un comentario estos 2 slash // ) segun el tipo que
tengas y vuelves y comentas la otra #define DHTTYPE no
puede habaer mas de 2 sin comentar
*/
DHT dht(DHTPIN, DHTTYPE);
/*insialisamos el constructor con el se define que dht
se va a usar y el pin  el contructor originalmente es
una clase  http://c.conclase.net/curso/?cap=029*/
void setupDHT11() {
  dht.begin();
}
/*ponemos una funcion vacia que no retorna nada con la cual se insialisa el
dht apartir de ahora va a recivir datos del senor de temperatura y humeda
ahora hay que poner como los va recivir*/ 
// Initialize DHT sensor for normal 16mhz Arduino can use with the arduino ide sorry esp8266

DHT11Data getDHT11Data() {
  DHT11Data data;
  data.temperature = isnan(dht.readTemperature()) ? -1 : dht.readTemperature();
  data.humidity = isnan(dht.readHumidity()) ? -1 : dht.readHumidity();;
  data.ready = 1;
  return data;
}/*creea una funcion con el tipo de dato DHT11Data la funcion es nomrada getDHT11Data sin ningun 
parametro  creando una clase que (recoje los datos de cundo funciona y no  importa
si no funciona saldra un error)  es una variable asignada  con funciones y clases
y que duevuelva data de todas las clases  tempertura humededad y ready*/
   
