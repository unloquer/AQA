#pragma once
#ifndef _HTTP_HANDLER_H
#define _HTTP_HANDLER_H

#include <constants_defines.h>
#include <aqaWifi.h>
#include <StreamString.h>
#include <FS.h>
namespace aqaHttp {



      int postCsvFile(String url, String filename);
      int postCsv(String url, String csv);
      int post2Influx(String url, String load);
      String _get(String url);
      String _post(String url, String json);





}



#endif
