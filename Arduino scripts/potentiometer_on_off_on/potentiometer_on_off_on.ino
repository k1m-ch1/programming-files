int aPin=0;
int dPin=3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int number=analogRead(aPin);
  Serial.print(number);
  int number2=map( number, 0,1024,0,255);
  if (number2<75||number2>200){
    Serial.println("  on");
    digitalWrite(dPin,HIGH);
  }else{
    Serial.println("  off");
    digitalWrite(dPin,LOW);
  }
  

}
