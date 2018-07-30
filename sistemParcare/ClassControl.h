
#ifndef control
#define control

#include <Buzzerclass.h>
#include <Snz.h>
#include <config.h>

#if (ARDUINO >=100)
  #include "Arduino.h"
#else 
  #include "WProgram.h"
  #endif

   class Control{

    /*
     * 
    mij=mijloc
    exd=exterior dreapta
    exs=exterior stanga
    ins=interior stanga
    ind=interior dreapta 
       
    */

     
    private :

    //id pentru fiecare senzor
    uint16_t _id_mij; 
    uint16_t _id_exd;
    uint16_t _id_exs;
    uint16_t _id_ins;
    uint16_t _id_ind;
    
    
    //pini pentru senzori ultrasonici 
     uint16_t  _echo_mij;
     uint16_t _trig_mij;
     uint16_t  _echo_exd;
     uint16_t _trig_exd;
     uint16_t _echo_exs;
     uint16_t _trig_exs;
     uint16_t _echo_ind;
     uint16_t _trig_ind;
     uint16_t _echo_ins;
     uint16_t _trig_ins;
   
    Senzor _mijloc;
    Senzor _extdreapta;
    Senzor _extstanga;
    Senzor _intdreapta;
    Senzor _intstanga;
    Buzzer object;
    
    public:
    Control(
    uint16_t echo_mij,
    uint16_t trig_mij,
    uint16_t echo_exd,
    uint16_t trig_exd,
    uint16_t echo_exs,
    uint16_t trig_exs,
    uint16_t echo_ind,
    uint16_t trig_ind,
    uint16_t echo_ins,
    uint16_t trig_ins,
    
    uint16_t id_mij,
    uint16_t id_exd,
    uint16_t id_exs,
    uint16_t id_ins,
    uint16_t id_ind);
   
    //Metode 
    void alertaBuzzer(uint16_t distanta,uint16_t volum );//se trimite cea mai mica distanta 
    uint16_t *citireSenzor();//returneaza cea mai mica distanta pentru buzzer
    void StopBuzzer();//functie pentru a opri sunetul generat de buzzer cand frana de mana este actionata 
    void initializare();//in aceasta functie initializam obiectele ce o sa fie folosite de clasa control
    void TaskLoop();//functia ce va apelata in loop-ul din sketch
    uint16_t minimDistante(uint16_t a[]);
    
    };
  #endif

