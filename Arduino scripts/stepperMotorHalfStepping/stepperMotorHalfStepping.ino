int eMagnet1=2;
int eMagnet2=3;
int eMagnet3=4;
int eMagnet4=5;
int step;
int a=1;
void spinMotor(int eMagnetEnergize, bool direction){
  if(direction==1){
    switch (eMagnetEnergize){
      case 1:
      digitalWrite(eMagnet1,HIGH);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 2:
      digitalWrite(eMagnet1,HIGH);
      digitalWrite(eMagnet2,HIGH);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 3:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,HIGH);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 4:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,HIGH);
      digitalWrite(eMagnet3,HIGH);
      digitalWrite(eMagnet4,LOW);
      break;
      case 5:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,HIGH);
      digitalWrite(eMagnet4,LOW);
      break;
      case 6:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,HIGH);
      digitalWrite(eMagnet4,HIGH);
      break;
      case 7:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,HIGH);
      break;
      case 8:
      digitalWrite(eMagnet1,HIGH);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,HIGH);
      break;
    }
  }
  else if(direction==0){
    switch(eMagnetEnergize){
    case 8:
      digitalWrite(eMagnet1,HIGH);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 7:
      digitalWrite(eMagnet1,HIGH);
      digitalWrite(eMagnet2,HIGH);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 6:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,HIGH);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,LOW);
      break;
      case 5:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,HIGH);
      digitalWrite(eMagnet3,HIGH);
      digitalWrite(eMagnet4,LOW);
      break;
      case 4:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,HIGH);
      digitalWrite(eMagnet4,LOW);
      break;
      case 3:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,HIGH);
      digitalWrite(eMagnet4,HIGH);
      break;
      case 2:
      digitalWrite(eMagnet1,LOW);
      digitalWrite(eMagnet2,LOW);
      digitalWrite(eMagnet3,LOW);
      digitalWrite(eMagnet4,HIGH);
      break;
      case 1:
      digitalWrite(eMagnet1,HIGH);
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
 if(Serial.available()>0){
    step=Serial.parseInt();
    while(step>0){
      spinMotor(a,1);
      delay(1);
      step--;
      a++;
      if(a>=9){
        a=1;
      }
    }
  }
  while(Serial.available()<=0){
    Serial.println("  INPUT STEPS");
  }
}
