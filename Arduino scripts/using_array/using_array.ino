
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int pin[3]={2,4,6};
  for (int i=0; i<3; i++){
    digitalWrite(pin[i],HIGH);
    delay(1000);
    digitalWrite(pin[i] ,LOW);
  }
  

}
