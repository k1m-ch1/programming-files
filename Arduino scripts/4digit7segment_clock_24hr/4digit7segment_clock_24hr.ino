int pinA = 12;
int pinB = 8;
int pinC = 4;
int pinD = 6;
int pinE = 7;
int pinF = 11;
int pinG = 3;
int pinDP = 5;
int switch1 = 2;
int switch10 = 9;
int switch100 = 10;
int switch1000 = 13;
void displayNum(int num, int digit, int state) {
  switch (num) {
    case 0:
      digitalWrite(pinA, state);
      digitalWrite(pinB, state);
      digitalWrite(pinC, state);
      digitalWrite(pinD, state);
      digitalWrite(pinE, state);
      digitalWrite(pinF, state);
      digitalWrite(pinG, 0);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
    case 1:
      digitalWrite(pinA, 0);
      digitalWrite(pinB, state);
      digitalWrite(pinC, state);
      digitalWrite(pinD, 0);
      digitalWrite(pinE, 0);
      digitalWrite(pinF, 0);
      digitalWrite(pinG, 0);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
    case 2:
      digitalWrite(pinA, state);
      digitalWrite(pinB, state);
      digitalWrite(pinC, 0);
      digitalWrite(pinD, state);
      digitalWrite(pinE, state);
      digitalWrite(pinF, 0);
      digitalWrite(pinG, state);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
    case 3:
      digitalWrite(pinA, state);
      digitalWrite(pinB, state);
      digitalWrite(pinC, state);
      digitalWrite(pinD, state);
      digitalWrite(pinE, 0);
      digitalWrite(pinF, 0);
      digitalWrite(pinG, state);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
    case 4:
      digitalWrite(pinA, 0);
      digitalWrite(pinB, state);
      digitalWrite(pinC, state);
      digitalWrite(pinD, 0);
      digitalWrite(pinE, 0);
      digitalWrite(pinF, state);
      digitalWrite(pinG, state);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
    case 5:
      digitalWrite(pinA, state);
      digitalWrite(pinB, 0);
      digitalWrite(pinC, state);
      digitalWrite(pinD, state);
      digitalWrite(pinE, 0);
      digitalWrite(pinF, state);
      digitalWrite(pinG, state);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
    case 6:
      digitalWrite(pinA, state);
      digitalWrite(pinB, 0);
      digitalWrite(pinC, state);
      digitalWrite(pinD, state);
      digitalWrite(pinE, state);
      digitalWrite(pinF, state);
      digitalWrite(pinG, state);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
    case 7:
      digitalWrite(pinA, state);
      digitalWrite(pinB, state);
      digitalWrite(pinC, state);
      digitalWrite(pinD, 0);
      digitalWrite(pinE, 0);
      digitalWrite(pinF, 0);
      digitalWrite(pinG, 0);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
    case 8:
      digitalWrite(pinA, state);
      digitalWrite(pinB, state);
      digitalWrite(pinC, state);
      digitalWrite(pinD, state);
      digitalWrite(pinE, state);
      digitalWrite(pinF, state);
      digitalWrite(pinG, state);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
    case 9:
      digitalWrite(pinA, state);
      digitalWrite(pinB, state);
      digitalWrite(pinC, state);
      digitalWrite(pinD, state);
      digitalWrite(pinE, 0);
      digitalWrite(pinF, state);
      digitalWrite(pinG, state);
      if (digit == 1) {
        digitalWrite(switch1, 0);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 10) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 0);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 1);
      }
      if (digit == 100) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 0);
        digitalWrite(switch1000, 1);
      }
      if (digit == 1000) {
        digitalWrite(switch1, 1);
        digitalWrite(switch10, 1);
        digitalWrite(switch100, 1);
        digitalWrite(switch1000, 0);
      }
      break;
  }
}
int secondsOnesDigit;
int secondsTensDigit;
int minuteOnesDigit = 0;
int minuteTensDigit = 0;
int hourOnesDigit = 0;
int hourTensDigit = 0;
int state = 1;
unsigned long restriction = 1;
int numDisplay[4] = { 0, 0, 0, 0 };
int digitDisplay[4] = { 1, 10, 100, 1000 };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  pinMode(switch1, OUTPUT);
  pinMode(switch10, OUTPUT);
  pinMode(switch100, OUTPUT);
  pinMode(switch1000, OUTPUT);
  state = 1;
  while (Serial.available() <= 0) {
    if (state == 1) {
      Serial.println("INPUT THE ONES DIGIT OF MINUTE");
      state = 0;
    }
    delay(1000);
  }
  minuteOnesDigit = Serial.parseInt();
  Serial.read();
  Serial.read();
  state = 1;
  while (Serial.available() <= 0) {
    if (state == 1) {
      Serial.println("INPUT THE TENS DIGIT OF MINUTE");
      state = 0;
    }
    delay(1000);
  }
  minuteTensDigit = Serial.parseInt();
  Serial.read();
  Serial.read();
  state = 1;
  while (Serial.available() <= 0) {
    if (state == 1) {
      Serial.println("INPUT THE ONES DIGIT OF HOURS");
      state = 0;
    }
    delay(1000);
  }
  hourOnesDigit = Serial.parseInt();
  Serial.read();
  Serial.read();
  state = 1;
  while (Serial.available() <= 0) {
    if (state == 1) {
      Serial.println("INPUT THE TENS DIGIT OF HOURS");
      state = 0;
    }
    delay(1000);
  }
  hourTensDigit = Serial.parseInt();
  Serial.read();
  Serial.read();
}
void loop() {
  numDisplay[0] = minuteOnesDigit;
  numDisplay[1] = minuteTensDigit;
  numDisplay[2] = hourOnesDigit;
  numDisplay[3] = hourTensDigit;
  for (int a = 0; a < 4; a++) {
    displayNum(numDisplay[a], digitDisplay[a], 1);
    if (a == 2) {
      digitalWrite(pinDP, HIGH);
    }
    delay(5);
    digitalWrite(pinDP, LOW);
    if (millis() / 1000 >= restriction) {
      restriction = restriction + 1;
      secondsOnesDigit++;
      if (secondsOnesDigit >= 10) {
        secondsOnesDigit = 0;
        secondsTensDigit++;
        if (secondsTensDigit >= 6) {
          secondsTensDigit = 0;
          minuteOnesDigit++;
          numDisplay[0] = minuteOnesDigit;
          if (minuteOnesDigit >= 10) {
            minuteOnesDigit = 0;
            minuteTensDigit++;
            numDisplay[0] = minuteOnesDigit;
            numDisplay[1] = minuteTensDigit;
            if (minuteTensDigit >= 6) {
              minuteTensDigit = 0;
              hourOnesDigit++;
              numDisplay[1] = minuteTensDigit;
              numDisplay[2] = hourOnesDigit;
              if (hourOnesDigit >= 4 & hourTensDigit >= 2) {
                hourTensDigit = 0;
                hourOnesDigit = 0;
                numDisplay[2] = hourOnesDigit;
                numDisplay[3] = hourTensDigit;
              }
              if (hourOnesDigit >= 10) {
                hourOnesDigit = 0;
                hourTensDigit++;
                numDisplay[2] = hourOnesDigit;
                numDisplay[3] = hourTensDigit;
              }
            }
          }
        }
      }
    }
  }
}