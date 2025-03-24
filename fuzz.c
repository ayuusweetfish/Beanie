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
    int8_t dir[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
    printf("Move %-5s | ", (const char *[]){"Down", "Up", "Right", "Left"}[move]);
    r += dir[move][0];
    c += dir[move][1];
    M();
    printf("(%2d,%2d) Step %d", r, c, s);
    if (r > N - 2) {
      assert(s == 3);
      s = 4;
      printf(" | Success!\n");
      break;
    } else if (r >= 0 && A[r * N + c] == 2) {
      r = -1;
      printf(" | Bomb!");
      if (s++ == 3) {
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
