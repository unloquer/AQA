#include "app.h"
#include <StreamString.h>

const uint16_t HTTP_TIMEOUT = 1000 * 60;
HTTPClient http;

// Facade to HTTP GET request
String _get(String url) {
  if (WiFi.status() == WL_CONNECTED) {
    http.begin(url);
    int httpCode = http.GET();

    // httpCode will be negative on error
    if(httpCode > 0) {
      // resource found at server
      if(httpCode == HTTP_CODE_OK) {
        return http.getString();
      }
    } else {
      DMSGf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}

String _post(String url, String json) {
  if (WiFi.status() == WL_CONNECTED) {
    http.begin(url);

    int httpCode = http.POST(json);

    if(httpCode > 0) {
      // resource found at server
      if(httpCode == HTTP_CODE_OK) {
        return http.getString();
      }
    } else {
      DMSGf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}

int postCsv(String url, String csv) {
  if (WiFi.status() != WL_CONNECTED) { return 0; }

  http.begin(url);
  http.setTimeout(HTTP_TIMEOUT);
  http.addHeader("Content-Type", "text/csv");
  http.addHeader("Content-Length", String(csv.length()));

  int httpCode = http.POST(csv);
  if(httpCode > 0) {
    String payload = http.getString();
    DMSG_STR(payload);
    DMSG_STR("CSV file sent successfully");
  } else {
    DMSG("[HTTP] failed, error: ");
    DMSG_STR(http.errorToString(httpCode).c_str());
  }

  http.end();

  return httpCode;
}

int postCsvFile(String url, String filename) {
  if (WiFi.status() != WL_CONNECTED) { return 0; }

  int content_length = 0;

  File file = SPIFFS.open(filename, "r");
  content_length = file.size();
  DMSG("Size:");
  DMSG_STR(content_length);

  String data = "";
  char *_data; 
  DMSG_STR("Reading file ...");
  while(file.available()) {
    DMSG(".");
    data += String((char)file.read());
  }
  data.toCharArray(_data, content_length);

  //uint8_t data[content_length];
  //int i = 0;
  //while(file.available()) {
  //*(data + i++) = file.read();
    //data[i++] = file.read();
    //DMSG(i);
  //}

  //*(data + i) = '\0';

  //DMSG("Count size:");
  //DMSG_STR(i);

  http.begin(url);
  http.setTimeout(HTTP_TIMEOUT);
  http.addHeader(F("Content-Type"), F("text/csv"));
  http.addHeader(F("Content-Length"), String(content_length));

  DMSG_STR("\nSending file to "+url);
  int httpCode = http.POST((uint8_t *)_data, strlen(_data));
  //int httpCode = http.POST(data);
  if(httpCode > 0) {
    String payload = http.getString();
    DMSG_STR(payload);
    DMSG_STR(F("CSV file sent successfully"));
  } else {
    DMSG(F("[HTTP] failed, error: "));
    DMSG_STR(http.errorToString(httpCode).c_str());
  }

  http.end();

  return httpCode;
}

// https://docs.influxdata.com/influxdb/v1.5/tools/api/#write
// example 3 or example 4

int post2Influx(String url, String load) {
  if (WiFi.status() != WL_CONNECTED) { return 0; }

  http.begin(url);
  http.setTimeout(HTTP_TIMEOUT); // En wifimanager con timeout no hace más intentos de conexión
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  //http.addHeader("Content-Type", "text/csv");
  http.addHeader("Content-Length", String(load.length()));

  StreamString stream;
  stream.print(load);

  size_t loadSize = load.length();
  int httpCode = -1;
  while(httpCode == -1){
    yield();
    //httpCode = http.POST(load) ;
    httpCode = http.sendRequest("POST", &stream, loadSize );
    yield();
    //https://github.com/esp8266/Arduino/issues/1872
    //int sendRequest(const char * type, Stream * stream, size_t size = 0);
    //http.writeToStream(&Serial);
    if(httpCode > 0) {
      String payload = http.getString();
      DMSG_STR(payload);
      DMSG_STR(F("load  sent successfully!"));
    } else {
      DMSG(F("[HTTP] failed, error;;;: "));
      DMSG_STR(http.errorToString(httpCode).c_str());
    }
  }

  http.end();
  return httpCode;

}

