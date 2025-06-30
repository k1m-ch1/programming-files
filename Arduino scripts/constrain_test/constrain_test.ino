int angle1=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(angle1>0){
    angle1=constrain(angle1,0,179);
    angle1=angle1+1;
    Serial.println(angle1);
    delay(10);
  }
  Serial.println("activated");

}
