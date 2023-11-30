int red1=2;
int yellow1=3;
int green1=5;
int red2=9;
int yellow2=10;
int green2=11;
int yellowDelay=2000;
int redGreenDelay=5000;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(red1, OUTPUT);
pinMode(yellow1, OUTPUT);
pinMode(green1, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(yellow2, OUTPUT);
pinMode(green2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(red1, HIGH);
digitalWrite(green2, HIGH);
Serial.println(" red1 , green2");
delay(redGreenDelay);
digitalWrite(green2, LOW);
digitalWrite(red1, HIGH);
digitalWrite(yellow2, HIGH);
delay(yellowDelay);
digitalWrite(red1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(red2, HIGH);
digitalWrite(green1, HIGH);
Serial.println("green1 , red2");
delay(redGreenDelay);
digitalWrite(yellow1,HIGH);
digitalWrite(red2, HIGH);
digitalWrite(green1, LOW); 
delay(yellowDelay);
digitalWrite(yellow1,LOW);
digitalWrite(red2,LOW);
}
