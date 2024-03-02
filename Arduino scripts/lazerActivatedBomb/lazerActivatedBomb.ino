#define D4 A1
#define A A0
#define F 13
#define D3 12
#define D2 11
#define B 10
#define E 4
#define D 5
#define C 7
#define G 8
#define D1 9
#define DP 6
#define BUZZER_PIN 3
#define LIGHT_RESISTOR_PIN 2

#define NUM_OF_DIGITS 4
#define NUM_OF_SEGMENTS 7
#define BEEP_TIME 50
#define BEEP_LOUDNESS 255

#define COUNTDOWN_TIME 20


const int SEGMENT_PIN_SETUP[NUM_OF_SEGMENTS] = {A, B, C, D, E, F, G};
const int DIGIT_PIN_SETUP[NUM_OF_DIGITS] = {D1, D2, D3, D4};


String DIGIT_DISPLAY[10] = {
  "1111110", 
  "0110000",
  "1101101",
  "1111001",
  "0110011",
  "1011011",
  "1011111",
  "1110000",
  "1111111",
  "1111011"
};


String timeToDisplay = "1234";

int convertCharToInt(char digitAsChar){
  int digitAsInt = (int)digitAsChar - 48;
  return digitAsInt;
}
'0'

String convertIntToString(int numberAsInt){
  if (numberAsInt > 0){
    return (String(numberAsInt/1000 % 10) + String(numberAsInt/100 % 10) + String(numberAsInt/10 % 10) + String(numberAsInt % 10)); 
  }
  else {
    return "0000";
  }
}
"1234"
void displayToTimer(String timeToDisplay){
  for (int i = 0; i < NUM_OF_DIGITS; i++){
 
    for (int j = 0; j < NUM_OF_DIGITS; j++){
      if (j == i){
        digitalWrite(DIGIT_PIN_SETUP[j], LOW);
      }
      else {
        digitalWrite(DIGIT_PIN_SETUP[j], HIGH);
      }
    }
    int numberToDisplay = convertCharToInt(timeToDisplay[i]);
//    Serial.println(numberToDisplay);
    String pinoutLightUp = DIGIT_DISPLAY[numberToDisplay];
    for (int i = 0; i < NUM_OF_SEGMENTS; i++){
      digitalWrite(SEGMENT_PIN_SETUP[i], convertCharToInt(pinoutLightUp[i]));
    }
    delay(2);
  }
}

void turnOffDisplay(){
  for(int i = 0; i < NUM_OF_DIGITS; i++){
    digitalWrite(DIGIT_PIN_SETUP[i], HIGH);
  }
}

void beep(unsigned long timePassed, int loudness, int timesPerCycle){
  int hundreds = (timePassed%1000%(1000/timesPerCycle));
  if (hundreds < (BEEP_TIME)){
    analogWrite(BUZZER_PIN, loudness);
  }
  else{
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void activateCountDown(){
    const unsigned long startMillis = millis();
    unsigned long timePassed = millis() - startMillis;
    int timeLeft = COUNTDOWN_TIME - (timePassed/1000);
    while(timeLeft > -2){
     if (timeLeft > 10){
      beep(timePassed, BEEP_LOUDNESS, 1);
     }
     else if (timeLeft > 5){
      beep(timePassed, BEEP_LOUDNESS, 3);
     }
     else if (timeLeft > 3){
      beep(timePassed, BEEP_LOUDNESS, 5);
     }
     else if (timeLeft > 2){
      beep(timePassed, BEEP_LOUDNESS, 7);
     }
     else if (timeLeft > 1){
      beep(timePassed, BEEP_LOUDNESS, 9);
     }
     else if (timeLeft > 0){
      beep(timePassed, BEEP_LOUDNESS, 12);
     }
     else {
      beep(timePassed, BEEP_LOUDNESS, 1000/BEEP_TIME);
     }
      displayToTimer(convertIntToString(timeLeft));
      timePassed = millis() - startMillis;
      timeLeft = COUNTDOWN_TIME - (timePassed/1000);
    }
    beep(BEEP_TIME+1, BEEP_LOUDNESS, 1);
    turnOffDisplay();
}

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LIGHT_RESISTOR_PIN, INPUT);
  
  for (int i = 0; i < NUM_OF_SEGMENTS; i++){
    pinMode(SEGMENT_PIN_SETUP[i], OUTPUT);
  }
  
  for (int i = 0; i < NUM_OF_DIGITS; i++){
    pinMode(DIGIT_PIN_SETUP[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
//   put your main code here, to run repeatedly:
  if (digitalRead(LIGHT_RESISTOR_PIN) == 0){
    activateCountDown();
  }
}
