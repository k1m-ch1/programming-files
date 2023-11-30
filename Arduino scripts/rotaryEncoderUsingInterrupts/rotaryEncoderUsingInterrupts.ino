int waveA=2;
int waveB=3;
int count=0;
void risingFunction(void){
  if(digitalRead(waveA)==1&digitalRead(waveB)==0){
    count++;
  }
  if(digitalRead(waveA)==1&digitalRead(waveB)==1){
    count--;
  }
}
void fallingFunction(){
  if(digitalRead(waveA)==0&digitalRead(waveB)==1){
    count++;
  }
  if(digitalRead(waveA)==0&digitalRead(waveB)==0){
    count--;
  }

}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(waveA,INPUT);
  pinMode(waveB,INPUT);
  attachInterrupt(digitalPinToInterrupt(waveA),risingFunction,RISING);
  attachInterrupt(digitalPinToInterrupt(waveB),fallingFunction,FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(count);

}
