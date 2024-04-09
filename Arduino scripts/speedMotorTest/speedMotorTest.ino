unsigned int prevTime;
unsigned int count = 0;
unsigned int sampleRate = 10; //sample rate in sample per seconds

void increaseCount(){
  count++;
  // Serial.println("increased");
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), increaseCount, RISING);
  prevTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - prevTime > 1000/sampleRate){
  //  Serial.print("Count in 1 second ");
   Serial.println(count*(millis() - prevTime));
    prevTime = millis();
    count = 0;
  }
  
}
