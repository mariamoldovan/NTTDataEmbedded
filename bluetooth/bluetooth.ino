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
  char dateDist[5] = {88, 199, 77, 21, 98};
  (*blue).trimiteDateRaspberry(dateDist);
  //(*blue).primesteDate();
  delay(1000000);
}
