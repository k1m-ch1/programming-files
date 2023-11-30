//
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
int hour_offset = 0;
int minute_offset = 0;
int another_array[7] = {A, B, C, D, E, F, G};
int another_another_array[4] = {D1, D2, D3, D4};
int setup_array[12] = {A, B, C, D, E, F, G, D1, D2, D3, D4, DP};
String numberOne = "0110000";
String numberTwo = "1101101";
String numberThree = "1111001";
String numberFour = "0110011";
String numberFive = "1011011";
String numberSix = "1011111";
String numberSeven = "1110000";
String numberEight = "1111111";
String numberNine = "1111011";
String numberZero = "1111110";
String str_array[10] = {numberZero, numberOne, numberTwo, numberThree, numberFour, numberFive, numberSix, numberSeven, numberEight, numberNine};

void evaluateData(String numberFormat, int digit){
  digit = digit - 1;
  for(int i = 0; i < 4; i++){
    if(digit == i){
      digitalWrite(another_another_array[i], LOW);
    }else{
      digitalWrite(another_another_array[i], HIGH);
    }
  }
  for(int i = 0; i < 7; i++){
    if(numberFormat[i] == '1'){
      digitalWrite(another_array[i], HIGH);
    }else{
      digitalWrite(another_array[i], LOW);
    }
  }
}

#define AMT_TIME 19
#define OUTPUT_PIN A5

String timeOfRinging[AMT_TIME] = {"0750", "0800", "0850", "0900", "0950", "1000", "1050", "1100", "1150", "1200", "1250", "1300", "1350", "1400", "1450", "1500", "1550", "1600", "1650"};

void ringBell(int minute, int hour){
  for(int i = 0; i < AMT_TIME; i++){
    int temp_hour = ((int)timeOfRinging[i][1] - 48) + ((int)timeOfRinging[i][0] - 48)*10;
    int temp_minute = ((int)timeOfRinging[i][3] - 48) + ((int)timeOfRinging[i][2] - 48)*10;
    if(minute == temp_minute && hour == temp_hour){
      pinMode(OUTPUT_PIN, OUTPUT);
      digitalWrite(OUTPUT_PIN, HIGH);
      delay(2000);
      digitalWrite(OUTPUT_PIN, LOW);
      delay(2000);
      digitalWrite(OUTPUT_PIN, HIGH);
      delay(2000);
      digitalWrite(OUTPUT_PIN, LOW);
      int overall_delay = 2;
      //delay(100000);
      delay(60000);//change7
      return;
    }
  }
  return;
}

int overall_delay = 2;

void offset_hour_increase(){
  hour_offset = hour_offset + 1;
  delay(1000);
}

void offset_hour_decrease(){
  hour_offset = hour_offset + 23;
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 12; i++){
    pinMode(setup_array[i], OUTPUT);
  }
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  bool flag = true;
  while (flag == true){
    unsigned long total_minutes = (int)(((int)(millis()/1000))/60);
    int minute = (total_minutes + minute_offset) % 60;
    int hour = (((total_minutes + minute_offset) / 60) + hour_offset) % 24;
    evaluateData(str_array[minute%10], 1);
    delay(2);
    if(digitalRead(2) == 1){
      delay(500);
      minute_offset++;
    }
    if(digitalRead(3) == 1){
      flag = false;
    }
  }
  delay(1000);
  flag = true;
  while (flag == true){
    unsigned long total_minutes = (int)(((int)(millis()/1000))/60);
    int minute = (total_minutes + minute_offset) % 60;
    int hour = (((total_minutes + minute_offset) / 60) + hour_offset) % 24;
    evaluateData(str_array[minute/10], 2);
    delay(2);
    if(digitalRead(2) == 1){
      minute_offset = minute_offset + 10;
      delay(500);
    }
    if(digitalRead(3) == 1){
      flag = false;
    }
  }
  attachInterrupt(digitalPinToInterrupt(2), offset_hour_increase, RISING);
  attachInterrupt(digitalPinToInterrupt(3), offset_hour_decrease, RISING);
}
int minute = 0;
int hour = 0;

void loop() {
  unsigned long total_seconds = millis()/1000;
  unsigned long total_minutes = total_seconds/60; 
  minute = (total_minutes + minute_offset) % 60;
  hour = (((total_minutes + minute_offset) / 60) + hour_offset) % 24;
  ringBell(minute, hour);
  evaluateData(str_array[minute%10], 1);
  delay(overall_delay);
  digitalWrite(DP, LOW);
  evaluateData(str_array[minute/10], 2);
  digitalWrite(DP, LOW);
  delay(overall_delay);
  evaluateData(str_array[hour%10], 3);
  digitalWrite(DP, HIGH);
  delay(overall_delay);
  evaluateData(str_array[hour/10], 4);
  digitalWrite(DP, LOW);
  delay(overall_delay);
}



