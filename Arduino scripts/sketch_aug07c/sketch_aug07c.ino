#include <Servo.h>
int aPin1 = 0;  //connected to joystick 1 y axis
int aPin2 = 1;  //connected to joystick 2 y axis
int aPin3 = 2;  //connected to joystick 1 x axis
int aPin4 = 3;  //connected to joystick 2 x axis
int sPin1 = 3;  //connect servo that adjusts the upper joint to digital pin 3
int sPin2 = 5;  //connect servo that adjusts the lower joint to digital pin 5
int sPin3 = 6;  //connect servo that adjusts the base to digital pin 6
int sPin4 = 9;  //connect servo that adjusts the claw to digital pin 9
int angle1 = 0;
int angle2 = 90;
int angle3 = 90;
int angle4 = 90;
int wait=1000;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(sPin1);
  servo2.attach(sPin2);
  servo3.attach(sPin3 );
  servo4.attach(sPin4);
  servo1.write(angle1);
  delay(wait);
  servo2.write(angle2);
  delay(wait);
  servo3.write(angle3);
  delay(wait);
  servo4.write(angle4);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int number = analogRead(A4);
  wait=map(number,0,1023,0,1000);
  //move servo1 clockwise
  while (analogRead(aPin1) < 341) {

    if (angle1 > 140) {
      break;
    }
    angle1 = angle1 + 1;
    servo1.write(angle1);
    delay(wait);
  }
  //move servo1 counter clockwise
  while (analogRead(aPin1) > 682) {
    if (angle1 < 1) {
      break;
    }
    angle1 = angle1 - 1;
    servo1.write(angle1);
    delay(wait);
  }
  //move servo2 clockwise
  while (analogRead(aPin2) < 341) {
    if (angle2 > 140) {
      break;
    }
    angle2 = angle2 + 1;
    servo2.write(angle2);
    delay(wait);
  }
  //move servo2 counter clockwise 
  while (analogRead(aPin2) > 682) {
    if (angle2 < 1) {
      break;
    }
    angle2 = angle2 - 1;
    servo2.write(angle2);
    delay(wait);
  }
  //move servo3 clockwise
  while (analogRead(aPin3) < 341) {
    if (angle3 > 179) {
      break;
    }
    angle3 = angle3 + 1;
    servo3.write(angle3);
    delay(wait);
  }
  //move servo3 counter clockwise
  while (analogRead(aPin3) > 682) {
    if (angle3 < 1) {
      break;
    }
    angle3 = angle3 - 1;
    servo3.write(angle3);
    delay(wait);
  }
  //move servo4 clockwise
  while (analogRead(aPin4) < 341) {
    if (angle4 > 179) {
      break;
    }
    angle4 = angle4 + 1;
    servo4.write(angle4);
    delay(wait);
  }
  //move servo4 counter clockwise
  while (analogRead(aPin4) > 682) {
    if (angle4 < 1) {
      break;
    }
    angle4 = angle4 - 1;
    servo4.write(angle4);
    delay(wait);
  }



}
