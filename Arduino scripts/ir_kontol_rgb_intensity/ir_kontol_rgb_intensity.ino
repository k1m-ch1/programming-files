#include <IRremote.h>
int redPin=9;
int greenPin=5;
int bluePin=6;
int redIntensity;
int blueIntensity;
int greenIntensity;
int state;
int state1;
IRrecv IRkontol(11);
decode_results results;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  IRkontol.enableIRIn();

}

void loop() {
  // put your main code here, to run repeatedly:
  while(IRkontol.decode(&results)==0){
    
  }
  if(results.value==0xFF30CF){
    redIntensity=redIntensity+10;
    redIntensity=constrain(redIntensity,0,255);
    analogWrite(redPin,redIntensity);
    Serial.print("RED BRIGHTNESS: ");
    Serial.print(redIntensity);
    Serial.print(",");
    Serial.print("GREEN BRIGHTNESS: ");
    Serial.print(greenIntensity);
    Serial.print(",");
    Serial.print("BLUE BRIGHTNESS:  ");
    Serial.println(blueIntensity);
  }
  if(results.value==0xFF10EF){
    redIntensity=redIntensity-10;
    redIntensity=constrain(redIntensity,0,255);
    analogWrite(redPin,redIntensity);
    Serial.print("RED BRIGHTNESS: ");
    Serial.print(redIntensity);
    Serial.print(",");
    Serial.print("GREEN BRIGHTNESS: ");
    Serial.print(greenIntensity);
    Serial.print(",");
    Serial.print("BLUE BRIGHTNESS:  ");
    Serial.println(blueIntensity);
    
  }
  if(results.value==0xFF18E7){
    greenIntensity=greenIntensity+10;
    greenIntensity=constrain(greenIntensity,0,255);
    analogWrite(greenPin,greenIntensity);
    Serial.print("RED BRIGHTNESS: ");
    Serial.print(redIntensity);
    Serial.print(",");
    Serial.print("GREEN BRIGHTNESS: ");
    Serial.print(greenIntensity);
    Serial.print(",");
    Serial.print("BLUE BRIGHTNESS:  ");
    Serial.println(blueIntensity);
  }
  if(results.value==0xFF38C7){
    greenIntensity=greenIntensity-10;
    greenIntensity=constrain(greenIntensity,0,255);
    analogWrite(greenPin,greenIntensity);
    Serial.print("RED BRIGHTNESS: ");
    Serial.print(redIntensity);
    Serial.print(",");
    Serial.print("GREEN BRIGHTNESS: ");
    Serial.print(greenIntensity);
    Serial.print(",");
    Serial.print("BLUE BRIGHTNESS:  ");
    Serial.println(blueIntensity);
  }
  if(results.value==0xFF7A85){
    blueIntensity=blueIntensity+10;
    blueIntensity=constrain(blueIntensity,0,255);
    analogWrite(bluePin,blueIntensity);
    Serial.print("RED BRIGHTNESS: ");
    Serial.print(redIntensity);
    Serial.print(",");
    Serial.print("GREEN BRIGHTNESS: ");
    Serial.print(greenIntensity);
    Serial.print(",");
    Serial.print("BLUE BRIGHTNESS:  ");
    Serial.println(blueIntensity);
    
  }
  if(results.value==0xFF5AA5){
    blueIntensity=blueIntensity-10;
    blueIntensity=constrain(blueIntensity,0,255);
    analogWrite(bluePin,blueIntensity);
    Serial.print("RED BRIGHTNESS: ");
    Serial.print(redIntensity);
    Serial.print(",");
    Serial.print("GREEN BRIGHTNESS: ");
    Serial.print(greenIntensity);
    Serial.print(",");
    Serial.print("BLUE BRIGHTNESS:  ");
    Serial.println(blueIntensity);
  }
  if(results.value==0xff6897){
    redIntensity=0;
    blueIntensity=0;
    greenIntensity=0;
    analogWrite(redPin,redIntensity);
    analogWrite(greenPin,greenIntensity);
    analogWrite(bluePin,blueIntensity);
    Serial.println("ALL BRIGHTNESS SET TO 0");
  }
  if(state==0&results.value==0x9DCF5C22){
    analogWrite(redPin,255);
    analogWrite(greenPin,255);
    analogWrite(bluePin,255);
    Serial.println("ALL BRIGHTNESS SET TO HIGH BY AC REMOTE CONTROL");
  }
  Serial.println(results.value,HEX);

  IRkontol.resume();
  delay(500);
}
