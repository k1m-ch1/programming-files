dPin=11
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(dPin, OUTPUT);
}

void loop() {
number=analogRead(A0);
if(number>506){
  digitalWrite(dPin, HIGH);
}else{
  digitalWrite(dPin, LOW);
  
}

}
