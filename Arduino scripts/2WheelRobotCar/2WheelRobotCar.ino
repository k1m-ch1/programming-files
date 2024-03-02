#include <Servo.h>

const int servoPin = 6;
const int ENA = 11;
const int trigPin = 9;
const int echoPin = 10;
int speed = 150;
const int turnDelay = 250;
Servo servo1;

const int pins[4] = {2, 3, 4, 5};// {in1 ,in2, in3, in4}, {out3:black left, out2:green}
const bool backward[4] = {1, 0, 1, 0};
const bool straight[4] = {0, 1, 0, 1};
const bool right[4] = {1, 0, 0, 1};
const bool left[4] = {0, 1, 1,0};    
const bool stop[4] = {0, 0, 0, 0};



void move(bool instructionSet[], int speed){
  analogWrite(ENA, speed);
  for(int i = 0; i < 4; i++){
    digitalWrite(pins[i], instructionSet[i]);
  }
}

int getDistance(){
  int distance;
  unsigned long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 343 * duration/20000;
  delay(100);
  return distance; 
}

void turningSensor(){
  servo1.write(0);
  int distanceRight = getDistance();
  delay(1000);
  servo1.write(180);
  int distanceLeft = getDistance();
  delay(1000);
  servo1.write(90);
  if(distanceRight > distanceLeft){
    move(right,speed);
  }
  else if(distanceRight < distanceLeft){
    move(left, speed);
  }
  delay(turnDelay);
  move(stop, speed);
}


void setup() {
  analogWrite(ENA, 100);
  for(int i = 0; i < 4; i++){
    pinMode(pins[i], OUTPUT);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(servoPin);
  servo1.write(90);
  Serial.begin(9600);
}

void loop() {
  int distance = getDistance();
  servo1.write(90);
  Serial.println(distance);
  if(distance <= 40){
    move(backward, speed);
    delay(250);
    move(stop, speed);
    turningSensor();
  }
  else{
     move(straight, speed);
  }


}
