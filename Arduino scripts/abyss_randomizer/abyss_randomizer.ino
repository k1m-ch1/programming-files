String character[51]={"Ganyu","Hu Tao","Raiden Shogun","Venti","Ayato","Arataki Itto","Bennett","Xingqiu","Zhongli","Albedo","Ayaka","Jean","Eula","Kazuha","Heizou","Yae Miko","Shenhe","Yun Jin","Gorou","Klee","Diluc","Kokomi","Yoimiya","Aloy","Yanfei","Mona","Tartaglia","Xiao","Diona","Sucrose","Keqing","Ningguang","Razor","Fischl","Noelle","Xiangling","Kuki","Thoma","Barbara","Sara","Sayu","Beidou","Chongyun","Kaeya","Rosaria","Qiqi","Xinyan","Lisa","Traveller","Amber"};
int a;
int b;
int c; 
int d;
int e;
int f;
int g;
int h;
int state;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("SPIRAL ABYSS RANDOM TEAM GENERATOR FOR GENSHIN IMPACT");
  Serial.println(" ");
  Serial.println("INPUT 1 TO GENERATE");
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.parseInt()==1){
  a=random(0,50);
  b=random(0,50);
  c=random(0,50);
  d=random(0,50);
  e=random(0,50);
  f=random(0,50);
  g=random(0,50);
  h=random(0,50);
  while (b==a){
    b=random(0,50);
  }
  while (c==a||c==b){
    c=random(0,50);
  }
  while (d==a||d==b||d==c){
    d=random(0,50);
  }
  while (e==a||e==b||e==c||e==d){
    e=random(0,50);
  }
  while (f==a||f==b||f==c||f==d||f==e){
    f=random(0,50);
  }
  while (g==a||g==b||g==c||g==d||g==e||g==f){
    g=random(0,50);
  }
  while (h==a||h==b||h==c||h==d||h==e||h==f||h==g){
    h=random(0,50);
  }
  Serial.println(" ");
  Serial.print("TEAM 1: ");
  Serial.print(character[a]);
  Serial.print(" , ");
  Serial.print(character[b]);
  Serial.print(" , ");
  Serial.print(character[c]);
  Serial.print(" , ");
  Serial.println(character[d]);
  Serial.print("TEAM 2: ");
  Serial.print(character[e]);
  Serial.print(" , ");
  Serial.print(character[f]);
  Serial.print(" , ");
  Serial.print(character[g]);
  Serial.print(" , ");
  Serial.println(character[h]);
  state=1;
  }
  if(state==1){
    Serial.println("");
    Serial.println("INPUT 1 TO GENERATE");
    state=0;
  }
  
  

}
