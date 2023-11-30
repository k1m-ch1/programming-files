int pin1=2;
int pin2=3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int number=analogRead(A0);
  if (number<=511){digitalWrite(pin1,HIGH);
  }
  else{digitalWrite(pin1,LOW);
  }
  if (number<=511){digitalWrite(pin2,LOW);
  }
  else{digitalWrite(pin2,HIGH);
  }

}
