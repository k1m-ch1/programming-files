#include <dht.h>

dht DHT;


void setup(){
  Serial.begin(9600);
}
void loop(){
  DHT.read11(A0);
  Serial.print(DHT.humidity);
  Serial.print("  ");
  Serial.println(DHT.temperature);
  delay(1000);
}
