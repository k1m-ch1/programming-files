#define TRIG_PIN 9
#define ECHO_PIN 10
#define SPEED_OF_SOUND 343 //in m/s
unsigned long duration;
float distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (SPEED_OF_SOUND * duration)/(20000.0);
  Serial.println(distance);
  delay(10);
}
