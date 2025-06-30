int displayPin2=2;
int displayPin3=3;
int displayPin4=4;
int displayPin5=5;
int displayPin6=6;
int displayPin7=7;
int displayPin8=8;
int displayPin9=9;

void displayNum(int nums, boolean state,int wait){
  switch (nums) {
    case 1:
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin7,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 2:
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 4:
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin7,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 5:
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 6:
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 7:
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin7,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 8:
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 9:
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 0:
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 10:
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,state);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 3:
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    

  }
}
void displayChar(char alphabet, int state, int wait){
  switch (alphabet){
    case 'a':
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,0);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'b':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
  break;
  case 'c':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,0);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,0);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'd':
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,0);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'e':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,0);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'f':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,0);
    digitalWrite(displayPin8,0);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'g':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,0);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'h':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,0);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'H':
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,0);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'i':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,0);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,0);
    digitalWrite(displayPin8,0);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'j':
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,0);
    digitalWrite(displayPin5,0);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'l':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,0);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,0);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'n':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,0);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,0);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'o':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,0);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'p':
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,0);
    digitalWrite(displayPin8,0);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'q':
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,0);
    digitalWrite(displayPin9,0);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'r':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,0);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,0);
    digitalWrite(displayPin8,0);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 's':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,state);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,0);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 't':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,0);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'u':
    digitalWrite(displayPin2,0);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,0);
    digitalWrite(displayPin5,0);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,state);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
    case 'y':
    digitalWrite(displayPin2,state);
    digitalWrite(displayPin3,0);
    digitalWrite(displayPin4,state);
    digitalWrite(displayPin5,state);
    digitalWrite(displayPin6,0);
    digitalWrite(displayPin7,state);
    digitalWrite(displayPin8,state);
    digitalWrite(displayPin9,0);
    if (wait>0){
      delay(wait);
      digitalWrite(displayPin2,0);
      digitalWrite(displayPin3,0);
      digitalWrite(displayPin4,0);
      digitalWrite(displayPin5,0);
      digitalWrite(displayPin6,0);
      digitalWrite(displayPin7,0);
      digitalWrite(displayPin8,0);
      digitalWrite(displayPin9,0);
    }
    break;
  }
}
char alphabet[21]={'a','b','c','d','e','f','g','h','H','i','j','l','n','o','p','q','r','s','t','u','y'};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  for(int i=0; i<10; i++){
    char statementNums[50];
    sprintf(statementNums,"THE PRINTED NUMBER IS: %i", i);
    Serial.println(statementNums);    
    displayNum(i,1,1500);
  }
  for(int i=0;i<21;i++){
    char statementChar[50];
    char character= alphabet[i];
    sprintf(statementChar,"THE DISPLAYED CHARACTER IS: %c", character);
    Serial.println(statementChar);

    displayChar(character,1,1000);
  }
}
