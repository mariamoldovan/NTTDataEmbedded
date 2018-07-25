//Test Bluetooth
#include "Bluetooth.h"

int pini[2] = {5, 6};
Bluetooth* blue = Bluetooth::getInstance(pini, 9600);

void setup() 
{
}
 
void loop()
{
  (*blue).trimiteDate();
  (*blue).primesteDate();
}
