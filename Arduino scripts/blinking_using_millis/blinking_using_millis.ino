unsigned int intervalTimeOn=2;
unsigned int intervalTimeOff=2;
int dPin=3;
unsigned int carrotTime=0;
unsigned int carrotTime2=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long currentTime=millis()/1000;
  Serial.println(carrotTime);
  if (currentTime-carrotTime>=intervalTimeOn){
    digitalWrite(dPin,HIGH);
    carrotTime=currentTime;  
  }
  if (currentTime-carrotTime2>=intervalTimeOff){
    digitalWrite(dPin,LOW);
    carrotTime2=currentTime;
  }
  
 

}
