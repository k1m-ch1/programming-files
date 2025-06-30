int decToBcd(int x, int digit);
int bcdToDec(int x, int digit);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int dec = 42;
  int Bcd = decToBcd(42, 0);
  Serial.print("BCD: ");
  Serial.print(Bcd, BIN);
  Serial.print("Dec: ");
  Serial.print(bcdToDec(Bcd, 0));
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}

int decToBcd(int x, int digit){
  // Converts an integer to bcd
  if (x <= 0){
    return 0;
  }
  else {
   return ((x%10) << (digit*4)) | decToBcd(x/10, digit+1);
  }
}

int bcdToDec(int x, int digit){
  // Convert Binary Coded Data to decimal
  if (x <= 0){
    return 0;
  }
  else{
    return (x%16*pow(10, digit)) + bcdToDec(x >> 4, digit+1);
  }
}