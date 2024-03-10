unsigned long long prevTime;
unsigned int count = 0;

void increaseCount(){
  count++;
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
  if (millis() - prevTime > 1000){
    Serial.print("Count in 1 second ");
    Serial.println(count);
    prevTime = millis();
    count = 0;
  }
  
}
