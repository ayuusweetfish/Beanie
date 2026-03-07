#include "src/Adafruit_NeoPixel-1.15.4/Adafruit_NeoPixel.h"

static const int LED_STRIP_PIN = 13;

static Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(16);
}

void showTest(int r, int g, int b) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, i % 2 ? strip.Color(255 - r, 255 - g, 255 - b) : strip.Color(r, g, b));
  }
  strip.show();
}

void loop() {
  showTest(255, 0, 0); delay(1000);
  showTest(0, 255, 0); delay(1000);
  showTest(0, 0, 255); delay(1000);
  showTest(255, 255, 255); delay(1000);
}
