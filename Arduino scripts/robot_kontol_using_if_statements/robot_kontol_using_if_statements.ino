#include <Servo.h>
int aPin1 = 0;
int aPin2 = 1;
int aPin3 = 2;
int aPin4 = 3;
int sPin1 = 3;
int sPin2 = 5;
int sPin3 = 6;
int sPin4 = 9;
int angle1;
int angle2;
int angle3;
int angle4;
int wait = 10 ; //controls the speed of the servo in degrees per millisecond
int waitHome=1000; //controls the delay between each servo during auto home of the motors
Servo servo1, servo2, servo3, servo4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(sPin1);
  servo2.attach(sPin2);
  servo3.attach(sPin3);
  servo4.attach(sPin4);
  servoResetCD(1000);
  servo1.write(90);
  delay(waitHome);
  servo2.write(90);
  delay(waitHome);
  servo3.write(90);
  delay(waitHome);
  servo4.write(90);
  delay(waitHome);
  Serial.println("ALL SERVO READY TO CONTROL");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(aPin1)<341){
    angle1=constrain(angle1,0,140);
    angle1=angle1+1;
    servo1.write(angle1);
    delay(wait);
  }
  if(analogRead(aPin1)>682){
    angle1=constrain(angle1,0,140);
    angle1=angle1-1;
    servo1.write(angle1);
    delay(wait);
  }
  if(analogRead(aPin2)<341){
    angle2=constrain(angle2,0,140);
    angle2=angle2+1;
    servo2.write(angle2);
    delay(wait);
  }
  if(analogRead(aPin2)>682){
    angle2=constrain(angle2,0,140);
    angle2=angle2-1;
    servo2.write(angle2);
    delay(wait);
  }
  if(analogRead(aPin3)<341){
    angle3=constrain(angle3,0,180);
    angle3=angle3+1;
    servo3.write(angle3);
    delay(wait);
  }
  if(analogRead(aPin3)>682){
    angle3=constrain(angle3,0,180);
    angle3=angle3-1;
    servo3.write(angle3);
    delay(wait);
  }
  if(analogRead(aPin4)<341){
    angle4=constrain(angle4,0,180);
    angle4=angle4+1;
    servo4.write(angle4);
    delay(wait);
  }
  if(analogRead(aPin4)>682){
    angle4=constrain(angle4,0,180);
    angle4=angle4-1;
    servo4.write(angle4);
    delay(wait);
  }

}
void servoResetCD(int countdown) {
  Serial.println("RESETTING IN 3");
  delay(countdown);
  Serial.println("RESETTING IN 2");
  delay(countdown);
  Serial.println("RESETTING IN 1");
  delay(countdown);
  Serial.println("RESET");
}
