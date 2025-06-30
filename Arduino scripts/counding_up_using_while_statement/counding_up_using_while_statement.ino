int number=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  while(number<1000){
    if (number>10){
    break;}
    number=number+1;
    Serial.println(number);
    delay(1000);

    }
  }
