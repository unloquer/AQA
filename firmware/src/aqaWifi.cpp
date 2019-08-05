#include <aqaWifi.h>
#include <ESP8266Ping.h>

// AsyncWebServer server(80);
// DNSServer dns;
// AsyncWiFiManager my_wifiManager(&server, &dns);


// void configModeCallback(AsyncWiFiManager *w_manager) {

//   w_manager->setConfigPortalTimeout(240);
//   w_manager->setTimeout(120);
//   DMSG_STR("Entered config mode");
//   DMSG_STR(WiFi.softAPIP());
//   // print the ssid that we should connect to to configure the ESP8266
//   DMSG("Created config portal AP ");
//   DMSG_STR(w_manager->getConfigPortalSSID());
// }

AqaWifi::AqaWifi(int duration) : _duration(duration) {


//connect_check_dispatcher.attach_ms(_duration,std::bind(&AqaWifi::check_connections, this));

}
/*AqaWifi::AqaWifi() {

}*/
void AqaWifi::check_connections() {

  DMSG_STR("checking connections");
 //  unsigned long start = millis();
 // wdt_disable();
 // do {
/*    while(Ping.ping("google.com")){
    //Ping.ping("google.com");
      DMSG("pinged google in  :");
      DMSG_STR(Ping.averageTime());
      yield();
     break;
    }*/
  if(!WiFi.isConnected()) {
    _router_connected = false;
    _internet_connected = false;

  }else {
    _router_connected = true;
  }
  if(_router_connected && Ping.ping("www.google.com")){
    DMSG("pinguiao: ");
      DMSG_STR(Ping.averageTime());
    _internet_connected = true;
  }else{
    // something is wrong
    _internet_connected = false;
          DMSG_STR("fucking shit UNE");
  }
// delay(5000);
 // }while(millis() - start < 1000);

 // wdt_enable(1000);
/*  DMSG_STR("checking connections");
  if(!WiFi.isConnected()) {

    DMSG_STR("router is down");
    // do somethig:

  }


  // ping google 5 times 
  if(Ping.ping("www.google.com")){

    DMSG("ping to google OK");
    DMSG("AVG packet time");
    DMSG_STR(Ping.averageTime());

  }else {

    //do something
    Serial.println("i have no internet :(");
  }
  //wait 5 sgs do it again
  */ 
}

bool AqaWifi::internetOk(void) {
  return _internet_connected;
}
void feck() {
  Serial.println("address callback");
}

#ifndef FIXED_WIFI
void AqaWifi::init_connections() {
// WiFiManager  my_wifiManager;
  my_wifiManager.setAPCallback(configModeCallback);

  if(!my_wifiManager.autoConnect("AQA_estacion")) {
    delay(1000); // timeout

    DMSG_STR("failed to connect and hit timeout");
    ESP.reset();
//    delay(1000);
  }
  // you are connected either to the ap or to the internet :)
  DMSG_STR("connected...yeey :)");
  //----init server
  //  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  //       request->send(200, "text/plain", "AQA_XD");
  //   });
  //  server.on("/log", std::bind(feck));
  // server.begin();
}
#else

void AqaWifi::init_connections() {
  // // Connect to WiFi
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());

  //----init server
  // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  //                            request->send(200, "text/plain", "AQA_XD");
  //                          });
  // server.on("/log", std::bind(feck));
  // server.begin();
}
#endif
