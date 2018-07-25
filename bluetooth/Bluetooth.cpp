//This sketch shows how to connect to a bluetooth device
// Arduino -> bluetooth
// Used with Android BlueTerm app

#include <SoftwareSerial.h> //Serial library
#include "Arduino.h"
#include "Bluetooth.h"

/**
   Arduino connection HC-05 connection:
   HC-05  | Arduino
   TX     | 5
   RX     | 6
*/

Bluetooth* Bluetooth::INSTANCE = 0;

Bluetooth::Bluetooth(uint16_t piniConfig[], uint16_t baund)
{
  bt = new SoftwareSerial (piniConfig[0], piniConfig[1]); //RX, TX (Switched on the Bluetooth - RX -> TX | TX -> RX)
  uint16_t btdata; // the data given from the computer
  (*bt).begin(baund);
  (*bt).println ("Tramsmission start!");
  Serial.print("%%start##");
}

Bluetooth* Bluetooth::getInstance(uint16_t piniConfig[], uint16_t baundRate)
{
  if (INSTANCE == 0)
  {
    INSTANCE = new Bluetooth(piniConfig, baundRate);
  }
  return INSTANCE;
}

void Bluetooth::trimiteDateRaspberry(uint8_t data[5])
{
  String mesaj = "";
  uint8_t trimiteDate[9];
  construireFrame(data, trimiteDate);
  String transmite = trimiteDate;
  (*bt).println ("s a trimis");
  (*bt).println(""+transmite);
  (*bt).print("\n");
  Serial.print(transmite+"\n");
  (*bt).println ("s-a trimis un pachet");
  (*bt).println("\n");
  delay (200); //prepare for data (2s)
}

void Bluetooth::primesteDateRaspberry()
{
  pinMode(LED_BUILTIN, OUTPUT);
  uint16_t btdata;
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

void Bluetooth::construireFrame(uint8_t data[], uint8_t* frame)
{
 // uint8_t frame[9];
  uint8_t startFrame = 'r';
  uint8_t endFrame = 'c';
  uint8_t detectParitate = 0;
  frame[0] = startFrame;

  for (int i = 0; i < 4; i++)
  {
    frame[i + 1] = data[i];
    if (paritate(data[i])) bitWrite(detectParitate, 0, 1);
    detectParitate << 1;
  }

  detectParitate >> 1;
  frame[6] = detectParitate;
  frame[7] = endFrame;
  frame[8] = '\0';

  //return frame;
}

uint16_t Bluetooth::paritate(uint8_t dist)
{
  uint16_t sumaBiti = 0;
  while (dist) {
    if (bitRead(dist, 0)) sumaBiti++;
    dist >> 1;
  }
  if ((sumaBiti % 2) == 0) return 0;
  return 1;
}

