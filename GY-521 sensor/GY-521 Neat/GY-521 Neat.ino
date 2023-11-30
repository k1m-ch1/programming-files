#include <Wire.h>

#define ADDRESS 0x68
#define ACCELEROMETER_MODE_REGISTER 0x1C
#define GYROSCOPE_MODE_REGISTER 0x1B
#define POWER_REGISTER 0x6B
#define ACCEL_REGISTER 0x3B
#define GYRO_REGISTER 0x43
#define TEMP_REGISTER 0x40


#define tDelay 1000

float gyroValue[3] = {0, 0, 0};
float accValue[3] = {0, 0, 0};
int temperature = 0;
byte buffer[6];
float averageGyroOffset[3] = {0, 0, 0};


void sendTo(int dataAddress, int data);
void receiveFrom(int dataAddress, int size, byte* buffer);
void printDAta();
void organiseData(byte* buffer, int size, bool acc);
void calibrateGyro(int numOfTimes);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  sendTo(POWER_REGISTER, 0);
  sendTo(ACCELEROMETER_MODE_REGISTER, 0);
  sendTo(GYROSCOPE_MODE_REGISTER, 0);
  calibrateGyro(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  receiveFrom(ACCEL_REGISTER, 6, buffer);
  organiseData(buffer, 6, true);
  receiveFrom(GYRO_REGISTER, 6, buffer);
  organiseData(buffer, 6, false);
  receiveFrom(TEMP_REGISTER, 2, buffer);
  temperature = (buffer[0] << 8 | buffer[1])/340.0 + 36.53;
  printData();
  delay(tDelay);
}

void sendTo(int dataAddress, int data){
  // Send to some data to that dataAddress
  Wire.beginTransmission(ADDRESS);
  Wire.write(dataAddress);
  Wire.write(data);
  Wire.endTransmission(true);

}

void receiveFrom(int dataAddress, int size, byte bufferLocal[]){
  // Receive from that data address
  int i = 0;
  Wire.beginTransmission(ADDRESS);
  Wire.write(dataAddress);
  Wire.endTransmission(false);
  
  Wire.requestFrom(ADDRESS, size, true);
  while (Wire.available()){
    buffer[i] = Wire.read();
    i++;
  }
}

void organiseData(byte bufferLocal[], int size, bool acc){
  // combine 2 bytes into one
  for(int i = 0; i < size/2; i++){
    if (acc == true){
      accValue[i] = (bufferLocal[2*i] << 8 | bufferLocal[2*i + 1])/16384.0;
    }else{
      gyroValue[i] = ((bufferLocal[2*i] << 8 | bufferLocal[2*i+1])/131.0) - averageGyroOffset[i];
    }
  }
}

void printData(){
  Serial.print("Accelerometer: ");
  for (int i = 0; i < 3; i++){
    Serial.print(accValue[i]);
    Serial.print(", ");
  }
  Serial.println();
  Serial.print("Temperature: ");
  Serial.print(temperature/340.0 + 36.53);
  Serial.println();
  Serial.print("Gyroscope: ");
  for (int i = 0; i < 3; i++){
    Serial.print(gyroValue[i]);
    Serial.print(", ");
  }
  Serial.println("\n---------------------------------------------");
}

void calibrateGyro(int numOfTimes){
  // Calibrates the gyroscope
  for (int i = 0; i < numOfTimes; i++){
    receiveFrom(GYRO_REGISTER, 6, buffer);
    organiseData(buffer, 6, false);
    for (int j = 0; j < 3; j++){
      averageGyroOffset[j] += gyroValue[j];
    }
  }
  Serial.print("Total Gyro Offset: ");
  for (int i = 0; i < 3; i++){
    gyroValue[i] = averageGyroOffset[i]/(float)numOfTimes;
    Serial.print(averageGyroOffset[i]);
    Serial.print(", ");
  }
  Serial.println();
}