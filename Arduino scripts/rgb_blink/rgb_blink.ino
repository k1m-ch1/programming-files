int redPin=3;
int greenPin=5;
int bluePin=6;
int aPin=0;
int wait=500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int brightness=analogRead(aPin);
  float notBrightness=map(brightness,0,1024,0,5);
  Serial.println(notBrightness);
  analogWrite(redPin,brightness);
  delay(wait);
  analogWrite(redPin,LOW);
  analogWrite(greenPin,brightness);
  delay(wait);
  analogWrite(greenPin,LOW);
  analogWrite(bluePin,brightness);
  delay(wait);
  analogWrite(bluePin,LOW);

}
