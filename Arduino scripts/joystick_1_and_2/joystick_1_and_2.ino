int aPin1=0;
int aPin2=1;
int aPin3=2;
int aPin4=3;
int aPin5=4;  //potentiometer readings
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(aPin1));
  Serial.print(",");
  Serial.print(analogRead(aPin2));
  Serial.print(",");
  Serial.print(analogRead(aPin3));
  Serial.print(",");
  Serial.print(analogRead(aPin4));
  Serial.print(",");
  Serial.println(analogRead(aPin5));
  delay(1000);
  
  

}
