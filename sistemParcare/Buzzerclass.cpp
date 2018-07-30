#include "Buzzerclass.h"
#include <toneAC.h>
#include <stddef.h>

Buzzer* Buzzer::instance = 0 ;
 
Buzzer* Buzzer :: getinstance()
{
    if (instance == nullptr)
    {
        instance = new Buzzer();
    }

    return instance;
}

Buzzer :: Buzzer(){
  //constructor fara parametri
  _frequency = 100;
  _duration = 10;
  _volume = 3 ;
}

Buzzer :: Buzzer(uint16_t frequency ,uint16_t duration , uint16_t  volume){
  //constructor cu parametri
  Serial.print("Obiectul de tip buzzer a fost instantiat !!!");
  _frequency = frequency;
  _duration = duration;
  _volume = volume ;
}

Buzzer :: ~Buzzer(){
  //destructor
 _frequency=0;
 _duration=0;
 _volume=0;
}

void Buzzer :: RingBuzzer(uint16_t sirdistante[],uint16_t volum)
{
  /*functie ce calculeaza distanta cea mai mica din vectorul de distante trimis de catre control
    dupa ce distanta este calculata buzzerul va incepe sa produca sunet in functie de paramtri dati
    */
   uint16_t temp = sirdistante[0];
   for(uint16_t i=0; i<5; i++) {
      if(temp>sirdistante[i]) {
         temp=sirdistante[i];
      }
   }
   Serial.print("Distanta minima :" );
   Serial.print(temp);
   Serial.println();
  
  
  
  if(temp<150 && temp>120){
      toneAC(150,25,volum,true);
      delay(100);
  }
  else if (temp <120 && temp>90){
      toneAC(100,20,volum,true);
      delay(80);
  }
  else if (temp<90 && temp>60){
      toneAC(80,15,volum,true);
      delay(60);
  }
  else if (temp<60 && temp>30){
     toneAC(60,10,volum,true);
     delay(40);
  }
  else if (temp<30 && temp>15){
    toneAC(40,5,volum,true);
    delay(20);
    noToneAC();
}
  else if (temp<15){
    toneAC(20,1,volum,true);
    delay(10);
    noToneAC();
}
}

void Buzzer :: RingBuzzer(uint16_t frequency ,uint16_t duration , uint16_t volume)
{
  /*metoda pentru a genera sunet fara logica pentru distante*/
  toneAC(frequency,duration,volume);
}

void Buzzer :: SilentBuzzer(){
  /*metoda pentru a opri sunetul generat de buzzer*/
  noToneAC();
  toneAC(0);
}

void Buzzer :: set_freq(uint16_t frequency){
  _frequency=frequency;
}

void Buzzer :: set_volume(uint16_t volume){
  _volume = volume;
}

void Buzzer :: set_duration(uint16_t duration){
  _duration= duration ;
}

