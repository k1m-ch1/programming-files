#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_SH1106.h>
#include <IRremote.h>
int state=0;
int i;
unsigned int pwm=125;
unsigned int turn90Degree=300;
unsigned int turn180Degree=600;
char *myStrings[] = {"LEFT 90", "RIGHT 90", "LEFT 180",
                     "RIGHT 180", "FORWARD", "BACKWARD"
                    };
IRrecv irrecv(9);
decode_results results;
Adafruit_SH1106 display(4);
void infoDisplay(){
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0,7);
  display.print("MODE:");
  display.print(state);
  display.setTextSize(1);
  display.setCursor(0,30);
  display.print("MOTOR SPEED:");
  display.setCursor(108,30);
  display.print(pwm);
  display.setCursor(0,40);
  display.print("90 RUN TIME:");
  display.setCursor(108,40);
  display.print(turn90Degree);
  display.setCursor(0,50);
  display.print("180 RUN TIME:");
  display.setCursor(108,50);
  display.print(turn180Degree);
  display.display();
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(state==0){

    if(results.value==0xFF30CF){
      pwm=pwm+10;
      if(pwm>255){
        pwm=255;
      }
      irrecv.resume();
    }
    if(results.value==0xFF10EF){
      pwm=pwm-10;
      if(pwm>255){
        pwm=255;
      }
      irrecv.resume();
    }
    if(results.value==0xFF18E7){
      turn90Degree=turn90Degree+10;
      if(turn90Degree>5000){
        turn90Degree=5000;
      }
      irrecv.resume();
    }
    if(results.value==0xFF38C7){
      turn90Degree=turn90Degree-10;
      if(turn90Degree>5000){
        turn90Degree=5000;
      }
      irrecv.resume();
    }      
    if(results.value==0xFF7A85){
      turn180Degree=turn180Degree+10;
      if(turn180Degree>10000){
        turn180Degree=10000;
      }
      irrecv.resume();
    }
    if(results.value==0xFF5AA5){
      turn180Degree=turn180Degree-10;
      if(turn180Degree>10000){
        turn180Degree=10000;
      }
      irrecv.resume();
    }
    irrecv.resume();
  }

}
