int state;
int state1=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(state1==0){
    state=0;
  }
  while (state==0 & digitalRead(4)==1){
    digitalWrite(3,1);
    state1=1;
  }
  if(state1==1){
    state=1;
  }
  while (state==1 & digitalRead(4)==1){
    digitalWrite(3,0);
    state1=0;
  }
  

}
