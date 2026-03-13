#include "prog.h"

#define BUZZER_PIN A5

int a(int c)
{
  if (c) {
    if (c == '\n') Serial.write('\r');
    Serial.write(c);
    return c;
  } else {
    while (!Serial.available()) { }
    return (c = Serial.read()) == '\r' ? '\n' : c;
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
  return millis() + analogRead(A0) + analogRead(A1) + analogRead(A2) + analogRead(A3);
}

void setup()
{
#ifdef BUZZER_PIN
  pinMode(BUZZER_PIN, OUTPUT);
#endif

  Serial.begin(115200);
}

void loop()
{
  L();
}
