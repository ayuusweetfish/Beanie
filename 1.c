#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
const char N = 5;

char A[N - 1][N], r0, s = 5, r, c, f;
uint32_t rs;

uint32_t my_rand()
{
  return (rs = rs * 1103515245 + 12345) << 1 >> 6;
}

void reset()
{
  memset(A, 0, sizeof A);
  r0 = my_rand() % N;
  r = -1; c = my_rand() % N; s = 1; f = 0;
}
void M()
{
  if (r < -1) r = -1; else if (c < 0) c = 0; else if (c > N - 1) c--; else {
    // 0 - unknown; 1 - known safe; 2 - monster
    if (r < 0 || A[r][c]) return;
    if (s == 1) {
      A[r][c] = 1 + ((f |= !!r) || c == r0);
    } else if (s == 3 || f || /* s == 2 && */ r0 > 0 && r0 < N - 1) {
      A[r][c] = 2;
    } else {
      A[r][c] = 1 + ((r0 == 0 ? c <= r : c >= N - 1 - r) || r == N - 2);
    }
    if (A[r][c] == 2) {
      for (char i = 0; i < N; i++) A[r][i] = A[i - (i > N - 2)][c] = 1;
      A[r][c] = 2;
    }
  }
}

// Ref: https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html

struct termios t, T;
void e()
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
}

int main()
{
  tcgetattr(STDIN_FILENO, &t);
  atexit(e);
  T = t; T.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, 0, &T);

  while (1) {
    unsigned char m = getchar();
    // i~l: 0/- +/0 -/0 0/+
    //      0   3   1   2
    // A~D: -/0 +/0 0/+ 0/-
    //      1   3   2   0
    char *a = "Aix6" + ((m += m == 'h') >= 'i');
    if ((m -= *a) < 4) printf("%d ", m), m = a[2] >> (6-m-m), r = c = (m & 2) - 1, r *= m & 1, c *= !(m & 1), printf("%d %d\n", r, c);
  }
  while (1) {
    if (s & 4) {
      if (s == 4) {
        printf("Press Enter to continue\n");
        while (getchar() != '\n') { }
      }
      rs -= time(0) ^ clock() << 3;
      reset();
    } else {
      printf("\e[7A");
    }
    printf("Move %d\e[K\n", s);
    for (char i = -1; i < N; i++) {
      for (char j = 0; j < N; j++)
        printf("%c%d%c", r == i && c == j ? '[' : ' ',
          i < 0 || i > N - 2 ? 3 : A[i][j], r == i && c == j ? ']' : ' ');
      printf("\n");
    }
    char m = getchar();
    switch (m) { case 'k': r -= 2; case 'j': r++; c++; case 'h': c -= 2; case 'l': c++; }
    M();
    if (r > N - 2) printf("\\(^ ^)/\n"), s++;
    else if (r >= 0 && r < N - 1 && A[r][c] == 2) {
      r = -1;
      if (s++ == 3) printf("(> <)\n");
    }
  }
}
