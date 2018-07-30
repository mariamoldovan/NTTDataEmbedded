#include "setSnz.h"

SetSnz :: SetSnz(){}

SetSnz :: SetSnz(
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
      uint16_t id_ind )
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

void SetSnz :: initializare(){
  
    _mijloc=Senzor (_id_mij,_trig_mij,_echo_mij);
    _extdreapta=Senzor (_id_exd,_trig_exd,_echo_exd);
    _extstanga=Senzor(_id_exs,_trig_exs,_echo_exs);
    _intdreapta=Senzor(_id_ind,_trig_ind,_echo_ind);
    _intstanga=Senzor (_id_ins,_trig_ins,_echo_ins);
}

uint16_t* SetSnz :: getDistance()
{
    initializare();
    uint16_t sirdistante[5];
    sirdistante[0]=_extstanga.citesteDistanta();
    sirdistante[1]=_intstanga.citesteDistanta();
    sirdistante[2]=_mijloc.citesteDistanta();
    sirdistante[3]=_intdreapta.citesteDistanta();
    sirdistante[4]=_extdreapta.citesteDistanta(); 
   	
	Serial.println();
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


