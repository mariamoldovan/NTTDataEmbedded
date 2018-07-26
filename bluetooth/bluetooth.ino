//Test Bluetooth
#include "Bluetooth.h"

Bluetooth *blue;
int pini[2] = {5, 6};

void setup()
{
  blue = Bluetooth::getInstance(pini, 9600);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("\t");
  //char dateDist[5] = {88, 199, 77, 21, 98};
  //(*blue).trimiteDateRaspberry(dateDist);
  Serial.println("\t"+(*blue).primesteDateRaspberry());
  delay(1000);
}
