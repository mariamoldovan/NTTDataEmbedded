#ifndef setsnz
#define setsnz

#include <Snz.h>

#if (ARDUINO >=100)
  #include "Arduino.h"
#else 
  #include "WProgram.h"
  #endif


class SetSnz{
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

     public:
        SetSnz(
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
	   SetSnz();	
        void initializare();

        uint16_t* getDistance();
	
};
#endif

