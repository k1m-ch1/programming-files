 int redPin=3;
int greenPin=5;
int bluePin=6;
int analogPin=0;
int wait=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (unsigned int redI=0;redI<255;redI++){
    analogWrite(redPin,redI);
    delay(wait);
  }
  for(unsigned int redI=254; redI<255;redI--){
    analogWrite(redPin,redI);
    delay(wait);
  }
    for(unsigned int blueI=0; blueI<255;blueI++){
    analogWrite(bluePin,blueI);
    delay(wait);
  }
    for(unsigned int blueI=254; blueI<255;blueI--){
    analogWrite(bluePin,blueI);
    delay(wait);
  }
    for(unsigned int greenI=0; greenI<255;greenI++){
    analogWrite(greenPin,greenI);
    delay(wait);
  }
    for(unsigned int greenI=254; greenI<255;greenI--){
    analogWrite(greenPin,greenI);
    delay(wait);
  }

}
