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
  printf("Restart, seed = %u\n", Y);
  R(Y);
  while (p < n) {
    uint8_t move = data[p++] % 4;
    char result = M('A' + move);
    for (signed char i = 0; i < N; i++) {
      for (char j = 0; j < N; j++)
        printf("%c%c%c",
          (i == r && j == c) ? ' ' : '[',
          i < 0 || i > N - 2 ? '=' : ".*o"[A[i * N + j]],
          (i == r && j == c) ? ' ' : ']');
      printf("\n");
    }
    printf("Move %-5s | ", (const char *[]){"Up", "Down", "Right", "Left"}[move]);
    printf("(%2d,%2d) Step %d (%d)", r, c, s, result);
    assert(result >= 0 && result <= 4 /* && result != 3 */);
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
