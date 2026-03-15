#define NO_LOOP
#include "prog.c"

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
  unsigned seed = *(uint32_t *)(data + 0);
  size_t p = 4;

  // Run case
  printf("Restart, seed = %u\n", seed);
  Y = 0; R(seed);
  while (p < n) {
    uint8_t move = data[p++] % 4;
    static char last_A[N * N - N];
    for (int i = 0; i < N * N - N; i++) last_A[i] = A[i];
    char result = M('A' + move);
    for (signed int i = -1; i < N; i++) {
      for (int j = 0; j < N; j++)
        printf("%c%c%c",
          (i == r && j == c) ? '[' : ' ',
          i < 0 || i > N - 2 ? '=' : ".*o#O"[A[i * N + j]],
          (i == r && j == c) ? ']' : ' ');
      printf("\n");
    }
    printf("Move %-5s | ", (const char *[]){"Up", "Down", "Right", "Left"}[move]);
    printf("(%2d,%2d) Step %d (%d)", r, c, o, result);
    assert(result >= 0 && result <= 5 /* && result != 4 */);
    if (result == 4 || result == 5) {
      assert(r > N - 2);
      printf(" | Success!\n");
      break;
    } else if (result == 2 || result == 3) {
      printf(" | Bomb!");
      if (result == 3) {
        printf(" Fail!\n");
        break;
      }
    }
    printf("\n");

    // Ensure that no row is empty!
    for (int i = 0; i < N - 1; i++) {
      char nonempty = 0;
      for (int j = 0; j < N; j++)
        if (A[i * N + j] % 2 != 1) { nonempty = 1; break; }
      assert(nonempty);
    }
    // Ensure mark behaviour
    for (int i = 0; i < N * N - N; i++) {
      assert(A[i] >= 0 && A[i] <= 4);
      if (A[i] == 3 || A[i] == 4) assert(result <= 1 || last_A[i] == 0);
    }
  }
  // Do not add to corpus if trailing extraneous bytes
  if (p < n) return -1;

  return 0;
}
