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

#define NUM_OF_DIGITS 4
#define NUM_OF_SEGMENTS 7
#define BEEP_TIME 75
#define BEEP_LOUDNESS 255

#define COUNTDOWN_TIME 100
int timeLeft;

const int SEGMENT_PIN_SETUP[NUM_OF_SEGMENTS] = {A, B, C, D, E, F, G};
const int DIGIT_PIN_SETUP[NUM_OF_DIGITS] = {D1, D2, D3, D4};
const unsigned long startMillis = millis();

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

String convertIntToString(int numberAsInt){
  return (String(numberAsInt/1000 % 10) + String(numberAsInt/100 % 10) + String(numberAsInt/10 % 10) + String(numberAsInt % 10)); 
}

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
    delay(5);
  }
}

void beep(unsigned long timePassed, int loudness){
  int hundreds = (timePassed%1000);
  Serial.println(hundreds);
  if (hundreds < BEEP_TIME){
    analogWrite(BUZZER_PIN, loudness);
  }
  else{
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);
  for (int i = 0; i < NUM_OF_SEGMENTS; i++){
    pinMode(SEGMENT_PIN_SETUP[i], OUTPUT);
  }
  
  for (int i = 0; i < NUM_OF_DIGITS; i++){
    pinMode(DIGIT_PIN_SETUP[i], OUTPUT);
  }
  Serial.begin(9600);
  timeLeft = COUNTDOWN_TIME;

}

void loop() {
//   put your main code here, to run repeatedly:

  unsigned long timePassed = millis() - startMillis;
  int timeLeft = COUNTDOWN_TIME - (timePassed/1000);
  beep(timePassed, BEEP_LOUDNESS);
  displayToTimer(convertIntToString(timeLeft));
}
