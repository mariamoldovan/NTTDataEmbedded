
//Sonar 1
const int echopin1=2;
const int trigpin1=3;

//Sonar 2
const int echopin2=4;
const int trigpin2=5;

//Sonar 3
const int echopin3=6;
const int trigpin3=7;

//Sonar 4
const int echopin4=8;
const int trigpin4=9;

void setup() {
  
 pinMode(trigpin1,OUTPUT);
 pinMode(echopin1,INPUT);
 pinMode(trigpin2,OUTPUT);
 pinMode(echopin2,INPUT);
 pinMode(trigpin3,OUTPUT);
 pinMode(echopin3,INPUT);
 pinMode(trigpin4,OUTPUT);
 pinMode(echopin4,INPUT);
 Serial.begin(9600);}

void loop()
{
  
long dur1,dur2,dur3,dur4;
long cm1,cm2,cm3,cm4;

dur1=GetDuration(trigpin1,echopin1);
dur2=GetDuration(trigpin2,echopin2);
dur3=GetDuration(trigpin3,echopin3);
dur4=GetDuration(trigpin4,echopin4);

cm1 = microsecondsToCentimeters(dur1);
Print(1,cm1);
delay(150);

cm2 = microsecondsToCentimeters(dur2);
Print(2,cm2);
delay(150);

cm3 = microsecondsToCentimeters(dur3);
Print(3,cm3);
delay(150);

cm4 = microsecondsToCentimeters(dur4);
Print(4,cm4);

delay(500);

}

long microsecondsToCentimeters(long microseconds)
{return microseconds / 29 / 2;}

long GetDuration(int trigPin,int echoPin){
  
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  int duration = pulseIn(echoPin, HIGH);
  return duration;
  
}

void Print(int id,int dist){
  
Serial.print(id);
if(dist>200){
  Serial.print("Out of range !!") ;
}
else if(dist < 200 && dist > 0 ){
  for(int i = 0 ; i <= dist ; i++){
  Serial.print("-");
  }
  Serial.print(dist,DEC);
  Serial.print(" cm");
  Serial.println();
}
}

