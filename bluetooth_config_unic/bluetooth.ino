//Test Bluetooth
#include "Bluetooth.h"


uint8_t pini[] = {5, 6};
Bluetooth *blue = Bluetooth::getInstance(pini, 9600);
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("de la Rasp");
  char dateDist[5] = {53, 33, 123, 133, 100};
  (*blue).trimiteDateRaspberry(dateDist, 0);
  unsigned long time;
  time = millis(); 
  Serial.print("Time :");
  Serial.print(time);
  Serial.println();
  //uint16_t dist = (*blue).primesteDateRaspberry();
  //Serial.println("\t"+dist);
  //(*blue).trimiteDateRaspberry(dateDist, 1);
  ////delay(1000);
}
