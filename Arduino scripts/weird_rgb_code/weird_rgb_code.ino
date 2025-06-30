int red_light_pin= 3;
int green_light_pin = 5;
int blue_light_pin = 6;
int wait=1000;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  Serial.begin(9600);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
  Serial.print("  red light: ");
  Serial.print(red_light_value);
  Serial.print("  green light: ");
  Serial.print(green_light_value);
  Serial.print("  blue light: ");
  Serial.println(blue_light_value);
 }
void loop() {
  RGB_color(255, 0, 0); // Red
  delay(wait);
  RGB_color(0, 255, 0); // Green
  delay(wait);
  RGB_color(0, 0, 255); // Blue
  delay(wait);
  RGB_color(255, 255, 125); // Raspberry
  delay(wait);
  RGB_color(0, 255, 255); // Cyan
  delay(wait);
  RGB_color(255, 0, 255); // Magenta
  delay(wait);
  RGB_color(255, 255, 0); // Yellow
  delay(wait);
  RGB_color(255, 255, 255); // White
  delay(wait);
}
