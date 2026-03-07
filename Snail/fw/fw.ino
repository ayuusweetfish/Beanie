#include "src/Adafruit_NeoPixel-1.15.4/Adafruit_NeoPixel.h"

static const int LED_STRIP_PIN = 3;
static const int BUZZER_PIN = A5;
static const int BUTTON_PIN[4] = {A0, 7, 8, A1};

static Adafruit_NeoPixel strip = Adafruit_NeoPixel(38, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(16);

  pinMode(BUZZER_PIN, OUTPUT);
  for (int i = 0; i < 4; i++)
    pinMode(BUTTON_PIN[i], INPUT_PULLUP);
}

void showTest(int r, int g, int b) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, i % 2 ? strip.Color(255 - r, 255 - g, 255 - b) : strip.Color(r, g, b));
  }
  strip.show();
}

void loop() {
  showTest(0, 0, 0);
  for (int i = 0; i < 4; i++) {
    if (digitalRead(BUTTON_PIN[i]) == 0) {
      switch (i) {
      case 0:
        tone(BUZZER_PIN, 1320, 50); showTest(255, 0, 0); break;
      case 1:
        tone(BUZZER_PIN, 1100, 50); showTest(0, 255, 0); break;
      case 2:
        tone(BUZZER_PIN, 880, 50); showTest(0, 0, 255); break;
      case 3:
        tone(BUZZER_PIN, 440, 50); showTest(255, 255, 255); break;
      }
      delay(100);
      while (digitalRead(BUTTON_PIN[i]) == 0) { }
    }
  }
}
