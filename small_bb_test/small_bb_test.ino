#include <CapacitiveSensor.h>
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);
long touchVar = cs_4_2.capacitiveSensor(30);
int redPin = 3;
int greenPin = 5;
int photoPin = 0;
int fadePin = 6;
int nightPin = 11;
int nightLevel = 0;
int caseState;
int fadeLevel = 0;
int darkState;
int counter = 0;
boolean fadeUp = false;


void setup() {
  // put your setup code here, to run once:
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(fadePin,OUTPUT);
pinMode(nightPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
touchSense();
debug();
}
