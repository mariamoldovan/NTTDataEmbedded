#include <NewPing.h>
#include "Snz.h"

Senzor::Senzor(uint16_t id, uint16_t pinTrig, uint16_t pinEcho)
{
    _pinTrig = pinTrig;
    _pinEcho = pinEcho;
	idSenzor = id;
}

Senzor :: Senzor()
{
	_pinTrig = 0;
    	_pinEcho = 0;
	idSenzor = 0;
}

uint16_t Senzor::citesteDistanta()
{
  NewPing sonar(_pinTrig, _pinEcho, 400);
  float duration;
  duration = sonar.ping_median(5);

  distantaActuala = (duration / 2) * 0.0343;
  // Send results to Serial Monitor
  if (distantaActuala >= 150 || distantaActuala <= 2) {
    return 150;
  }
  else {
    return distantaActuala;
    delay(500);
  }
}

uint16_t Senzor::getId()
{
	return idSenzor;
}

