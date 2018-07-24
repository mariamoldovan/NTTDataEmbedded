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
  unsigned int _frequency;
  unsigned int _duration;
  unsigned int _volume ;
  static Buzzer* instance;
  Buzzer();
  //Buzzer (unsigned int frequency ,unsigned int duration , unsigned int volume );//constructor
 
  
  public :
 ~Buzzer();//destructor
 static Buzzer* getinstance();
 
 //Metode 
  void RingBuzzer();//functie pentru a genera sunet de la buzzer fara parametri
  void RingBuzzer(unsigned int frequency ,unsigned int duration , unsigned int volume);//functie pentru a genera sunet de la buzzer cu parametri
  void SilentBuzzer();//functie pentru a opri sunetul generat de buzzer 
  
  void set_freq(int frequency);//setam doar frecventa
  void set_duration(int duration);//setam doar duratia
  void set_volume(int volume);//setam doar volumul 
  
};

#endif 


