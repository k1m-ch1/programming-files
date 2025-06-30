const int wait1 = 32;
const int redOn = 5000;
const int yellowOn = 2000;
const int greenOn = 5000;

void setup() {
  // put your setup code here, to run once:
 pinMode(11, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(11, HIGH);
 delay(redOn);
 digitalWrite(11,LOW);
 delay(wait1);
 digitalWrite(10, HIGH);
 delay(yellowOn);
 digitalWrite(10, LOW);
 delay(wait1);
 digitalWrite(9, HIGH);
 delay(greenOn);
 digitalWrite(9, LOW);
 delay(wait1);
}
