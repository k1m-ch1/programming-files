int dPin=3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int input=Serial.parseInt();
  Serial.println(input);
  if (input==0){
    digitalWrite(LED_BUILTIN,HIGH);
  }
  else if(input==1){
    digitalWrite(LED_BUILTIN,LOW);
  }
  delay(10000);
  

}
