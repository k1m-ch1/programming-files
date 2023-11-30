int onInitialize=100;
int offInitialize=500;
int offPin=9;
int outPin=10;
int number;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(offPin,INPUT);
  pinMode(outPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(offPin)==1){
    number=number+1;
    Serial.println(number);
    onInitialize=constrain(onInitialize,0,offInitialize);
    if (number<onInitialize){
      digitalWrite(outPin,HIGH);
    }
    if (number>offInitialize){
      digitalWrite(outPin,LOW);
    }
    
  }
  number=0;

}
