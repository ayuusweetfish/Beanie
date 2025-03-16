#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#define N 5

char A[N - 1][N], r0, s = 5, r, c, f, q[N * N], h, t;
uint32_t R;

uint32_t my_rand()
{
  return (R = R * 1103515245 + 12345) << 1 >> 6;
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
    if (r < 0 || A[r][c]) return;
    if (f *= 6 - s - s) {
    #define I(R, C) \
      if (h < N * N && R >= 0 && R < N - 1 && C >= 0 && C < N && \
        A[R][C] < 2 && (A[R][C] || (A[r][c] == 2 && (R == r || C == c)))) \
        A[R][C] |= 4, q[t++] = (R) * N + C, (R == 0 ? h = N * N : 0);
    #define F(n, o) \
      A[r][c] = n; h = t = 0; \
      for (char C = 0; C < N; C++) I(N - 2, C) \
      while (h < t) { \
        char R = q[h] / N, C = q[h++] % N; \
        I(R - 1, C) I(R, C + 1) I(R, C - 1) \
      } \
      for (char r = 0; r < N - 1; r++) for (char c = 0; c < N; c++) A[r][c] &= 3; \
      f |= (h o N * N);
      F(2,<)F(1,==)
      if (r0 == 0 && c <= r || r0 == N - 1 && c >= N - 1 - r) f |= 1;
      f = 4 - (A[r][c] = 1 + (f & 1)) - s;
    } else {
      A[r][c] = 1 + (s == 3 || c == r0);
      f ^= (r || c == r0);
    }
    #define f for (char i = 0; i < N; i++) A[r][i] = A[i - (i > N - 2)][c] = 1; A[r][c] = 2;
    if (A[r][c] == 2) { f }
    t = 1;
    while (t--) {
      for (char r = 0; r < N - 1; r++) {
        h = 0; for (char c = 0; c < N; c++) h += A[r][c];
        if (h == N - 1) for (char c = 0; c < N; c++) if (!A[r][c]) { t = 1; f }
      }
    }
  }
}

struct termios S, T;
void e()
{
  tcsetattr(0, TCSAFLUSH, &S);
}

int main()
{
  tcgetattr(0, &S);
  atexit(e);
  T = S; T.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(0, 0, &T);

  while (1) {
    if (s & 4) {
      if (s == 4) {
        printf("Press Enter to continue\n");
        while (getchar() != '\n') { }
      }
      R -= time(0) ^ clock() << 3;
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
