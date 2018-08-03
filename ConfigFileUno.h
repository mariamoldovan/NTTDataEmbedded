#ifndef ConfigFile
#define ConfigFile

//pini senzori 
const uint8_t EchoMijloc=7;
const uint8_t TrigMijloc=6;
const uint8_t EchoExteriorDreapta=13;
const uint8_t TrigExteriorDreapta=12;
const uint8_t EchoExteriorStanga=3;
const uint8_t TrigExteriorStanga=2;
const uint8_t EchoInteriorDreapta=11;
const uint8_t TrigInteriorDreapta=8;
const uint8_t EchoInteriorStanga=5;
const uint8_t TrigInteriorStanga=4;

//id senzori
const uint8_t IdMijloc=3;
const uint8_t IdExteriorDreapta=5;
const uint8_t IdExteriorStanga=1;
const uint8_t IdInteriorStanga=2;
const uint8_t IdInteriorDreapta=4; 

//pin switch 
const uint8_t PinSwitch=A0;

//numar senzori
const uint8_t NumarSenzori=5;

//parametri pentru clasa ce masoara si initilizeaza senzori  
const uint8_t VitezaSunetCM=29;
const uint8_t DistantaMaximaSenzor=150;
const uint8_t DistantaMinimaSenzor=2;
const uint8_t OutOfRange=160;

//-------------------------------------------------------
//parametru pentru buzzer
//distante pentru fiecare segment 
const uint8_t DistantaSegment5 = 150;
const uint8_t DistantaSegment4 = 120;
const uint8_t DistantaSegment3 = 90;
const uint8_t DistantaSegment2 = 60;
const uint8_t DistantaSegment1=  30;
const uint8_t DistantaSegment0=  15;

//frecventa/ton pentru fiecare segment 
const uint8_t FrecventaSegment5 = 45;
const uint8_t FrecventaSegment4 = 75;
const uint8_t FrecventaSegment3 = 95;
const uint8_t FrecventaSegment2 = 115;
const uint8_t FrecventaSegment1 = 135;
const uint8_t FrecventaSegment0 = 155;

//durata in milisecunde pentru fiecare nota/ton pe fiecare segment
const uint8_t DurataNotaSegment5 = 13;
const uint8_t DurataNotaSegment4 = 11;
const uint8_t DurataNotaSegment3 = 9;
const uint8_t DurataNotaSegment2 = 7;
const uint8_t DurataNotaSegment1 = 5;
const uint8_t DurataNotaSegment0 = 3;

//valoare default pentru volum 
const uint8_t DefaultVolum =5;


//-------------------------------------------------------
//parametri bluetooth 

//baudrate transmisie
const uint16_t baudeRateBluetooth = 9600;

//pini pentru modulul de transmisie bluetooth
const uint16_t PinRxBluetooth = 1;  
const uint16_t PinTxBluetooth = 0;


const uint8_t NrCaractereFrame = 9;

//parametri frame bluetooth
const uint8_t startFrame = 'r';
const uint8_t endFrame = 'c';
 
#endif


