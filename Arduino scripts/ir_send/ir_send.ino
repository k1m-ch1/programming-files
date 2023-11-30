
#include <IRremote.h>
IRsend irLed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()==0){
  Serial.println("press 1");
  delay(10000);
  }
  if(Serial.parseInt()==1){
    irLed.sendPanasonic(0x9DCF5C22,32);
    Serial.println("SENT");
  }
  delay(1000);

}
