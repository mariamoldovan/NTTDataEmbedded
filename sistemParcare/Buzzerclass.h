#ifndef buzzer
#define buzzer

#if (ARDUINO >=100)
  #include "Arduino.h"
#else 
  #include "WProgram.h"
  #endif

  // CONNECTION:
 //   Pins  9 & 10 - ATmega328, ATmega128, ATmega640, ATmega8, Uno, Leonardo, etc.
 //   Pins 11 & 12 - ATmega2560/2561, ATmega1280/1281, Mega
 //   Pins 12 & 13 - ATmega1284P, ATmega644
 //   Pins 14 & 15 - Teensy 2.0
 //   Pins 25 & 26 - Teensy++ 2.0

class Buzzer {
  
  private://variabile private 
  uint16_t _frequency;
  uint16_t _duration;
  uint16_t _volume ;
  static Buzzer* instance;
  Buzzer();
  Buzzer (uint16_t frequency ,uint16_t duration , uint16_t volume );//constructor
 
  
  public :
 ~Buzzer();//destructor
 static Buzzer* getinstance();
 
 //Metode 
  void RingBuzzer(uint16_t sirdistanta[],uint16_t volum);//functie pentru a genera sunet de la buzzer fara parametri
  void RingBuzzer(uint16_t frequency ,uint16_t duration , uint16_t volume);//functie pentru a genera sunet de la buzzer cu parametri
  void SilentBuzzer();//functie pentru a opri sunetul generat de buzzer 
  
  void set_freq(uint16_t frequency);//setam doar frecventa
  void set_duration(uint16_t duration);//setam doar duratia
  void set_volume(uint16_t volume);//setam doar volumul
};

#endif 


