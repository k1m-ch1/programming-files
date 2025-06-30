#include <FastLED.h>

#define NUM_LEDS 300
#define LED_PIN 9

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Red;
    FastLED.show();
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  for (int i = (NUM_LEDS - 1); i >= 0; i--){
    leds[i] = CRGB::Red;
    FastLED.show();
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}
