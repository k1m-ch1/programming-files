int redPin=3;
int greenPin=5;
int bluePin=6;
int wait=50;
int aPin=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float brightness=analogRead(aPin);
  Serial.println(brightness/204.6);
  analogWrite(redPin,brightness);
  delay(wait);
  analogWrite(bluePin,LOW);
  delay(wait);
  analogWrite(greenPin,brightness);
  delay(wait);
  analogWrite(redPin,LOW);
  delay(wait);
  analogWrite(bluePin,brightness);
  delay(wait);
  analogWrite(greenPin,LOW);
  delay(wait);
  

}
