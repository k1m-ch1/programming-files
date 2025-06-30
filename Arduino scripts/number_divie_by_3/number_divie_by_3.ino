float results;
float number1;
float number2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    number1=Serial.parseInt();
    delay(1000);
    results=number1/3;
    Serial.println(results,3);
  }

}
