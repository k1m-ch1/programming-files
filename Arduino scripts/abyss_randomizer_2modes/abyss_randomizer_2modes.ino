
unsigned int pickChar;
String assignedChar;
int mode;
int state;
const int numOfChar = 50;
String character[numOfChar];
int d;
int e;
int wait=10;

void mode2Function(int choosenChar, int nextLine) {
  int charEliminate = numOfChar - choosenChar;
  for (int a = 0; a < charEliminate; a++) {
    pickChar = random(0, numOfChar);
    assignedChar = character[pickChar];
    while (assignedChar == "null") {
      pickChar = random(0, numOfChar);
      assignedChar = character[pickChar];
    }
    character[pickChar] = "null";
    delay(wait);
  }
  Serial.println("CHARACTERS PICKED: ");
  for (int b = 0; b < numOfChar; b++) {
    String c = character[b];
    if (c != "null") {
      Serial.print(character[b]);
      int comma = choosenChar - 1;
      if (e < comma) {
        Serial.print(", ");
        e++;
      }
      d++;
      if (d >= nextLine) {
        Serial.println("");
        d = 0;
      }
    }
    delay(wait);
  }
  e = 0;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(A0));

}

void loop() {
  // put your main code here, to run repeatedly:
  character[0] = "Ganyu" ;
  character[1] = "Hu Tao" ;
  character[2] = "Raiden Shogun" ;
  character[3] = "Venti" ;
  character[4] = "Ayato" ;
  character[5] = "Arataki Itto" ;
  character[6] = "Bennett" ;
  character[7] = "Xingqiu" ;
  character[8] = "Zhongli" ;
  character[9] = "Albedo" ;
  character[10] = "Ayaka" ;
  character[11] = "Jean" ;
  character[12] = "Eula" ;
  character[13] = "Kazuha" ;
  character[14] = "Heizou" ;
  character[15] = "Yae Miko" ;
  character[16] = "Shenhe" ;
  character[17] = "Yun Jin" ;
  character[18] = "Gorou" ;
  character[19] = "Klee" ;
  character[20] = "Diluc" ;
  character[21] = "Kokomi" ;
  character[22] = "Yoimiya" ;
  character[23] = "Aloy" ;
  character[24] = "Yanfei" ;
  character[25] = "Mona" ;
  character[26] = "Tartaglia" ;
  character[27] = "Xiao" ;
  character[28] = "Diona" ;
  character[29] = "Sucrose" ;
  character[30] = "Keqing" ;
  character[31] = "Ningguang" ;
  character[32] = "Razor" ;
  character[33] = "Fischl" ;
  character[34] = "Noelle" ;
  character[35] = "Xiangling" ;
  character[36] = "Kuki" ;
  character[37] = "Thoma" ;
  character[38] = "Barbara" ;
  character[39] = "Sara" ;
  character[40] = "Sayu" ;
  character[41] = "Beidou" ;
  character[42] = "Chongyun" ;
  character[43] = "Kaeya" ;
  character[44] = "Rosaria" ;
  character[45] = "Qiqi" ;
  character[46] = "Xinyan" ;
  character[47] = "Lisa" ;
  character[48] = "Traveller" ;
  character[49] = "Amber";

  mode = Serial.parseInt();
  if (mode == 0) {
    if (state == 0) {
      Serial.println("SELECT MODE1, MODE2, MODE3");
      Serial.println("");
    }
    state = 1;
  }
  if (mode == 1) {
    Serial.print("TEAM 1: ");
    for (int i = 0; i < 4 ; i++) {
      pickChar = random(0, numOfChar);
      assignedChar = character[pickChar];
      while (assignedChar == "null") {
        pickChar = random(0, numOfChar);
        assignedChar = character[pickChar];
      }
      Serial.print(assignedChar);
      if (i < 3) {
        Serial.print(", ");
      }
      character[pickChar] = "null";
      delay(wait);
    }
    Serial.println("");
    Serial.print("TEAM 2: ");
    for (int j = 0; j < 4 ; j++) {
      pickChar = random(0, numOfChar);
      assignedChar = character[pickChar];
      while (assignedChar == "null") {
        pickChar = random(0, numOfChar);
        assignedChar = character[pickChar];
      }
      Serial.print(assignedChar);
      if (j < 3) {
        Serial.print(", ");
        state = 0;
      }
      character[pickChar] = "null";
      delay(wait);
    }
    Serial.println("");
    Serial.println("");
  }


  if (mode == 2) {
    mode2Function(20, 5);
    Serial.println("");
    state = 0;
    
  }
}
