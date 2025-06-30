bool bottomState;
bool topState;
byte angle = 0;

#define SHORT_WAIT 15
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
  topState = digitalRead(A0);
  bottomState = digitalRead(A1);
  if (!topState && !bottomState){
    if (angle > 90){
      angle = 45;
    }
    else{
      angle = 45 + 90;
    }
    delay(LONG_WAIT);
  }
  else if (topState && !bottomState){
    angle += 1;
    delay(SHORT_WAIT);
  }
  else if (bottomState && !topState){
    angle -= 1;
    delay(SHORT_WAIT);
  }
  if (angle < 1){
    angle = 1;

  }
  if (angle > 179){
    angle = 179;
  }
  myservo.write(angle);
  Serial.print(angle);
  Serial.print(", ");
  Serial.print(topState);
  Serial.print(", ");
  Serial.println(bottomState);
  
}
