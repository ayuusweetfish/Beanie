#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
const char N = 5;

char A[N - 1][N], r0, s = 5, r, c, f, F[N - 1][N], qr[N * N], qc[N * N], qh, qt;
uint32_t rs;

uint32_t my_rand()
{
  return (rs = rs * 1103515245 + 12345) << 1 >> 6;
}

void reset()
{
  memset(A, 0, sizeof A);
  r0 = my_rand() % N;
  printf("<%d>\n", r0);
  r = -1; c = my_rand() % N; s = 1; f = 0;
}
void M()
{
  if (r < -1) r = -1; else if (c < 0) c = 0; else if (c > N - 1) c--; else {
    // 0 - unknown; 1 - known safe; 2 - monster
    if (r < 0 || A[r][c]) return;
    if (s == 3) {
      A[r][c] = 2;
    } else if (f) {
      // If no path emerges even with newly-revealed safe cells
      // or a trivial win next-step condition is held (r == N - 2), set to monster
      // This will guarantee 2-move unwinnable
      memset(F, 0, sizeof F);
      qh = qt = 0;
      A[r][c] = 2;
    #define I(r1, c1) \
      if (qh < N * N && (r1) >= 0 && (r1) < N - 1 && (c1) >= 0 && (c1) < N && \
        !F[r1][c1] && A[r1][c1] < 2 && (A[r1][c1] || (r1) == r || (c1) == c)) \
        F[r1][c1] = 1, qr[qt] = r1, qc[qt++] = c1, (r1 == 0 ? qh = N * N : 0);
      for (char c1 = 0; c1 < N; c1++) I(N - 2, c1)
      while (qh < qt) {
        char r1 = qr[qh], c1 = qc[qh++];
        I(r1 + 1, c1)
        I(r1 - 1, c1)
        I(r1, c1 + 1)
        I(r1, c1 - 1)
      }
      // printf("<%d %d> ", qh, qt);
      A[r][c] = 1 + (qh < N * N);
    } else if (s == 1) {
      A[r][c] = 1 + (((f ^= r) && (my_rand() & 1)) || c == r0);
    } else if (r0 > 0 && r0 < N - 1) {
      // Rule: known-safe cells cannot reach the already-exploded column
      A[r][c] = 1 + (r < 2 ? abs(r0 - c) < 2 : A[r - 1][c + (c < r0) * 2 - 1] == 0);
    } else {
      A[r][c] = 1 + ((r0 == 0
        ? c <= r || (A[r - 1][c - 1] == 0 || A[r - 1][c - 2] + A[r - 1][c] == 0)
        : c >= N - 1 - r || (A[r - 1][c + 1] == 0 || A[r - 1][c + 2] + A[r - 1][c] == 0)) || r == N - 2);
    }
    if (A[r][c] == 2) {
      for (char i = 0; i < N; i++) A[r][i] = A[i - (i > N - 2)][c] = 1;
      A[r][c] = 2;
    }
  }
}

struct termios t, T;
void e()
{
  tcsetattr(0, TCSAFLUSH, &t);
}

int main()
{
  tcgetattr(0, &t);
  atexit(e);
  T = t; T.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(0, 0, &T);

  while (1) {
    if (s & 4) {
      if (s == 4) {
        printf("Press Enter to continue\n");
        while (getchar() != '\n') { }
      }
      rs -= time(0) ^ clock() << 3;
      reset();
    } else {
      printf("\e[%dA", N + 2);
    }
    printf("Move %d\e[K\n", s);
    for (char i = -1; i < N; i++) {
      for (char j = 0; j < N; j++)
        printf("%c%d%c", r == i && c == j ? '[' : ' ',
          i < 0 || i > N - 2 ? 3 : A[i][j], r == i && c == j ? ']' : ' ');
      printf("\n");
    }
    unsigned char m = getchar();
    char *a = "Aix6" + ((m += m == 'h') >= 'i');
    if ((m -= *a) < 4) m = a[2] >> (6-m-m), *(m & 1 ? &r : &c) += (m & 2) - 1;
    M();
    if (r > N - 2) printf("\\(^ ^)/\n"), s = 4;
    else if (r >= 0 && r < N - 1 && A[r][c] == 2) {
      r = -1;
      if (s++ == 3) printf("(> <)\n");
    }
  }
}
