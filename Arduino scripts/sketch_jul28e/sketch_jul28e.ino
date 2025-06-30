int aPin=0;
int dPin=3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int number=analogRead(A0);number<256;number=analogRead(A0)){
    digitalWrite(dPin,HIGH);
    Serial.println(number);
    if (number>256){
      break;
    }
  }
  for(int number=analogRead(A0);number>254;number=analogRead(A0)){
    digitalWrite(dPin,LOW);
    Serial.println(number);
    if (number>512){
      break;
    }
  }
  
  for(int number=analogRead(A0);number>511;number=analogRead(A0)){
    digitalWrite(dPin,HIGH);
    if (number>768){
      break;
    }
  }
  for(int number=analogRead(A0);number>768;number=analogRead(A0)){
    digitalWrite(dPin,LOW);
    if (number>1023){
      break;
    }
  }
}
