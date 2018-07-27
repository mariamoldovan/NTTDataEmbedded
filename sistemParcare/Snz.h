#include "Arduino.h"

class Senzor
{
  
    public:
    
     Senzor(uint16_t id,uint16_t pinTrig, uint16_t pinEcho);
	
	
	 Senzor() ;
    
     uint16_t citesteDistanta();
    
     void begin();
	 
	 uint16_t getId();
             
    private:
 
     uint16_t _pinTrig, _pinEcho, distantaActuala, idSenzor;
    // NewPing sonar;
    

};
