#pragma once
#ifndef _FS_H
#define _FS_H

#include <app.h>

class filesystem {
  FSInfo fs_info;
  String readPosition();
  void savePosition(String position);
  void readLog();

  fs::File file;

  void fs_info_print() {
    SPIFFS.info(fs_info);
    DMSG("totalBytes ");DMSG_STR(fs_info.totalBytes);
    DMSG("usedBytes ");DMSG_STR(fs_info.usedBytes);
    DMSG("blockSize ");DMSG_STR(fs_info.blockSize);
    DMSG("pageSize ");DMSG_STR(fs_info.pageSize);
    DMSG("maxOpenFiles ");DMSG_STR(fs_info.maxOpenFiles);
    DMSG("maxPathLength ");DMSG_STR(fs_info.maxPathLength);
  }
  void fs_delete_file() {
    //SPIFFS.format(); // descomentar esta línea si hay algo que no se puede borrar en la memoria flash
    // Assign a file name e.g. 'names.dat' or 'data.txt' or 'data.dat' try to use the 8.3 file naming convention format could be 'data.d'
    char filename [] = "datalog.txt";                     // Assign a filename or use the format e.g. SD.open("datalog.txt",...);

    if (SPIFFS.exists(filename)) SPIFFS.remove(filename); // First blu175.mail.live.com in this example check to see if a file already exists, if so delete it
  }
  void deleteLog() {
    DMSG_STR("Deleting log");
    SPIFFS.remove("datalog.txt");
  }

  void fs_list_files(){
    Dir dir = SPIFFS.openDir("/");
    while (dir.next()) {
      DMSG(dir.fileName());
      File f = dir.openFile("r");
      DMSG_STR(f.size());
    }
  }
}

#endif
