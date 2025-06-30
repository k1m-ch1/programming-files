const int wait1 = 100;
const int wait2 = 500;
const int wait3 = 1000;
const int wait4 = 2000;
const int wait5 = 3000;

void setup() {
  // put your setup code here, to run once:
  pinMode (11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (11, HIGH);
  delay (wait5);
  digitalWrite (11, LOW);
  delay (wait5);
  digitalWrite (11, HIGH);
  delay (wait4);
  digitalWrite (11, LOW);
  delay (wait4);
  digitalWrite (11, HIGH);
  delay (wait3);
  digitalWrite (11, LOW);
  delay (wait3);
  digitalWrite (11, HIGH);
  delay (wait2);
  digitalWrite (11, LOW);
  delay (wait2);
  digitalWrite (11, HIGH);
  delay (wait1);
  digitalWrite (11, LOW);
  delay (wait1);
  digitalWrite (11, HIGH);
  delay (wait1);
  digitalWrite (11, LOW);
  delay (wait1);  
  digitalWrite (11, HIGH);
  delay (wait1);
  digitalWrite (11, LOW);
  delay (wait1);  
  digitalWrite (11, HIGH);
  delay (wait1);
  digitalWrite (11, LOW);
  delay (wait1);
  
}
