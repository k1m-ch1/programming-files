int redPin=3;
int greenPin=5;
int bluePin=6;
int aPin=A0;
int redI=255;
int greenI=0;
int blueI=255;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i=analogRead(A0);
  Serial.println(i);
  i=map(i,0,1024,0,255);
  analogWrite(redPin,redI);
  analogWrite(greenPin,greenI);
  analogWrite(bluePin,blueI);

}
