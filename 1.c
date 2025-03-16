#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
const char N = 5;

char A[N - 1][N], r0, s = 5, r, c, f, qr[N * N], qh, qt;
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
    if (r < 0 || A[r][c]) return;
    if (s == 3) {
      A[r][c] = 2;
    } else if (f *= 2) {
    #define I(R, C) \
      if (qh < N * N && R >= 0 && R < N - 1 && C >= 0 && C < N && \
        A[R][C] < 2 && (A[R][C] || (A[r][c] == 2 && (R == r || C == c)))) \
        A[R][C] |= 4, qr[qt++] = (R) * N + C, (R == 0 ? qh = N * N : 0);
    #define F(n, o) \
      A[r][c] = n; qh = qt = 0; \
      for (char c1 = 0; c1 < N; c1++) I(N - 2, c1) \
      while (qh < qt) { \
        char r1 = qr[qh] / N, c1 = qr[qh++] % N; \
        I(r1 - 1, c1) I(r1, c1 + 1) I(r1, c1 - 1) \
      } \
      for (char r = 0; r < N; r++) for (char c = 0; c < N; c++) A[r][c] &= 3; \
      f |= (qh o N * N);
      F(2,<)F(1,==)
      if (r0 == 0 && c <= r || r0 == N - 1 && c >= N - 1 - r) f |= 1;
      A[r][c] = 1 + (f & 1);
      f = 1;
    } else {
      A[r][c] = 1 + (c == r0);
      f ^= (r || c == r0);
    }
    #define f for (char i = 0; i < N; i++) A[r][i] = A[i - (i > N - 2)][c] = 1; A[r][c] = 2;
    if (A[r][c] == 2) { f }
    qt = 1;
    while (qt--) {
      for (char r = 0; r < N - 1; r++) {
        qh = 0; for (char c = 0; c < N; c++) qh += A[r][c];
        if (qh == N - 1) for (char c = 0; c < N; c++) if (!A[r][c]) { qt = 1; f }
      }
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
