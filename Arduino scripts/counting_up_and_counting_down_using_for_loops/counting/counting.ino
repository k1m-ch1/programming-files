
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int number=0;number<100;number++){
    Serial.print("your number is: ");
    Serial.println(number);
  }
  for(unsigned int number=100;number<1000;number--){
    Serial.print("your number is: ");
    Serial.println(number);
  }

}
