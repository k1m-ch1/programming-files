#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SH1106.h>
Adafruit_SH1106 display(4);
void printText(int x, int y, String text){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(x,y);
  display.print(text);
  display.display();
}
void printNum(int x, int y,int num){
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(x, y);
  display.print(num);
  display.display();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<90; i++){
    printText(i,0,"HEWWO");
  }
  for(int i=90; i>0;i--){
    printText(i,0,"HEWWO");    
  }
  for(int i=0;i<55; i++){
    printText(0,i,"HEWWO");
  }
  for(int i=55;i>0; i--){
    printText(0,i,"HEWWO");
  }
  for(int i=0;i<50; i++){
    printText(i*2,i,"HEWWO");
  }
  for(int i=50;i>0;i--){
    printText(i*2,i,"HEWWO");
  }
  


}
