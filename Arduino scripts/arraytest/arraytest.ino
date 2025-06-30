String arraya[5]={"0","1","2","3","4"};
String displaya;
int state;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  String arraya[5]={"0","1","2","3","4"};  
  Serial.println(arraya[2]);
  delay(1000);
  arraya[2]="something";
  displaya=arraya[2];
  state=Serial.parseInt();
  Serial.println(displaya);
  if(state==0){
    Serial.println("input a zero"); 
  }
  if(state>0){
    Serial.println("nothing");
  }


}
