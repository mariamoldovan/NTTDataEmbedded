#ifndef BT
#define BT

#include "Arduino.h"
#include <SoftwareSerial.h> //Serial library

class Bluetooth
{
  public:
    static Bluetooth* getInstance(int piniConfig[], int baundRate);
    bool distrugeBluetooth();
    void trimiteDate();
    void primesteDate();
    void decodareFrame();
    
  private:
    int _dateTrimise;
    int pini[];
    static Bluetooth* INSTANCE;
    SoftwareSerial *bt;

    Bluetooth(int piniconfig[], int baund);
    void construireFrame();
    void init();
    void dinit();
  
};



#endif
