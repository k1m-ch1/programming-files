char receiveValue;
int led=13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()>0){
    receiveValue=Serial.read();
    Serial.println(receiveValue);
    if(receiveValue=='0'){
      digitalWrite(led,LOW);
    }
    if(receiveValue=='1'){
      digitalWrite(led,HIGH);
    }
  }

}
