#include "Buzzerclass.h"
#include <toneAC.h>

Buzzer* Buzzer::instance = 0;
 
Buzzer* Buzzer :: getinstance()
{
    if (instance == 0)
    {
        instance = new Buzzer();
    }

    return instance;
}

Buzzer :: Buzzer(){
  
  _frequency = 100;
  _duration = 10;
  _volume = 3 ;
}

/*Buzzer :: Buzzer(unsigned int frequency ,unsigned int duration , unsigned int volume){
  Serial.print("Obiectul de tip buzzer a fost instantiat !!!");
  _frequency = frequency;
  _duration = duration;
  _volume = volume ;
}*/

Buzzer :: ~Buzzer(){
 _frequency=0;
 _duration=0;
 _volume=0;
}

void Buzzer :: RingBuzzer()
{
  
  toneAC(_frequency,_volume,_duration);
}

void Buzzer :: RingBuzzer(unsigned int frequency ,unsigned int duration , unsigned int volume)
{
  toneAC(frequency,duration,volume);
}

void Buzzer :: SilentBuzzer(){
  noToneAC();
  toneAC(0);
}

void Buzzer :: set_freq(int frequency){
  _frequency=frequency;
}

void Buzzer :: set_volume(int volume){
  _volume = volume;
}

void Buzzer :: set_duration(int duration){
  _duration= duration ;
}

