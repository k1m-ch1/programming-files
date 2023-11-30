String characterConst[40]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
"fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twenty-one","twenty-two","twenty-three","twenty-four","twenty-five","twenty-six","twentys-seven",
"twenty-eight","twenty-nine","thirty","thirty-one","thirty-two","thirty-three","thrity-four","thrity-five","thrity-six","thrity-seven","thirty-eight","thirty-nine",};
String character[40];
String word1;
String word2;
String word3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i=0;
  int j=0;
  while(i<40){
    word1=characterConst[i];
    character[j]=word1;
    Serial.print(character[j]);
    Serial.println(", ");
    delay(100);
    i++;
    j++;
  }

}
