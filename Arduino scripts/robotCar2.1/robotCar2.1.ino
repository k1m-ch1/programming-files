#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SH1106.h>
#include <Wire.h>
#include <SPI.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <Servo.h>
int forwardDistance;
int leftDistance;
int rightDistance;
const int speedControlPin=6;
const int in1=A0;
const int in2=A1;
const int in3=A2;
const int in4=A3;
int pwm=125;
int degree90=300;
int degree180=600;
int trigPin=A6;
int echoPin=10;
int startDistance=25;
int stopDistance=25;
int leftOrRight;
Servo seekingServo;
void moveForward(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in2,LOW);
}
void moveBackward(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in4,HIGH);
}
int moveRight(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  return 2;
}
int moveLeft(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in4,LOW);
  return 1;
}
int stop(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  return 0;
}
void setOutput(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT); 
}
int ultrasonicSeek(){
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  int ultrasonicWait=pulseIn(echoPin,HIGH);
  int distance=ultrasonicWait*0.034/2;
  return distance;
}
int seekLeft(){
  seekingServo.write(180);
  delay(1000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  int seekLeftWait=pulseIn(echoPin,HIGH);
  int seekLeftDistance=seekLeftWait*0.034/2;
  seekingServo.write(180);
  return seekLeftDistance;
}
int seekRight(){
  seekingServo.write(0);
  delay(1000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  int seekRightWait=pulseIn(echoPin,HIGH);
  int seekRightDistance=seekRightWait*0.034/2;
  seekingServo.write(0);
  return seekRightDistance;
}
int seekForward(){
  seekingServo.write(90);
  delay(1000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  int seekForwardWait=pulseIn(echoPin,HIGH);
  int seekForwardDistance=seekForwardWait*0.034/2;
  seekingServo.write(90);
  return seekForwardDistance;
}
int fasterSeekForward(){
  //this function assumes that you are already in servo.write(90);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  int fasterSeekForwardWait=pulseIn(echoPin,HIGH);
  int fasterSeekForwardDistance=fasterSeekForwardWait*0.034/2;

  return fasterSeekForwardDistance;

}
void correctiveMechanism(){
  stop(0);
  forwardDistance=seekForward();
  leftDistance=seekLeft();
  rightDistance=seekRight();
  if(forwardDistance>=startDistance){ 
  } 
  else if(leftDistance>startDistance&rightDistance>startDistance){
    leftOrRight=random(1,3);
    switch (leftOrRight){
      case 1:
      moveLeft(pwm);
      delay(degree90);
      stop(0);
      break;
      case 2:
      moveRight(pwm);
      delay(degree90);
      stop(0);
      break;
    }
  }
    else if(leftDistance>startDistance){
      moveLeft(pwm);
      delay(degree90);
      stop(0);
    }
    else if(rightDistance>startDistance){
      moveRight(pwm);
      delay(degree90);
      stop(0);
    }
    else {
      leftOrRight=random(1,3);
      switch (leftOrRight){
        case 1:
        moveLeft(pwm);
        delay(degree180);
        stop(0);
        break;
        case 2:
        moveRight(pwm);
        delay(degree180);
        stop(0);
        break;
      }
  }
  seekingServo.write(90);
  delay(1000);
}
void leftRightOnlyCorrectiveMechanism(){
  stop(0);
  leftDistance=seekLeft();
  rightDistance=seekRight();
  if(leftDistance>startDistance&rightDistance>startDistance){
    leftOrRight=random(1,3);
    switch (leftOrRight){
      case 1:
      moveLeft(pwm);
      delay(degree90);
      stop(0);
      break;
      case 2:
      moveRight(pwm);
      delay(degree90);
      stop(0);
      break;
    }
  }
    else if(leftDistance>startDistance){
      moveLeft(pwm);
      delay(degree90);
      stop(0);
    }
    else if(rightDistance>startDistance){
      moveRight(pwm);
      delay(degree90);
      stop(0);
    }
    else {
      leftOrRight=random(1,3);
      switch (leftOrRight){
        case 1:
        moveLeft(pwm);
        delay(degree180);
        stop(0);
        break;
        case 2:
        moveRight(pwm);
        delay(degree180);
        stop(0);
        break;
      }
   }
   seekingServo.write(90);
   delay(1000);
}
void setup() {
  // put your setup code here, to run once:
  setOutput();
  Serial.begin(9600);
  seekingServo.attach(5);
  randomSeed(analogRead(A7));
  correctiveMechanism();
}
void loop(){
  moveForward(pwm);
  for(long i=0; i<1000;){
  if(fasterSeekForward()<=stopDistance){
      moveBackward(pwm);
      delay(200);
      stop(0);
      leftRightOnlyCorrectiveMechanism();
      stop(0);
      break;
    }
    delay(5);
  }
}  
 