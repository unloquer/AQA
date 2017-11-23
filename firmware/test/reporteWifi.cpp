#include "app.h"


void reportWiFi(int pm25_value)
{
    String AP_NameString = "Partículas PM2.5 " + (String)pm25_value + " ug/m3";
      char AP_NameChar[AP_NameString.length() + 1];
    memset(AP_NameChar, AP_NameString.length() + 1, 0);
      for (int i=0; i<AP_NameString.length(); i++)
        AP_NameChar[i] = AP_NameString.charAt(i);
      WiFi.softAP(AP_NameChar, "unloquer");
  }

WiFi.mode(WIFI_AP);
setupWiFi(30);
setupWiFi(plantower.pm25);
