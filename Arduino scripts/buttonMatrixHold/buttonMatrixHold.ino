const int r1=2;
const int r2=3;
const int r3=4;
const int r4=5;
const int c1=6;
const int c2=7;
const int c3=8;
const int c4=9;
void scanRow(int rowNum){
  switch(rowNum){
    case 1:
    digitalWrite(r1,1);
    digitalWrite(r2,0);
    digitalWrite(r3,0);
    digitalWrite(r4,0);
    break;
    case 2:
    digitalWrite(r1,0);
    digitalWrite(r2,1);
    digitalWrite(r3,0);
    digitalWrite(r4,0);
    break;
    case 3:
    digitalWrite(r1,0);
    digitalWrite(r2,0);
    digitalWrite(r3,1);
    digitalWrite(r4,0);
    break;
    case 4:
    digitalWrite(r1,0);
    digitalWrite(r2,0);
    digitalWrite(r3,0);
    digitalWrite(r4,1);
    break;
  }  
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int a=1; a<5; a++){
    scanRow(a);
    switch (a){
      case 1:
      if(digitalRead(c4)==1){
        Serial.println("1");
      }
      if(digitalRead(c3)==1){
        Serial.println("2");
      }
      if(digitalRead(c2)==1){
        Serial.println("3");
      }
      if(digitalRead(c1)==1){
        Serial.println("A");
      }
      break;
      case 2:
      if(digitalRead(c4)==1){
        Serial.println("4");
      }
      if(digitalRead(c3)==1){
        Serial.println("5");
      }
      if(digitalRead(c2)==1){
        Serial.println("6");
      }
      if(digitalRead(c1)==1){
        Serial.println("B");
      }
      break;
      case 3:
      if(digitalRead(c4)==1){
        Serial.println("7");
      }
      if(digitalRead(c3)==1){
        Serial.println("8");
      }
      if(digitalRead(c2)==1){
        Serial.println("9");
      }
      if(digitalRead(c1)==1){
        Serial.println("C");
      }
      break;
      case 4:
      if(digitalRead(c4)==1){
        Serial.println("0");
      }
      if(digitalRead(c2)==1){
        Serial.println("F");
      }
      if(digitalRead(c2)==1){
        Serial.println("E");
      }
      if(digitalRead(c1)==1){
        Serial.println("F");
      }
      break;
    }
    delay(5);
  }
}
