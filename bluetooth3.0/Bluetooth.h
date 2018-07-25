#ifndef BT
#define BT

#include "Arduino.h"
#include <SoftwareSerial.h> //Serial library

class Bluetooth
{
  public:
    static Bluetooth* getInstance(uint16_t piniConfig[], uint16_t baundRate);
    void trimiteDateRaspberry(uint8_t data[5]);
    void primesteDateRaspberry();
    void decodareFrame();
    
  private:
    uint16_t pini[];
    static Bluetooth* INSTANCE;
    SoftwareSerial *bt;

    Bluetooth(uint16_t piniconfig[], uint16_t baund);
    void construireFrame(uint8_t data[], uint8_t tramnsmite[9]);
    uint16_t paritate(uint16_t dist);
  
};



#endif
