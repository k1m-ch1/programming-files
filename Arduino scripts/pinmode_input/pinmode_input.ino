int dPin = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int number=digitalRead(dPin);
  Serial.println(number);
  

}
