const int clockPin=3;
const int dtPin=4;
int previousState;
int currentState;
int count=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(clockPin,INPUT);
  pinMode(dtPin,INPUT);
  previousState=digitalRead(clockPin);
  
}

void loop() {
  // put your main code here, to run repeatedly:
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
  Serial.println(count);

}
