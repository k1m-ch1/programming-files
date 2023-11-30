int in1=3;
int in2=4;
int in3=5;
int in4=6;
char input_char;
void setOutput(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void moveForward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void moveRight(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void moveBackward(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void moveLeft(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void stop(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setOutput();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    input_char=Serial.read();
    if(input_char=='0'){
      stop();
    }
    if(input_char=='1'){
      moveForward();
    }
    if(input_char=='2'){
      moveRight();
    }
    if(input_char=='3'){
      moveBackward();
    }
    if(input_char=='4'){
      moveLeft();
    }
  }
}
