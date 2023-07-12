#include "AFMotor.h"
#define lightsensor A0
#define borderLeft 100
#define borderRight 500
#define normalSpeed 80

AF_DCMotor motorRight (1,MOTOR12_8KHZ) ;
AF_DCMotor motorLeft (3,MOTOR34_8KHZ)  ;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
    pinMode(lightsensor, INPUT) ;
    
  //turn on motor
  motorRight.setSpeed(normalSpeed);
  motorLeft.setSpeed(normalSpeed);
}

void loop() {
  int sensor=0;
  int error=0;

  Serial.println(analogRead(lightsensor));
  sensor=analogRead(lightsensor);
  error=(sensor -75);
  
  if(sensor>borderLeft && sensor<borderRight)
  {
    motorRight.setSpeed(normalSpeed);
    motorLeft.setSpeed(normalSpeed);
    motorRight.run(FORWARD);
    motorLeft.run(FORWARD);
  }
  else if(sensor>=borderRight)
  {
 
    motorRight.setSpeed(220);
    motorLeft.setSpeed(220);
    motorRight.run(FORWARD);
    motorLeft.run(BACKWARD);
  }
  else if(sensor<=100)
  {
 
    //motorRight.setSpeed(normalSpeed+error);
      motorLeft.setSpeed(190);
      motorRight.setSpeed(190);
      motorLeft.run(FORWARD);
      motorRight.run(BACKWARD);
    
  }

}
