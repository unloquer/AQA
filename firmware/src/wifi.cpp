#include "app.h"
// WiFi parameters
const char* ssid = "HOME-4E05";
const char* password = "BDFBC14F7BC4E656";


void configModeCallback (WiFiManager *myWiFiManager) {
  DMSG_STR("Entered config mode");
  DMSG_STR(WiFi.softAPIP());
  // print the ssid that we should connect to to configure the ESP8266
  DMSG("Created config portal AP ");
  DMSG_STR(myWiFiManager->getConfigPortalSSID());
}


void setupWifi() {
  // respond to GET requests on URL /heap
  // server.on("/log", HTTP_GET, [](AsyncWebServerRequest *request){
  //   //Download index.htm
  //   request->_tempFile = SPIFFS.open("datalog.txt", "r");
  //   request->send(request->_tempFile, request->_tempFile.name(), String(), true);
  //   //AsyncWebServerResponse *response = request->beginResponse(SPIFFS, "log", String(), true);
  //   });

  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  //Download index.htm
  // respond to GET requests on URL /heap
  //WiFiManager wifiManager;
  //reset settings - for testing
  //wifiManager.resetSettings();
  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  // wifiManager.setAPCallback(configModeCallback);
  // //fetches ssid and pass and tries to connect
  // //if it does not connect it starts an access point with the specified name
  // //here  "AutoConnectAP"
  // //and goes into a blocking loop awaiting configuration
  // if(!wifiManager.autoConnect()) {
  //   DMSG_STR("failed to connect and hit timeout");
  //   //reset and try again, or maybe put it to deep sleep
  //   ESP.reset();
  //   delay(1000); 
  // }

  //if you get here you have connected to the WiFi
  // DMSG_STR("connected...yeey :)");

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());

}
