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
  char dateDist[5] = {1, 1, 1, 1, 1};
  (*blue).trimiteDateRaspberry(dateDist);
  //(*blue).primesteDate();
}
