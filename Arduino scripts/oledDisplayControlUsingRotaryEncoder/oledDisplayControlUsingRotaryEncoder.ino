#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SH1106.h>
#include <Wire.h>
#include <SPI.h>
int switchPin=7;
int buttonState=0;
int buttonStateAlter=0;
unsigned int numberForArray=0;
unsigned int pwm=100;
unsigned int degree90=300;
unsigned degree180=1000;
int stopDistance=25;
int state=0;
int increaseMargin=5;
int direction=4;
const int clockPin=3;
const int dtPin=4;
int previousState;
int currentState;
int cursorPointingAt[5]={10,20,30,40,50};
Adafruit_SH1106 display(4);
void infoDisplay(){
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(80,0);
  switch (state){
    case 0:
    display.print("OFF");
    break;
    case 1:
    display.print("ON");
    break;
  }
  display.setTextSize(1);
  int yCord=cursorPointingAt[numberForArray];
  display.setCursor(0,yCord);
  display.print(">");
  display.setCursor(8,0);
  switch (direction){
    case 0:
    display.print("STOP");
    break;
    case 1:
    display.print("FORWARD");
    break;
    case 2:
    display.print("RIGHT");
    break;
    case 3:
    display.print("BACKWARD");
    break;
    case 4:
    display.print("LEFT");
    break;
  }
  display.setCursor(8,10);
  display.print("+");
  display.print(increaseMargin);
  display.setCursor(8,20);
  display.print("STOP:  ");
  display.print(stopDistance);
  display.setCursor(8,30);
  display.print("MOTOR SPEED: ");
  display.print(pwm);
  display.setCursor(8,40);
  display.print("DEGREE 90:   ");
  display.print(degree90);
  display.setCursor(8,50);
  display.print("DEGREE 180:  ");
  display.print(degree180);
  display.display();


}




void setup() {
  // put your setup code here, to run once:
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);
  pinMode(switchPin,INPUT_PULLUP);
  pinMode(clockPin,INPUT);
  pinMode(dtPin,INPUT);
  infoDisplay();  
  previousState=digitalRead(clockPin);
}

void loop() {

 currentState=digitalRead(clockPin);
  if(currentState!=previousState){
    if(digitalRead(dtPin)!=currentState){
      if(numberForArray<4){
        numberForArray++;
        infoDisplay();
      }
    }
    else if(digitalRead(dtPin)==currentState){
      if(numberForArray>0){
        numberForArray--;
        infoDisplay();
      }
    }
  }
  previousState=currentState;
if(digitalRead(switchPin)==1){
  buttonStateAlter=1;
}
if(digitalRead(switchPin)==0&buttonStateAlter==1){
  buttonState=1;
}

while(digitalRead(switchPin)==0){
  currentState=digitalRead(clockPin);
  if(currentState!=previousState){
    if(digitalRead(dtPin)!=currentState){
      increaseMargin++;
      infoDisplay();
    }
    else if(digitalRead(dtPin)==currentState){
      increaseMargin--;
      infoDisplay();
    }
   previousState=currentState;
  }
  infoDisplay();
}
}