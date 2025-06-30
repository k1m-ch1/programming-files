#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_SH1106.h>
#include <IRremote.h>
#include <Servo.h>
int state=0;
const int redLed=7;
const int greenLed=8;
int relay=13;
const int recvPin=9;
int offSet;
int forwardDistance;
int leftDistance;
int rightDistance;
const int speedControlPin=6;
const int in1=A0;
const int in2=A1;
const int in3=A2;
const int in4=A3;
int pwm=200;
int degree90=300;
int degree180=600;
int trigPin=12;
int echoPin=10;
int startDistance=25;
int stopDistance=15;
int leftOrRight;
Adafruit_SH1106 display(4);
IRrecv irrecv(9);
decode_results results;
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
void moveRight(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
}
void moveLeft(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in4,LOW);
}
void stop(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void setOutput(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT); 
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(relay,OUTPUT);
  
}
int seekLeft(){
  seekingServo.write(180);
  delay(1000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  long seekLeftWait=pulseIn(echoPin,HIGH);
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
  long seekRightWait=pulseIn(echoPin,HIGH);
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
  long seekForwardWait=pulseIn(echoPin,HIGH);
  int seekForwardDistance=seekForwardWait*0.034/2;
  seekingServo.write(90);
  return seekForwardDistance;
}
int fasterSeekForward(){
  //this function assumes that you are already in servo.write(90);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  long fasterSeekForwardWait=pulseIn(echoPin,HIGH);
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
void leftRightOnlyCorrectiveMechanismSmart(){
  stop(0);
  leftDistance=seekLeft();
  rightDistance=seekRight();
  if(leftDistance>startDistance&rightDistance>startDistance){
    if(leftDistance>rightDistance){
      moveLeft(pwm);
      delay(degree90);
      stop(0);
    }
    if(leftDistance<rightDistance){
      moveRight(pwm);
      delay(degree90);
      stop(0);
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
   Serial.print(leftDistance);
   Serial.print(",");
   Serial.println(rightDistance);
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
   Serial.print(leftDistance);
   Serial.print(",");
   Serial.println(rightDistance);
   delay(1000);
}
void turnOff(){
  digitalWrite(relay,LOW);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,LOW);
  state=0;
}
void turnOn(){
  digitalWrite(relay,HIGH);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,HIGH);
  state=1;
}

void infoDisplay(){
  if(state==0){
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0,7);
  display.print("MODE: OFF");
  display.setTextSize(1);
  display.setCursor(0,30);
  display.print("MOTOR SPEED:");
  display.setCursor(100,30);
  display.print(map(pwm,0,255,0,100));
  display.print('%');
  display.setCursor(0,40);
  display.print("90 RUN TIME:");
  display.setCursor(100,40);
  display.print(degree90);
  display.setCursor(0,50);
  display.print("180 RUN TIME:");
  display.setCursor(100,50);
  display.print(degree180);
  display.display();
  }
  else{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0,7);
  display.print("MODE: ON");
  display.setTextSize(1);
  display.setCursor(0,30);
  display.print("MOTOR SPEED:");
  display.setCursor(100,30);
  display.print(map(pwm,0,255,0,100));
  display.print('%');
  display.setCursor(0,40);
  display.print("90 RUN TIME:");
  display.setCursor(100,40);
  display.print(degree90);
  display.setCursor(0,50);
  display.print("180 RUN TIME:");
  display.setCursor(100,50);
  display.print(degree180);
  display.display();
  }
}
void relayState(bool relayStatus){
  if(relayStatus==0){
    digitalWrite(relay,LOW);
  }
  if(relayStatus==1){
    digitalWrite(relay,HIGH);
  }
}
void setup() {
  // put your setup code here, to run once:
  setOutput();
  relayState(1);
  irrecv.enableIRIn();
  Serial.begin(9600);
  seekingServo.attach(5);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  infoDisplay();
  attachInterrupt(digitalPinToInterrupt(2),turnOff,RISING);
  attachInterrupt(digitalPinToInterrupt(3),turnOn,RISING);
  randomSeed(analogRead(A7));
  correctiveMechanism();
  if(state==0){
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
    relayState(0);
  }
  if(state==1){
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
    relayState(1);
  }
  infoDisplay();
  Serial.println("in loop");
}
void loop(){
  infoDisplay();
  while(state==0){
    stop(0);
    relayState(0);
    infoDisplay();
    int analogReading=analogRead(A6);
    degree90=map(analogReading,0,1023,0,1000);
    degree180=degree90*1.9;
    if(pwm<100){
      degree180=degree90*2;
    }
    
  }
  while(state==1){
  infoDisplay();
  relayState(1);
  moveForward(pwm);
  for(long i=0; i<1000;){
  if(state==0){
      infoDisplay();
      break;
    }
  if(fasterSeekForward()<=stopDistance){
      moveBackward(pwm);
      delay(200);
      stop(0);
      leftRightOnlyCorrectiveMechanismSmart();
      break;
    }
    delay(5);
  }
}
}  
