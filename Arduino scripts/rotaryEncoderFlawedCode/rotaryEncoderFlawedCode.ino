int waveA=2;
int waveB=3;
int count=0;
int state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(waveA,INPUT);
  pinMode(waveB,INPUT);
  state=digitalRead(waveA);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(waveA)==1&digitalRead(waveB)==0){
    delay(50);
    if(digitalRead(waveA)==1&digitalRead(waveB)==1){
      count++;
    }
    if(digitalRead(waveA)==0&digitalRead(waveB)==0){
      count--;
    }
  }
  if(digitalRead(waveA)==0&digitalRead(waveB)==1){
    delay(50);
    if(digitalRead(waveA)==1&digitalRead(waveB)==1){
      count--;
    }
    if(digitalRead(waveA)==0&digitalRead(waveB)==0){
      count++;
    }
  }
  delay(1);
  Serial.print(count);
  Serial.print(",");
  Serial.println(state);
}
