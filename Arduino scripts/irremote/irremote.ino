#include <IRremote.h>
int IRpin=11;
int dPin1=3;
int dPin2=4;
int dPin3=5;
IRrecv IR(IRpin);
decode_results results;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(dPin1,OUTPUT);
  pinMode(dPin2,OUTPUT);
  pinMode(dPin3,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(IR.decode(&results)==0){
    
  }
  Serial.println(results.value,HEX);
  IR.resume();
  if(results.value==0xFF30CF){
    digitalWrite(dPin1,HIGH);
  }
  if(results.value==0xFF18E7){
    digitalWrite(dPin1,HIGH);
    digitalWrite(dPin2,HIGH);
  }
  if(results.value==0xFF7A85){
    digitalWrite(dPin3,HIGH);
    digitalWrite(dPin2,HIGH);
    digitalWrite(dPin1,HIGH);
  }
  if(results.value==0xFF6897){
    digitalWrite(dPin1,LOW);
    digitalWrite(dPin2,LOW);
    digitalWrite(dPin3,LOW);
  }
  delay(1500);



}
