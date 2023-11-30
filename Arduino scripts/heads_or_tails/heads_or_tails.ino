
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("COIN FLIP SIMULATOR");
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.parseInt()==1){
    int i = random(1,3);
    switch (i){
      case 1:
      Serial.println("HEADS");
      break;
      case 2:
      Serial.println("TAILS");
      break;
    }
    
  }else{
    Serial.println("INPUT 1 TO FLIP");
    delay(1000);
  }

}
