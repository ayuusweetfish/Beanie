#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

void w(uint64_t n)
{
  while (n) putchar(n % 128), n >>= 7;
}

int main()
{
  const char *S[] = {
    "\033[02A",
    "\033[K", "(O O)\r", "(> <)\n", "\\(>-<)/\n", "\\(^ ^)/\n", "~\\(^-^*)\n",
  };
  for (int i = 0; i < sizeof S / sizeof S[0]; i++) {
    const char *s = S[i];
    uint64_t n = 0;
    for (int j = 0; j < 9 && s[j] != 0; j++)
      n |= ((uint64_t)s[j]) << (7 * j);
    printf("%" PRIu64 "\n", n);
    // w(n); printf("\n");
  }
}
