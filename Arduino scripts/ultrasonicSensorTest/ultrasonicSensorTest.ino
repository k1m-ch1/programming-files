const int echo=10;
const int trig=12;
int distance;
int duration;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  Serial.println(distance);
  delay(100);
  

}
