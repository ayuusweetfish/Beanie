#include "prog.h"

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
void b(int l)
{
}
unsigned d()
{
  return 0;
}

void setup()
{
  Serial.begin(115200);
  Serial.write("Hello!\r\n");
}

void loop()
{
  void L(); L();
}
