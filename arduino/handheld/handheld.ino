#include "beanie.h"
#include "src/Adafruit_NeoPixel-1.15.4/Adafruit_NeoPixel.h"

static const int LED_STRIP_PIN = 3;
static const int BUZZER_PIN = A5;
static const int BUTTON_PIN[4] = {A0, 7, 8, A1};

static Adafruit_NeoPixel strip = Adafruit_NeoPixel(38, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

int buttons()
{
  int result = -1;
  static bool down[4] = {0};
  static unsigned short cooldown[4] = {0};
  static unsigned last_time = 0;
  unsigned cur_time = millis(), delta_time = cur_time - last_time;
  for (int i = 0; i < 4; i++) {
    bool cur_down = !digitalRead(BUTTON_PIN[i]);
    cooldown[i] = (cooldown[i] <= delta_time ? 0 : cooldown[i] - delta_time);
    if (cooldown[i] == 0 && !down[i] && cur_down) result = i;
    down[i] = cur_down;
  }
  if (result != -1) {
    cooldown[result] = 50;
    result = "ACBD"[result];
  }
  last_time = cur_time;
  return result;
}

void setup()
{
  strip.begin();
  strip.setBrightness(16);

  pinMode(BUZZER_PIN, OUTPUT);
  for (int i = 0; i < 4; i++)
    pinMode(BUTTON_PIN[i], INPUT_PULLUP);
}

void loop()
{
  static int c[3] = {0};

  int b = buttons();
  if (b != -1) {
    c[b % 3] ^= 31;
  }

  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, i % 2 ? strip.Color(63 - c[0], 63 - c[1], 63 - c[2]) : strip.Color(c[0], c[1], c[2]));
  }
  strip.show();
}
