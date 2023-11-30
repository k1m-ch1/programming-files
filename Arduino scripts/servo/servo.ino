  #include <Servo.h>
  int pin=9;
  Servo deezServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  deezServo.attach(pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  deezServo.write(180);
}
