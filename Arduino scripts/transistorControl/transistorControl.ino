void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  analogWrite(9, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valueRn = map(analogRead(A0), 0, 1023, 0, 255);
  analogWrite(9, valueRn);
  Serial.println(analogRead(A0));
}
