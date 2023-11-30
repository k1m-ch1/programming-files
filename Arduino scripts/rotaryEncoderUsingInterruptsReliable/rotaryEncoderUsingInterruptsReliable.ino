const int clockPin=3;
const int dtPin=4;
int previousState;
int currentState;
int count=0;
void rotaryEncoder(){
  currentState=digitalRead(clockPin);
  if(currentState!=previousState){
    if(digitalRead(dtPin)!=currentState){
      count++;
    }
    else if(digitalRead(dtPin)==currentState){
      count--;
    }
    previousState=currentState;
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(clockPin,INPUT);
  pinMode(dtPin,INPUT);
  previousState=digitalRead(clockPin);
  attachInterrupt(digitalPinToInterrupt(clockPin),rotaryEncoder,CHANGE);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(count);
  for(int i=0; i<100; i++){
    Serial.print(i);
    Serial.print("  , ");
    Serial.println(count);
    delay(100);
  }
  

}

