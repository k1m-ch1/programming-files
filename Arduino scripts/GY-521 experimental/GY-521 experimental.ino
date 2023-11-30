#include <Wire.h>

#define ADDRESS 0x68
#define POWER_REGISTER 0x6B
#define DATA_REGISTER 0x3B
#define ACCELEROMETER_MODE_REGISTER 0x1C
#define GYROSCOPE_MODE_REGISTER 0x1B

float acc_x, acc_y, acc_z, temperature, gy_x, gy_y, gy_z;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(ADDRESS);
  Wire.write(POWER_REGISTER);
  Wire.write(0);
  Wire.endTransmission(true);

  Wire.beginTransmission(ADDRESS);
  Wire.write(ACCELEROMETER_MODE_REGISTER);
  Wire.write(0);
  Wire.endTransmission(true);

  Wire.beginTransmission(ADDRESS);
  Wire.write(GYROSCOPE_MODE_REGISTER);
  Wire.write(0);
  Wire.endTransmission(true);    
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(ADDRESS);
  Wire.write(DATA_REGISTER);
  Wire.endTransmission(false);
  Wire.requestFrom(ADDRESS, 7 * 2, true);
  acc_x = Wire.read() << 8 | Wire.read();
  acc_y = Wire.read() << 8 | Wire.read();
  acc_z = Wire.read() << 8 | Wire.read();
  temperature = Wire.read() << 8 | Wire.read();
  gy_x = Wire.read() << 8 | Wire.read();
  gy_y = Wire.read() << 8 | Wire.read();
  gy_z = Wire.read() << 8 | Wire.read();
  scaleAccVal();
  scaleGyVal();
  Serial.print("Accelerometer: ");
  Serial.print(acc_x);
  Serial.print(", ");
  Serial.print(acc_y);
  Serial.print(", ");
  Serial.print(acc_z);
  Serial.println();
  Serial.print("Temperature: ");
  Serial.print(temperature/340.0 + 36.53);
  Serial.println();
  Serial.print("Gyroscope: ");
  Serial.print(gy_x);
  Serial.print(", ");
  Serial.print(gy_y);
  Serial.print(", ");
  Serial.println(gy_z);
  Serial.println("---------------------------------------------");
  delay(1000);
}

void scaleAccVal(){
  acc_x = acc_x / 16384.0;
  acc_y = acc_y / 16384.0;
  acc_z = acc_z / 16384.0;
}

void scaleGyVal(){
  gy_x = gy_x / 131.0;
  gy_y = gy_y / 131.0;
  gy_z = gy_z / 131.0;
}

