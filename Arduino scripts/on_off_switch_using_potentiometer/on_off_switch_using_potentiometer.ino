int dPin=2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(dPin, OUTPUT);
}

void loop() {
int number=analogRead(A0);
if(number>506){
  digitalWrite(dPin, LOW);
}else{
  digitalWrite(dPin, HIGH);
}
Serial.println(number);
}
