
unsigned int pickChar;
String assignedChar;
int mode;
int state;
int b;
const int numOfChar=50;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(A0));

}

void loop() {
  // put your main code here, to run repeatedly:
  String character[numOfChar]={"Ganyu","Hu Tao","Raiden Shogun","Venti","Ayato","Arataki Itto","Bennett","Xingqiu","Zhongli","Albedo","Ayaka","Jean","Eula","Kazuha","Heizou","Yae Miko","Shenhe","Yun Jin","Gorou","Klee","Diluc","Kokomi","Yoimiya","Aloy","Yanfei","Mona","Tartaglia","Xiao","Diona","Sucrose","Keqing","Ningguang","Razor","Fischl","Noelle","Xiangling","Kuki","Thoma","Barbara","Sara","Sayu","Beidou","Chongyun","Kaeya","Rosaria","Qiqi","Xinyan","Lisa","Traveller","Amber"};
  mode=Serial.parseInt();
  if(mode==0){
    if(state==0){
      Serial.println("SELECT MODE1, MODE2, MODE3");
    } 
    state=1;
  }
  if(mode==1){
  Serial.print("TEAM 1: ");
  for(int i=0; i<4 ; i++){
  pickChar=random(0,numOfChar);
  assignedChar=character[pickChar];
  while(assignedChar=="null"){
    pickChar=random(0,numOfChar);
    assignedChar=character[pickChar];
  }
  Serial.print(assignedChar);
  if(i<3){
  Serial.print(", ");
  }
  character[pickChar]="null";
  }
  Serial.println("");
  Serial.print("TEAM 2: ");
  for(int j=0; j<4 ;j++){
  pickChar=random(0,numOfChar);
  assignedChar=character[pickChar];
  while(assignedChar=="null"){
    pickChar=random(0,numOfChar);
    assignedChar=character[pickChar];
  }
  Serial.print(assignedChar);
  if(j<3){
    Serial.print(", ");
    state=0;
  }
  character[pickChar]="null";
  }
  Serial.println("");
  }


}
