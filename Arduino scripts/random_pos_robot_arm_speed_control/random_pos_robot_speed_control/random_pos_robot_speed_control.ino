#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int sPin1=3;
int sPin2=5;
int sPin3=6;
int sPin4=9;
int angle1;
int angle2;
int angle3;
int angle4;
int a=90;
int b=90;
int c=90;
int d=90;
int wait=100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(sPin1);
  servo2.attach(sPin2);
  servo3.attach(sPin3);
  servo4.attach(sPin4);

  

}

void loop() {
  // put your main code here, to run repeatedly:{
  int pin[4]={1,2,3,4};
  int i=random(1,4);
  int j=pin[i];
  switch (j){
    case 1:
    angle1=random(0,180);
    while (a<angle1){
      a=a+1;
      servo1.write(a);
      delay(wait);
      if(a=angle1){
        break;
      }
     while (a>angle1){
      a=a-1;
      servo1.write(a);
      delay(wait);
      if(a=angle1){
        break;
      }
     }
    }
    break;
    case 2:
    angle2=random(0,180);
    while (b<angle2){
      b=b+1;
      servo2.write(b);
      delay(wait);
      if(b=angle2){
        break;
      }
     while (b>angle2){
      b=b-1;
      servo2.write(b);
      delay(wait);
      if(b=angle2){
        break;
      }
     }
    }
    break;    
    case 3:
    angle3=random(0,180);
    while (c<angle3){
      c=c+1;
      servo3.write(c);
      delay(wait);
      if(c=angle3){
        break;
      }
     while (c>angle3){
      c=c-1;
      servo3.write(c);
      delay(wait);
      if(c=angle3){
        break;
      }
     }
    }
    break;
    case 4:
    angle4=random(0,180);
    while (d<angle4){
      d=d+1;
      servo4.write(d);
      delay(wait);
      if(d=angle4){
        break;
      }
     while (d>angle4){
      d=d-1;
      servo4.write(d);
      delay(wait);
      if(d=angle4){
        break;
      }
     }
    }
    break;
  }
}
