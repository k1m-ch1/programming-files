int eMagnet1=2;
int eMagnet2=3;
int eMagnet3=4;
int eMagnet4=5;
int wait=3;
//direction is a boolean, direction==1 move motor anti-clockwise, direction==0 move motor clockwise
void spinMotor(int direction,int onOff){
  if(direction==1){
    switch (onOff){
      case 1:
      digitalWrite(eMagnet1,HIGH);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 2:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,HIGH);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 3:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,HIGH);
      digitalWrite(eMagnet4,LOW);
      break;
      case 4:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,HIGH);
      break;
    }
  }
  else if(direction==0){
    switch (onOff){
      case 4:
      digitalWrite(eMagnet1,HIGH);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 3:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,HIGH);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 2:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,HIGH);
      digitalWrite(eMagnet4,LOW);
      break;
      case 1:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,HIGH);
      break;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(eMagnet1,OUTPUT);
  pinMode(eMagnet2,OUTPUT);
  pinMode(eMagnet3,OUTPUT);
  pinMode(eMagnet4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  spinMotor(1,1);
  delay(wait);
  spinMotor(1,2);
  delay(wait);
  spinMotor(1,3);
  delay(wait);
  spinMotor(1,4);
  delay(wait);

}
