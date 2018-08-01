//Test Bluetooth
#include "Bluetooth.h"


int pini[2] = {5, 6};
Bluetooth *blue = Bluetooth::getInstance(pini, 9600);
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("de la Rasp");
  char dateDist[5] = {53, 123, 36, 23, 53};
  (*blue).trimiteDateRaspberry(dateDist, 0);
  //uint16_t dist = (*blue).primesteDateRaspberry();
  //Serial.println("\t"+dist);
  //(*blue).trimiteDateRaspberry(dateDist, 1);
  delay(1000);
}
