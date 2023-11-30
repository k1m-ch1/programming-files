void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float input=Serial.parseInt();
  if (input==0){Serial.println("input numbers");}
  else{Serial.print("your number divided by 2 is: ");
  Serial.println(input/2);
  }
}
