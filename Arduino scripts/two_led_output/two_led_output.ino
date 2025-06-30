int ledNo1=2;
int ledNo2=3;

void setup() {
  // put your setup code here, to run once:
 pinMode(ledNo1, OUTPUT);
 pinMode(ledNo2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(ledNo1, HIGH);
 delay(1500);
 digitalWrite(ledNo1, LOW);
 delay(1500);
 digitalWrite(ledNo2, HIGH);
 delay(1500);
 digitalWrite(ledNo2, LOW);
 delay(1500);
}
