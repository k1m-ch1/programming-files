int aPin=A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int number = analogRead(A0);
  int reading = map(number,0,1023,-50,150);
  Serial.println(reading);

}
