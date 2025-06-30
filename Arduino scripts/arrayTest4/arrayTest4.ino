String character[50];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
character[0]="zero";
character[1]="one";
character[2]="two";
character[3]="three" ;
character[4]="four" ;
character[5]="five" ;
character[6]="six" ;
character[7]="seven" ;
character[8]="eight" ;
character[9]="nine" ;
character[10]="ten" ;
character[11]="eleven" ;
character[12]="twelve" ;
character[13]="thirteen" ;
character[14]="fourteen" ;
character[15]="fifteen" ;
character[16]="sixteen" ;
character[17]="seventeen" ;
character[18]="eighteen" ;
character[19]="nineteen" ;
character[20]="twenty" ;
character[21]="twenty-one"; 
character[22]="twenty-two" ;
character[23]="twenty-three" ;
character[24]="twenty-four" ;
character[25]="twenty-five" ;
character[26]="twenty-six" ;
character[27]="twentys-seven" ;
character[28]="twenty-eight" ;
character[29]="twenty-nine" ;
character[30]="thirty" ;
character[31]="thirty-one" ;
character[32]="thirty-two" ;
character[33]="thirty-three";
character[34]="thrity-four" ;
character[35]="thrity-five" ;
character[36]="thrity-six";
character[37]="thrity-seven" ;
character[38]="thirty-eight" ;
character[39]="thirty-nine" ;
character[40]="fourty" ;
character[41]="fourty-one" ;
character[42]="fourty-two" ;
character[43]="fourty-three" ;
character[44]="fourty-four" ;
character[45]="fourty-five" ;
character[46]="fourty-six"; 
character[47]="fourty-seven"; 
character[48]="fourty-eight";
character[49]="fourty-nine";
for(int i=0; i<50; i++){
  String j=character[i];
  Serial.println(j);
}
  
}
