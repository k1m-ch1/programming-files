
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int number=0;number>-1;number=number+2){
    Serial.println(number);
    if (number>1000){
      break;
    }
  }

}
