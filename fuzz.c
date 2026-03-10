// clang % -g -O2 -fsanitize=fuzzer,address
#define FUZZ
#include "1.c"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#ifdef PRINT
#include <stdio.h>
#else
#define printf(...)
#endif

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t n)
{
  if (n < 5) return -1;
  s = 4;
  unsigned seed = *(uint32_t *)(data + 0);
  size_t p = 4;

  // Run case
  Y = seed;
  printf("Restart, seed = %u\n", Y);
  R(0);
  while (p < n) {
    uint8_t move = data[p++] % 4;
    printf("Move %-5s | ", (const char *[]){"Up", "Down", "Right", "Left"}[move]);
    char result = M('A' + move);
    printf("(%2d,%2d) Step %d", r, c, s);
    assert(result >= 0 && result <= 4);
    if (result == 3 || result == 4) {
      assert(r > N - 2);
      printf(" | Success!\n");
      break;
    } else if (result == 1 || result == 2) {
      printf(" | Bomb!");
      if (result == 2) {
        printf(" Fail!\n");
        break;
      }
    }
    printf("\n");
  }
  // Do not add to corpus if trailing extraneous bytes
  if (p < n) return -1;

  return 0;
}
