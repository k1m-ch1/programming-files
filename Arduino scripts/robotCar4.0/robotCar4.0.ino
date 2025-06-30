#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_SH1106.h>
#include <Servo.h>
char inputChar;
int motorPowerPercentage;
int threshold;
int backwardState=0;
bool state=0;
const int redLed=7;
const int greenLed=8;
int relay=13;
const int recvPin=9;
int forwardDistance;
int leftDistance;
int rightDistance;
const int speedControlPin=6;
const int in1=4;
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
int xAxis=A6;
int yAxis=A0;
int numberForArray=0;
int increaseMargin=5;
unsigned int direction=4;
int cursorPointingAt[5]={10,20,30,40,50};

Adafruit_SH1106 display(4);
Servo seekingServo;
void moveForward(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in2,LOW);
  direction=1;
  infoDisplay();
}
void moveBackward(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in4,HIGH);
  direction=3;
  infoDisplay();
}
void moveRight(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  direction=2;
  infoDisplay();
}
void moveLeft(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in4,LOW);
  direction=4;
  infoDisplay();
}
void stop(int speed){
  analogWrite(speedControlPin,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  direction=0;
  infoDisplay();
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
  delay(400);
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
  delay(800);
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
  delay(400);
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
  stop(0);
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
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(80,0);
  switch (state){
    case 0:
    display.print("OFF");
    break;
    case 1:
    display.print("ON");
    break;
  }
  display.setTextSize(1);
  int yCord=cursorPointingAt[numberForArray];
  display.setCursor(0,yCord);
  display.print(">");
  display.setCursor(8,0);
  switch (direction){
    case 0:
    display.print("STOP");
    break;
    case 1:
    display.print("FORWARD");
    break;
    case 2:
    display.print("RIGHT");
    break;
    case 3:
    display.print("BACKWARD");
    break;
    case 4:
    display.print("LEFT");
    break;
  }
  display.setCursor(8,10);
  display.print("+");
  display.print(increaseMargin);
  display.setCursor(8,20);
  display.print("STOP:  ");
  display.print(stopDistance);
  display.setCursor(8,30);
  display.print("MOTOR SPEED: ");
  motorPowerPercentage=map(pwm,0,255,0,100);
  display.print(motorPowerPercentage);
  display.print('%');  
  display.setCursor(8,40);
  display.print("DEGREE 90:   ");
  display.print(degree90);
  display.setCursor(8,50);
  display.print("DEGREE 180:  ");
  display.print(degree180);
  display.display();


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
    relayState(0);
    infoDisplay();
    if(Serial.available()>0){
      inputChar=Serial.read();
      if(inputChar=='0'){
        stop(0);
      }
      while(inputChar=='1'){
        moveForward(pwm);
        if(Serial.available()>0){
          break;
        }
      }
      while(inputChar=='2'){
        moveRight(pwm);
        if(Serial.available()>0){
          break;
        }
      }
      while(inputChar=='3'){
        moveBackward(pwm);
        if(Serial.available()>0){
          break;
        }
      }
      while(inputChar=='4'){
        moveLeft(pwm);
        if(Serial.available()>0){
          break;
        }
      }
    }
    while(analogRead(yAxis)<341){
    if(numberForArray>=4){
      numberForArray=-1;
    }
    for(int i=0; i<800; i++){
      if(analogRead(yAxis)>341){
        break;
      }
      delay(1);
    }
    numberForArray++;
    Serial.println(numberForArray);
    infoDisplay();
  }
  while(analogRead(yAxis)>642){
    if(numberForArray<=0){
      numberForArray=5;
    }
    for(int i=0; i<800;i++){
      if(analogRead(yAxis)<642){
        break;
      }
      delay(1);
    }
    numberForArray--;
    infoDisplay();
  }
  switch (numberForArray){
    case 0:
    while(analogRead(xAxis)<341){
    if(increaseMargin>100){
      increaseMargin=100;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    increaseMargin++;
    infoDisplay();
  }
  while(analogRead(xAxis)>642){
    if(increaseMargin<2){
      increaseMargin=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    increaseMargin--;
    infoDisplay();
  }
    break;
    case 1:
    while(analogRead(xAxis)<341){
    if(stopDistance>50){
      stopDistance=50;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    stopDistance=stopDistance+increaseMargin;
    if(stopDistance>50){
      stopDistance=50;
      break;
    }
    infoDisplay();
  }
  while(analogRead(xAxis)>642){
    if(stopDistance<2){
      stopDistance=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    stopDistance=stopDistance-increaseMargin;
    if(stopDistance<2){
      stopDistance=1;
      break;
    }
    infoDisplay();
   }
   break;
   case 2:
   while(analogRead(xAxis)<341){
    if(pwm>254){
      pwm=255;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    pwm=pwm+increaseMargin;
    if(pwm>254){
      pwm=255;
      break;
    }
    infoDisplay();
  }
  while(analogRead(xAxis)>642){
    if(pwm<2){
      pwm=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    pwm=pwm-increaseMargin;
    if(pwm<2){
      pwm=1;
      break;
    }
    infoDisplay();
  }
  break;
  case 3:
  while(analogRead(xAxis)<341){
    if(degree90>9000){
      degree90=9000;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    degree90=degree90+increaseMargin;
    if(degree90>9000){
      degree90=9000;
      break;
    }
    infoDisplay();
  }
  while(analogRead(xAxis)>642){
    if(degree90<2){
      degree90=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    degree90=degree90-increaseMargin;
    if(degree90<2){
      degree90=1;
      break;
    }
    infoDisplay();
  }
  break;
  case 4:
  while(analogRead(xAxis)<341){
    if(degree180>9000){
      degree180=9000;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    degree180=degree180+increaseMargin;
    if(degree180>9000){
      degree180=9000;
      break;
    }
    infoDisplay();
  }
   while(analogRead(xAxis)>642){
    if(degree180<2){
      degree180=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    degree180=degree180-increaseMargin;
    if(degree180<2){
      degree180=1;
      break;
    }
    infoDisplay();
  }
  break;
  }
  infoDisplay();
  }
  while(state==1){
  infoDisplay();
  relayState(1);
  moveForward(pwm);
  threshold=(millis()/1000)+1;
  for(long i=0; i<1000;){
  if(state==0){
      infoDisplay();
      break;
    }
  if(fasterSeekForward()<=stopDistance){
      moveBackward(pwm);
      if(millis()/1000>threshold){
        delay(200);       
      }
      stop(0);
      leftRightOnlyCorrectiveMechanismSmart();
      break;
    }
    delay(5);
  }
}
stop(0);
}  

