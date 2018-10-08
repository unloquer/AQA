#pragma once 
#ifndef _AQA_WIFI_H
#define _AQA_WIFI_H

#include<constants_defines.h>
#include <Arduino.h>
#include <Ticker.h>
#include <ESP8266WiFi.h>
//#include <ESP8266Ping.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
namespace aqaWifi {


  class AqaWifi {

    public:
      AqaWifi(int duration);
      void init_connections();
      void check_connections();
      bool internetOk(void);

    private:

      int _duration;
      bool _internet_connected;
      bool _router_connected;

//      void configModeCallback (WiFiManager *w_manager);
      Ticker connect_check_dispatcher;
      WiFiManager my_wifiManager;




  };
}

#endif

