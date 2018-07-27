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

Bluetooth::Bluetooth(uint16_t piniConfig[], uint16_t baund)
{
  bt = new SoftwareSerial (piniConfig[0], piniConfig[1]); //RX, TX (Switched on the Bluetooth - RX -> TX | TX -> RX)
  uint16_t btdata; // the data given from the computer
  (*bt).begin(baund);
}

/**
   Functia getInstance() este folosita pentru crearea unui obiect de
   tip Bluetooth. Se foloseste design patternul Singleton.
*/
Bluetooth* Bluetooth::getInstance(uint16_t piniConfig[], uint16_t baundRate)
{
  if (INSTANCE == nullptr)
  {
    INSTANCE = new Bluetooth(piniConfig, baundRate);
  }
  return INSTANCE;
}

/**
   Functia trimite date este utilizata pentru transmisia datelor
   pe directia Arduino-Raspberry.
   Aceasta comunicare se efectueaza prin intermediul unui dispozitiv Bluetooth.
   Pentru efectuarea comunicarii, folosim functiile din biblioteca SoftwareSerial.
*/
void Bluetooth::trimiteDateRaspberry(uint8_t data[5])
{
  int16_t i; //iteratore");
  uint8_t frame[9];

  construireFrame(data, frame); //construirea frame-ului care urmeaza sa fie transmis

  String transmite = frame; //conversia la tipul String
  (*bt).println("\t"); //pentru asigurarea unei transmiteri complete
  (*bt).println(""+transmite);
  //(*bt).println("\t"); //pentru asigurarea unei transmiteri complete
}

uint16_t Bluetooth::primesteDateRaspberry()
{
  String btdata;
  //Serial.println("Se incepe citirea de la Raspberry");
  btdata =(*bt).read();
  int volum = btdata.toInt();
  Serial.println(volum);
  return volum;
}

uint8_t Bluetooth::decodificareFrame(uint8_t mesajVolum)
{
  
  //Serial.println("in decodare");
  /**uint8_t i = sizeof(mesajDecod) - 1; //iterator
  mesajVolum.toCharArray(mesajDecod, sizeof(mesajDecod));

  if (mesajDecod[i] != 'r')return -1;

  volum = mesajDecod[--i];
  Serial.println(volum);
  uint16_t sumaBiti = 0;//calculeaza suma bitilor de '1'
  while (mesajDecod[i] != 0) {
    Serial.println("in while:");
    if (bitRead(mesajDecod[i], 0)) sumaBiti++;
    mesajDecod[i] = mesajDecod[i] >> 1;
    Serial.println(mesajDecod[i]);
  }

  if ((bitRead(mesajDecod[--i], 0) + sumaBiti) % 2 != 0) return -1;
  */
  return mesajVolum;
}


/**
   Functia construireFrame se ocupa direct cu asamblarea componentelor unui frame.
   Structura unui frame este urmatoarea:
   -se incepe cu litera 'r' pentru marcarea inceputului de frame
   -se adauga apoi informatiile transmise prin parametrul data
   -se adauga un caracter pentru detectia erorilor
   -se adauga caracterul 'c' pentru a marca finalul frame-ului
   -se adauga caracterul '\0' pentru a marca sfarsitul sirului
*/
void Bluetooth::construireFrame(uint8_t data[], uint8_t* frame)
{
  uint16_t i;//iterator
  uint8_t startFrame = 'r';
  uint8_t endFrame = 'c';
  uint8_t detectParitate = 0;
  frame[0] = startFrame;
 //Serial.println(frame.length());
  for (i = 0; i <= 4; i++)
  {
    frame[i + 1] = data[i];
    detectParitate = detectParitate << 1;//se shifteza continutul pentru a adauga urmatorul bit
    if (paritate(data[i])) bitWrite(detectParitate, 0, 1);//se adauga un bit de paritate pentru fiecare valoare din vectorul data
  }
  frame[6] = detectParitate;
  frame[7] = endFrame;
  frame[8] = '\0';
}

/**
   Functia paritate calculeaza bitul de paritate pentru o valoare transmisa ca parametru
   si returneaza valoarea 1 daca numarul de biti de 1 din numar este impar
   si 0 in caz contrar.
*/
uint16_t Bluetooth::paritate(uint8_t dist)
{
  uint16_t sumaBiti = 0;//calculeaza suma bitilor de '1'
  while (dist != 0) {
    if (bitRead(dist, 0)) sumaBiti++;
    dist = dist >> 1;
  }
  if ((sumaBiti % 2) == 0) return 0;
  return 1;
}

