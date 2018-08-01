#ifndef bluetoothConfig
#define BC

#include "Arduino.h"

const uint8_t startFrame = 'r';
const uint8_t endFrame = 'c';
const uint8_t endSir = '\0';

const uint16_t baudeRateBluetooth = 9600;

const uint16_t PinRxBluetooth = 8;  
const uint16_t PinTxBluetooth = 9;

const uint8_t NR_MAX_DISTANTE = 5;
const uint8_t NR_CARACTERE_FRAME = 9;


#endif
