int dPin1=3;
int dPin2=4;
int outPin1=5;
int intensity=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dPin1,INPUT);
  pinMode(dPin2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int oneInput=digitalRead(dPin1);
  while (oneInput==0){
    analogWrite(outPin1,intensity);
    if(intensity>=255){
      break;}
    Serial.println(intensity);
    intensity=intensity+1;
    delay(10);
    if(digitalRead(dPin1)==1){
      break;
    }
  }
    while (oneInput==0){
    analogWrite(outPin1,intensity);
    if(intensity>=255){
      break;}
    Serial.println(intensity);
    intensity=intensity+1;
    delay(10);
    if(digitalRead(dPin1)==1){
      break;
    }
  }
  int twoInput=digitalRead(dPin2);
    while (twoInput==0){
    analogWrite(outPin1,intensity);
    if(intensity<1){
      break;}
    Serial.println(intensity);
    intensity=intensity-1;
    delay(10);
    if(digitalRead(dPin2)==1){
      break;
    }
  }
  

}
