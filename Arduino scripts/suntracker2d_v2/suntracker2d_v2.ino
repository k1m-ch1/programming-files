int bottomState;
int topState;
byte angle = 0;

#define SHORT_WAIT 100
#define LONG_WAIT 300

#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myservo.attach(9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  topState = analogRead(A0);
  bottomState = analogRead(A1);
  Serial.print(angle);
  Serial.print(", ");
  Serial.print(topState);
  Serial.print(", ");
  Serial.println(bottomState);
  if (topState < bottomState){
    angle -= 1;
    delay(SHORT_WAIT);
  }
  else if (topState > bottomState){
    angle += 1;
    delay(SHORT_WAIT);
  }

  if (angle < 1){
    angle = 179;
  }
  else if (angle > 179){
    angle = 1;
  }

  myservo.write(angle);
 
  
}
