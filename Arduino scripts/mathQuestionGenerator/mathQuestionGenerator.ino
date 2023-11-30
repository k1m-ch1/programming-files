char symbol[4]={'+','-','*','/'};
String correctResponse[10]={"GOOD JOB","NICE JOB","AMAZING","COOL","DICKS ARE GETTING SUCKED TONIGHT","NICE FUCKING JOB YOU FUCKING CUNT","CUM(I CAME)","ARE YOU ALBERT EINSTEIN?","YOU'RE (NOT) A GENIUS","PERMISSION TO SUCK ON DEEZ NUTS EARNED"};
String wrongResponse[6]={"BRUH MOMENT","STUPID ASS BITCH","DUMBASS MOTHERFUCKER","YOU'RE A SUSSY BAKA","YOU'RE BAD","SUCK A NIG*A'S DICK"};
int correctResponsePick;
int wrongResponsePick;
long answerCorrect;
long answerInput;
char symbolRandom;
char symbolReal;
long number1;
long number2;
int state=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(A0));

}

void loop() {
  // put your main code here, to run repeatedly:
  symbolRandom= random(4);
  symbolReal=symbol[symbolRandom];
  switch (symbolReal){
    case '+':
    number1=random(0,2100000);
    number2=random(0,2100000);
    Serial.print("QUESTION: ");
    Serial.print(number1);
    Serial.print('+');
    Serial.println(number2);
    answerCorrect=number1+number2;
    break;
    case '-':
    number1=random(0,2100000);
    number2=random(0,2100000);
    Serial.print("QUESTION: ");
    Serial.print(number1);
    Serial.print('-');
    Serial.println(number2);
    answerCorrect=number1-number2;
    break;
    case '*':
    number1=random(0,10000);
    number2=random(0,100);
    Serial.print("QUESTION: ");
    Serial.print(number1);
    Serial.print('*');
    Serial.println(number2);
    answerCorrect=number1*number2;
    break;
    case '/':
    number1=random(0,2200000);
    number2=random(0,200);
    Serial.print("QUESTION: ");
    Serial.print(number1);
    Serial.print('/');
    Serial.println(number2);
    answerCorrect=number1/number2;
    break;
  }
  Serial.parseInt();
  while(Serial.available()==0){
  }
  answerInput=Serial.parseInt();
  if(answerInput==answerCorrect){
    correctResponsePick=random(0,10);
    Serial.println(correctResponse[correctResponsePick]);
    state=1;
  }
  if(answerInput!=answerCorrect & state==0){
    wrongResponsePick=random(0,6);
    wrongResponsePick=random(0,6);
    Serial.println(wrongResponse[wrongResponsePick]);
    Serial.print("CORRECT ANSWER IS:  ");
    Serial.println(answerCorrect);
    delay(1000);
  }
  while(Serial.available()>0){
    Serial.read();
  }
  state=0;
  

}

  
  
