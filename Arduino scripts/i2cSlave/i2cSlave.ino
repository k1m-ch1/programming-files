#include <Wire.h>
#define SLAVE_ADDRESS 9
#define ANSWERSIZE 5

String answer = "hello";
unsigned int a  = 0;
void setup() {
  // put your setup code here, to run once:
  Wire.begin(9);
  Serial.begin(9600);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
}

void loop() {
  // put your main code here, to run repeatedly:

    delay(50);
}

void receiveEvent(){

  while(Wire.available() > 0){
    byte x = Wire.read();
  }
}

void requestEvent(){
  Wire.write(a);
  a++;
  Serial.println(a);
}
