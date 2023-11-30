int pinIn=2;
int pinOut1=3;
int pinOut2=4;
int pinOut3=5;
int pinOut4=6;
int pinOut5=7;
int pinOut6=8;
int pinOut7=9;
int pinOut8=10;
int state;
int state1;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinIn,INPUT);
  pinMode(pinOut1,OUTPUT);
  pinMode(pinOut2,OUTPUT);
  pinMode(pinOut3,OUTPUT);
  pinMode(pinOut4,OUTPUT);
  pinMode(pinOut5,OUTPUT);
  pinMode(pinOut6,OUTPUT);
  pinMode(pinOut7,OUTPUT);
  pinMode(pinOut8,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(state==0&digitalRead(pinIn)==1){
    state1=1;
    digitalWrite(pinOut1,HIGH);
  }
  if(state1==1){
    state=1;
  }
  while(state1==1&digitalRead(pinIn)==1){
    digitalWrite(pinOut2,HIGH);
    state=2;
  }
  if(state==2){
    state1=2;
  }
  while(state==2&digitalRead(pinIn)==1){
    digitalWrite(pinOut3,HIGH);
    state1=3;
  }
  if(state1==3){
    state=3;
  }
  while(state==3&digitalRead(pinIn)==1){
    digitalWrite(pinOut4,HIGH);
    state1=4;
  }
  if(state1==4){
    state=4;
  }
  while(state==4&digitalRead(pinIn)==1){
    digitalWrite(pinOut5,HIGH);
    state1=5;
  }
  if(state1==5){
    state=5;
  }
  while(state==5&digitalRead(pinIn)==1){
    digitalWrite(pinOut6,HIGH);
    state1=6;
  }
  if(state1==6){
    state=6;
  }
  while(state==6&digitalRead(pinIn)==1){
    digitalWrite(pinOut7,HIGH);
    state1=7;
  }
  if(state1==7){
    state=7;
  }
 while(state==7&digitalRead(pinIn)==1){
    digitalWrite(pinOut8,HIGH);
    state1=8;
 }
 if(state1==8){
    state=8;
 }
 while(state==8&digitalRead(pinIn)==1){
    digitalWrite(pinOut1,LOW);
    digitalWrite(pinOut2,LOW);
    digitalWrite(pinOut3,LOW);
    digitalWrite(pinOut4,LOW);
    digitalWrite(pinOut5,LOW);
    digitalWrite(pinOut6,LOW);
    digitalWrite(pinOut7,LOW);
    digitalWrite(pinOut8,LOW);
    state1=9;
 }

 if(state1==9){
  state=0;
  state1=0;
 }
 }
 
