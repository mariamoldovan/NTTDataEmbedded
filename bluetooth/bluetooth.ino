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
  char dateDist[5] = {3, 3, 3, 3, 3};
  (*blue).trimiteDateRaspberry(dateDist, 0);
  //uint16_t dist = (*blue).primesteDateRaspberry();
  //Serial.println("\t"+dist);
  delay(1000);
}
