
#ifndef __CONFIG__
  #define __CONFIG__
  #define SD_BIN
  //#define SD_CSV





  //section contraintes 
  #if defined(SD_BIN)&&defined(SD_CSV)
    #undef SD_CSV
  #endif


  #if defined(SD_BIN)||defined(SD_CSV)
    #define SD
  #endif

#endif

