
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int number=Serial.parseInt();
    switch(number)
    {
    case 1:
    Serial.println("1");
    break;
    case 2:
    Serial.println("2");
    break;
    case 3:
    Serial.println("3");
    break;
    default:
    Serial.println("not 123");
    break;}
    
  

}
