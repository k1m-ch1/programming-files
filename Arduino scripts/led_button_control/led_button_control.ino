int aPin=A0;
int dPin=3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int number=analogRead(A0);
  while (number > 0){
    int number=analogRead(A0);
    digitalWrite(dPin,HIGH);
    Serial.print(number);
    Serial.println("still here");
    if (number==0){
      break;
    }
    
  }
  digitalWrite(dPin,LOW);
  

}
