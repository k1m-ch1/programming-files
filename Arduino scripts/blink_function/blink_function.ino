void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  ledBlink(3,HIGH,OUTPUT,100);
  ledBlink(3,LOW,OUTPUT,100);

  
}
void ledBlink(int dPin,int state,int mode,int wait){
  pinMode(dPin,mode);
  digitalWrite(dPin,state);
  delay(wait);
  
}
