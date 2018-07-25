//This sketch shows how to connect to a bluetooth device
// Arduino -> bluetooth
// Used with Android BlueTerm app

#include <SoftwareSerial.h> //Serial library
#include "Arduino.h"
#include "Bluetooth.h"

/**
 * Arduino connection HC-05 connection: 
 * HC-05  | Arduino
 * TX     | 5
 * RX     | 6
*/

Bluetooth* Bluetooth::INSTANCE = 0;

Bluetooth::Bluetooth(int piniConfig[], int baund)
{
  bt = new SoftwareSerial (piniConfig[0],piniConfig[1]);  //RX, TX (Switched on the Bluetooth - RX -> TX | TX -> RX)
  int btdata; // the data given from the computer
  (*bt).begin(baund);
  //(*bt).println ("Message...");
}

Bluetooth* Bluetooth::getInstance(int piniConfig[], int baundRate)
{
  if (INSTANCE == 0)
  {
    INSTANCE = new Bluetooth(piniConfig, baundRate);
  }
  return INSTANCE;
}

void Bluetooth::trimiteDate()
{
//  //String mesaj = "";
  //double x = 5120000;
//  
////  if(Serial.available() > 0) {
////    mesaj = Serial.read();
////    x = Serial.
////    (*bt).print(mesaj);
////    (*bt).print("\n");
////    (*bt).print(x);
////  }
  //(*bt).print(x);
  //(*bt).print("\n");
    (*bt).println ("1234567890");
    (*bt).println ("0987654321");
    (*bt).println ("1234653123");
 // (*bt).println ("sebi");
  //(*bt).print("\n");
  //delay (2000); //prepare for data (2s)

}

bool Bluetooth::distrugeBluetooth()
{
  return false;
}


void Bluetooth::primesteDate()
{
  pinMode(LED_BUILTIN, OUTPUT);
  int btdata;
  if ((*bt).available()) {
    btdata = (*bt).read();
    if (btdata == '1') {
      //if 1
      digitalWrite (LED_BUILTIN, HIGH);
      (*bt).println ("LED ON!");
    }
    if (btdata == '0') {
      //if 0
      digitalWrite (LED_BUILTIN, LOW);
      (*bt).println ("LED OFF!");
    }
  }
  delay (100); //prepare for data
}
void Bluetooth::decodareFrame()
{
  
}

void Bluetooth::construireFrame()
{
  
}
void Bluetooth::init()
{
  
}
void Bluetooth::dinit()
{
  
}

