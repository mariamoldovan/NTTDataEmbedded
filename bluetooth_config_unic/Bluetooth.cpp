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

/**
  Initializarea pinilor si a frecventei de transmisiea bitilor
*/

Bluetooth::Bluetooth(uint8_t piniConfigurare[], uint16_t baudeRate)
{
  bluetoothCommunication = new SoftwareSerial (piniConfigurare[0], piniConfigurare[1]); //RX, TX (Switched on the Bluetooth - RX -> TX | TX -> RX)
  //uint16_t btdata; // the data given from the computer
  (*bluetoothCommunication).begin(baudeRate);
}

/**
   Functia getInstance() este folosita pentru crearea unui obiect de
   tip Bluetooth. Se foloseste design patternul Singleton.
*/
Bluetooth* Bluetooth::getInstance(uint8_t piniConfigurare[], uint16_t baudeRate)
{
  if (INSTANCE == nullptr)
  {
    INSTANCE = new Bluetooth(piniConfigurare, baudeRate);
  }
  return INSTANCE;
}

/**
   Functia trimite date este utilizata pentru transmisia datelor
   pe directia Arduino-Raspberry.
   Aceasta comunicare se efectueaza prin intermediul unui dispozitiv Bluetooth.
   Pentru efectuarea comunicarii, folosim functiile din biblioteca SoftwareSerial.
*/
void Bluetooth::trimiteDateRaspberry(uint8_t distante[5], uint16_t franaDeMana)
{
  uint8_t frameTransmisie[9];

  construireFrame(distante, frameTransmisie, franaDeMana); //construirea frame-ului care urmeaza sa fie transmis

  String transmiteFrame = frameTransmisie; //conversia la tipul String
  (*bluetoothCommunication).println("\t"); //pentru asigurarea unei transmiteri complete
  (*bluetoothCommunication).println("" + transmiteFrame);
}

/**
   Functia primesteDateRaspberry este utilizata pentru primirea de date de la
   placuta Raspberry catre sistemul de parcare (placuta Arduino).
   Informatiile sunt transmise pe un byte si reprezinta valoarea
   volumului Buzzerului.
*/

uint8_t Bluetooth::primesteDateRaspberry()
{
  String dateBluetooth;
  dateBluetooth = (*bluetoothCommunication).read();
  uint8_t volumBuzzer = dateBluetooth.toInt();
  //Serial.println(volumBuzzer);
  return volumBuzzer;
}

/**
   Functia construireFrame se ocupa direct cu asamblarea componentelor unui frame.
   Structura unui frame este urmatoarea:
   -se incepe cu litera 'r' pentru marcarea inceputului de frame
   -se adauga apoi informatiile transmise prin parametrul data
   -se adauga un caracter pentru detectia erorilor; tot in acest caracter, bitul 7(cel mai din stanga)
   serveste ca 'martor' pentru frana de mana
   -se adauga caracterul 'c' pentru a marca finalul frame-ului
   -se adauga caracterul '\0' pentru a marca sfarsitul sirului
*/
void Bluetooth::construireFrame(uint8_t distante[], uint8_t* frameTransmisie, uint16_t franaDeMana)
{
  uint8_t iteratorDistante;//iterator
  uint8_t detectParitate = 0;
  frameTransmisie[0] = startFrame;

  for (iteratorDistante = 0; iteratorDistante < NR_MAX_DISTANTE; iteratorDistante++)
  {
    frameTransmisie[iteratorDistante + 1] = distante[iteratorDistante];
    detectParitate = detectParitate << 1;//se shifteza continutul pentru a adauga urmatorul bit
    if (calculParitate(distante[iteratorDistante]) == 1) 
    {
      bitWrite(detectParitate, 0, 1); //se adauga un bit de paritate pentru fiecare valoare din vectorul data
    }
  }

  if (franaDeMana != 0) 
  {
    bitWrite(detectParitate, 7, 1);
  }

  bitWrite(detectParitate, 6, 1);// prin aceasta instructiune se asigura faptul ca valoarea transmisa pentru 
  //detectia de erorii nu este niciodata 0000 0000 == NULL in ASCII

  frameTransmisie[6] = detectParitate;
  frameTransmisie[7] = endFrame;
  frameTransmisie[8] = endSir;
}

/**
   Functia paritate calculeaza bitul de paritate pentru o valoare transmisa ca parametru
   si returneaza valoarea 1 daca numarul de biti de 1 din numar este impar
   si 0 in caz contrar.
*/
uint8_t Bluetooth::calculParitate(uint8_t distanta)
{
  uint8_t sumaBiti = 0;//calculeaza suma bitilor de '1'
  distanta = (distanta & 0x55) + ((distanta >> 1) & 0x55);
  distanta = (distanta & 0x33) + ((distanta >> 2) & 0x33);
  distanta = (distanta & 0x0F) + ((distanta >> 4) & 0x0F);
  sumaBiti = distanta % 2;
  return sumaBiti;
}
