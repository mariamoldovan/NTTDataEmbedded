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
  char dateDist[5] = {2, 231, 2, 18, 17};
  (*blue).trimiteDateRaspberry(dateDist);
 delay(1000000);
  //(*blue).primesteDate();
}
