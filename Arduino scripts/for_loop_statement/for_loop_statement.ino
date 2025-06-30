
int rampTime = 100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("COUNTING TO 100");
  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=1; i<100; i++){
  Serial.print("number now: ");
  Serial.println(i);
  delay(rampTime=100);
  }
  Serial.println("resetting");
  delay(rampTime);
 
  
}
 
