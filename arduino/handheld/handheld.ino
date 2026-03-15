#include "beanie.h"
#include "src/Adafruit_NeoPixel-1.15.4/Adafruit_NeoPixel.h"

#define BUZZER_PIN A5
#define BUTTON_PIN _button_pins
static const int _button_pins[4] = {A0, 7, 8, A1};
#define LED_STRIP_PIN 3

#ifdef LED_STRIP_PIN
static Adafruit_NeoPixel strip = Adafruit_NeoPixel(38, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);
#endif

int buttons()
{
  int result = -1;
#ifdef BUTTON_PIN
  static bool down[4] = {0};
  static unsigned short cooldown[4] = {0};
  static unsigned last_time = 0;
  unsigned cur_time = millis(), delta_time = cur_time - last_time;
  for (int i = 0; i < 4; i++) {
    cooldown[i] = (cooldown[i] <= delta_time ? 0 : cooldown[i] - delta_time);
    if (cooldown[i] == 0 && result == -1) {
      bool cur_down = !digitalRead(BUTTON_PIN[i]);
      if (!down[i] && cur_down) result = i;
      down[i] = cur_down;
    }
  }
  last_time = cur_time;
  if (result != -1) cooldown[result] = 50;
#endif
  return result;
}

int a(int c)
{
  if (c) {
    if (c == '\n') Serial.write('\r');
    Serial.write(c);
    return c;
  } else {
    int b;
    while (!Serial.available() && (b = buttons()) == -1) { }
    return b != -1 ? o >= 4 ? '\n' : "ACBD"[b] : (c = Serial.read()) == '\r' ? '\n' : c;
  }
}
void b(int p)
{
#ifdef BUZZER_PIN
  int16_t l = ((p + '-') & -256), S, E = 144 - (p -= l) - l;
  if (E) {
    tone(BUZZER_PIN, 440), delay(22);
    if (l) {
      if (p)
        tone(BUZZER_PIN, abs(p) * 36.67), delay(l * 0.2);
      else
        for (int i = 0; i < l * 0.2; i++)
          tone(BUZZER_PIN, 420 - i * 20), delay(1);
    }
    noTone(BUZZER_PIN);
  }
#endif
}
unsigned d()
{
  return millis() + analogRead(A2) + analogRead(A3) + analogRead(A4);
}

enum {
  LIGHTS_ORDINARY = 0,
  LIGHTS_BLINK_TRAP_ON = 1,
  LIGHTS_BLINK_TRAP_OFF = 2,
};
void display_lights(int mode)
{
#ifdef LED_STRIP_PIN
  #define cell_light(_r, _c) \
    ((N - 1 - (_r)) * N + ((N - (_r)) % 2 ? (_c) : (N - 1 - (_c))))
    /* (N + (N - 1 - (_r)) * N + ((N - (_r)) % 2 ? (N - 1 - (_c)) : (_c))) */
  #define move_light(_n) \
    (37 - (_n))
  static const uint32_t palette[6] = {0x000000, 0x000401, 0x060001, 0x030303, 0x080800, 0x080400};
  for (int r = 0; r < N - 1; r++)
    for (int cc = 0; cc < N; cc++) {
      int a = A[r * N + cc];
      if (a == 3) a = (mode == LIGHTS_BLINK_TRAP_ON || mode == LIGHTS_BLINK_TRAP_OFF ? 0 : 1);
      if (a == 2 && cc == c)
        a = (mode == LIGHTS_BLINK_TRAP_ON ? 5 : 
             mode == LIGHTS_BLINK_TRAP_OFF ? 0 : 2);
      strip.setPixelColor(cell_light(r, cc), palette[a]);
    }
  for (int c = 0; c < N; c++) {
    strip.setPixelColor(cell_light(N - 1, c), palette[r == N - 1 ? 4 : 3]);
    strip.setPixelColor(cell_light(-1, c), palette[3]);
  }
  if (mode == LIGHTS_ORDINARY && !(r >= 0 && r < N - 1 && A[r * N + c] == 2))
    strip.setPixelColor(cell_light(r, c), palette[4]);
  for (int i = 0; i < 3; i++)
    strip.setPixelColor(move_light(i), palette[o == i + 1 ? (mode == LIGHTS_BLINK_TRAP_ON || mode == LIGHTS_BLINK_TRAP_OFF ? 0 : r == N - 1 ? 4 : 4) : o >= i + 1 ? (r == N - 1 ? 4 : 2) : 0]);
  strip.show();
  #undef cell_light
  #undef move_light
#endif
}

void y(int t)
{
  if (t == 2 || t == 3) {
    for (int i = 0; i < 2; i++) {
      display_lights(LIGHTS_BLINK_TRAP_ON); delay(50);
      display_lights(LIGHTS_BLINK_TRAP_OFF); delay(50);
    }
  }
  display_lights(LIGHTS_ORDINARY);
}

void setup()
{
#ifdef LED_STRIP_PIN
  strip.begin();
  strip.setBrightness(255);
#endif

#ifdef BUZZER_PIN
  pinMode(BUZZER_PIN, OUTPUT);
#endif

#ifdef BUTTON_PIN
  for (int i = 0; i < 4; i++)
    pinMode(BUTTON_PIN[i], INPUT_PULLUP);
#endif

  Serial.begin(115200);
}

void loop()
{
  L();
}
