long pop=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int number=1;number>0;number++){
    pop=number*pop;
    Serial.print("the factorial of ");
    Serial.print(number);
    Serial.print(" is ");
    Serial.println(pop);
    delay(1000);
    if(pop>2147483647){
      break;}
    }
  }
