
#include "ClassControl.h"


    
   Control ::  Control(
    uint16_t echo_mij,
    uint16_t trig_mij,
    uint16_t echo_exd,
    uint16_t trig_exd,
    uint16_t  echo_exs,
    uint16_t trig_exs,
    uint16_t echo_ind,
    uint16_t trig_ind,
    uint16_t echo_ins,
    uint16_t trig_ins,
    uint16_t id_mij,
    uint16_t id_exd,
    uint16_t id_exs,
    uint16_t id_ins,
    uint16_t id_ind)
    
   {
     
     _echo_mij=echo_mij;
     _trig_mij=trig_mij;
     _echo_exd=echo_exd;
     _trig_exd=trig_exd;
     _echo_exs=echo_exs;
     _trig_exs=trig_exs;
     _echo_ind=echo_ind;
     _trig_ind=trig_ind;
     _echo_ins=echo_ins;
     _trig_ins=trig_ins;

     _id_mij=id_mij;
     _id_exd=id_exd;
     _id_exs=id_exs;
     _id_ins=id_ins;
     _id_ind=id_ind;
     
    }
  

 uint16_t* Control :: citireSenzor(){

    
    int sirdistante[5];
    sirdistante[0]=_extstanga.citesteDistanta();
    sirdistante[1]=_intstanga.citesteDistanta();
    sirdistante[2]=_mijloc.citesteDistanta();
    sirdistante[3]=_intdreapta.citesteDistanta();
    sirdistante[4]=_extdreapta.citesteDistanta(); 

    for(int i=0;i<5;i++){
      Serial.print(i+1);
      Serial.print(". -------------- ");
      Serial.print(sirdistante[i]);
      Serial.print(" cm");
      Serial.println();
    }
    Serial.println();

    return sirdistante;
}

  void Control :: alertaBuzzer(uint16_t distanta ,uint16_t volum){
 
  if(distanta<150 && distanta>120){
      object.set_freq(100);
      object.set_volume(volum);
      object.set_duration(5);
      object.RingBuzzer();
  }
  else if (distanta <120 && distanta>90){
      object.set_freq(200);
      object.set_volume(volum);
      object.set_duration(10);
      object.RingBuzzer();
  }
  else if (distanta<90 && distanta>60){
      object.set_freq(300);
      object.set_volume(volum);
      object.set_duration(15);
      object.RingBuzzer();
  }
  else if (distanta<60 && distanta>30){
     object.set_freq(400);
     object.set_volume(volum);
     object.set_duration(20);
     object.RingBuzzer();
  }
else if (distanta<30 && distanta>15){
    object.set_freq(500);
    object.set_volume(volum);
    object.set_duration(0);
    object.RingBuzzer();
}
}

void Control :: StopBuzzer(){
  object.SilentBuzzer();
}

uint16_t Control :: minimDistante(uint16_t sirdistante[]){
uint16_t contor, min, index;
 
  min = sirdistante[0];
  index = 0;
 
  for (contor = 1; contor < 5; contor++) {
    if (sirdistante[contor] < min) {
       index = contor;
       min = sirdistante[contor];
    }
  }
 
  return index;  
}

void Control :: initializare(){
  
    Senzor _mijloc(_id_mij,_trig_mij,_echo_mij);
    Senzor _extdreapta(_id_exd,_trig_exd,_echo_exd);
    Senzor _extstanga(_id_exs,_trig_exs,_echo_exs);
    Senzor _intdreapta(_id_ind,_trig_ind,_echo_exd);
    Senzor _intstanga(_id_ins,_trig_ins,_echo_ins);
}

void Control:: TaskLoop(){
  initializare();
  uint16_t minim =  minimDistante(citireSenzor());
  alertaBuzzer(minim,2);
}

