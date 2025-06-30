#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SH1106.h>
#include <Wire.h>
#include <SPI.h>
int xAxis=A6;
int yAxis=A7;
int numberForArray=0;
int pwm=100;
int degree90=300;
int degree180=1000;
int stopDistance=25;
bool state=0;
int increaseMargin=5;
unsigned int direction=4;
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
  infoDisplay();
}

void loop() {
  while(analogRead(yAxis)<341){
    if(numberForArray>=4){
      numberForArray=-1;
    }
    for(int i=0; i<800; i++){
      if(analogRead(yAxis)>341){
        break;
      }
      delay(1);
    }
    numberForArray++;
    Serial.println(numberForArray);
    infoDisplay();
  }
  while(analogRead(yAxis)>642){
    if(numberForArray<=0){
      numberForArray=5;
    }
    for(int i=0; i<800;i++){
      if(analogRead(yAxis)<642){
        break;
      }
      delay(1);
    }
    numberForArray--;
    infoDisplay();
  }
  switch (numberForArray){
    case 0:
    while(analogRead(xAxis)<341){
    if(increaseMargin>100){
      increaseMargin=100;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    increaseMargin++;
    infoDisplay();
  }
  while(analogRead(xAxis)>642){
    if(increaseMargin<2){
      increaseMargin=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    increaseMargin--;
    infoDisplay();
  }
    break;
    case 1:
    while(analogRead(xAxis)<341){
    if(stopDistance>50){
      stopDistance=50;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    stopDistance=stopDistance+increaseMargin;
    if(stopDistance>50){
      stopDistance=50;
      break;
    }
    infoDisplay();
  }
  while(analogRead(xAxis)>642){
    if(stopDistance<2){
      stopDistance=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    stopDistance=stopDistance-increaseMargin;
    if(stopDistance<2){
      stopDistance=1;
      break;
    }
    infoDisplay();
   }
   break;
   case 2:
   while(analogRead(xAxis)<341){
    if(pwm>254){
      pwm=255;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    pwm=pwm+increaseMargin;
    if(pwm>254){
      pwm=255;
      break;
    }
    infoDisplay();
  }
  while(analogRead(xAxis)>642){
    if(pwm<2){
      pwm=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    pwm=pwm-increaseMargin;
    if(pwm<2){
      pwm=1;
      break;
    }
    infoDisplay();
  }
  break;
  case 3:
  while(analogRead(xAxis)<341){
    if(degree90>1000){
      degree90=1000;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    degree90=degree90+increaseMargin;
    if(degree90>1000){
      degree90=1000;
      break;
    }
    infoDisplay();
  }
  while(analogRead(xAxis)>642){
    if(degree90<2){
      degree90=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    degree90=degree90-increaseMargin;
    if(degree90<2){
      degree90=1;
      break;
    }
    infoDisplay();
  }
  break;
  case 4:
  while(analogRead(xAxis)<341){
    if(degree180>2000){
      degree180=2000;
      break;
    }
    for(int i=0; i<800; i++){
      if(analogRead(xAxis)>341){
        break;
      }
      delay(1);
    }
    degree180=degree180+increaseMargin;
    if(degree180>2000){
      degree180=2000;
      break;
    }
    infoDisplay();
  }
   while(analogRead(xAxis)>642){
    if(degree180<2){
      degree180=1;
      break;
    }
    for(int i=0; i<800;i++){
      if(analogRead(xAxis)<642){
        break;
      }
      delay(1);
    }
    degree180=degree180-increaseMargin;
    if(degree180<2){
      degree180=1;
      break;
    }
    infoDisplay();
  }
  break;
  }
  infoDisplay();


}


