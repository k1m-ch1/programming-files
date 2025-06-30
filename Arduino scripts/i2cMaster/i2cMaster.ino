#include <Wire.h>

#define SLAVE_ADDRESS 9
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();

  Serial.println("Receiving data...");

  Wire.requestFrom(SLAVE_ADDRESS, 2);
  int data = 0;
  while (Wire.available() > 0){
    int b = Wire.read();
    int c = Wire.read();
    Serial.print(b);
    Serial.print(c);
    Serial.println();
  }
  Serial.println(data);
}
