#include <Servo.h>

int aPin1=0;
int aPin2=1;
int aPin3=2;
int aPin4=3;
int sPin1=3;
int sPin2=5;
int sPin3=6;
int sPin4=9;
int i;
char j;
char  pin[4]={'a','b','c','d'};
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(sPin1);
  servo2.attach(sPin2);
  servo3.attach(sPin3);
  servo4.attach(sPin4);

  Serial.println("RANDOM POSITION GENERATOR START");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  i = random(0,4);
  j = pin[i];

  switch (j){
    case 'a':
    int k=random(0,181);
    servo1.write(k);
    Serial.print("Servo1 pos:  ");
    Serial.println(k);
    break;
    
    case 'b':
    int l=random(0,181);
    servo2.write(l);
    Serial.print("Servo2 pos:  ");
    Serial.println(l);
    break;
    
    case 'c':
    int m=random(0,181);
    servo3.write(m);
    Serial.print("Servo3 pos:  ");
    Serial.println(m);
    break;
    
    case 'd':
    int n=random(0,181);
    servo4.write(n);
    Serial.print("Servo4 pos:  ");
    Serial.println(n);    
    break;
    }
  delay(1000);
  

}
