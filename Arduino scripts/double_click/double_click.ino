int pinIn=4;
int pinOut=3;
int state;
int state1;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinIn,INPUT);
  pinMode(pinOut,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(state==0&digitalRead(pinIn)==1){
    state1=1;
  }
  if(state1==1){
    state=1;
  }
  while(state1==1&digitalRead(pinIn)==1){
    digitalWrite(pinOut,HIGH);
    state=2;
  }
  if(state==2){
    state1=2;
  }
  while(state==2&digitalRead(pinIn)==1){
    digitalWrite(pinOut,LOW);
    state1=3;
  }
  if(state1==3){
    state=0;
    state1=0;
  }
  
 
}
