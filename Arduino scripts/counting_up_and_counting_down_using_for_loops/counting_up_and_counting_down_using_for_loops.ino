int rampTime=10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("counting to 100 and counting down to 0");

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int number=1;number<100;number=number+1){
    Serial.print("your number plus one is: ");
    Serial.println(number);
    delay(rampTime);
  }
  for(unsigned number1=100;number1<1000;number1=number1-1){
    Serial.print("your number minus one is: ");
    Serial.println(number1);
    delay(rampTime);
  }

}
