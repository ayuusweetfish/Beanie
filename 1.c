#define N 5
#define F(a, b) for (char a = 0; a < b; a++)

char A[N * N - N], r0, s = 5, r, c, f, q[N * N], h, t;
unsigned Y;

void R(unsigned x)
{
  F(r, N * N - N) A[r] = 0;
  r0 = ((Y = (Y - x) * 1103515245u + 12345) << 1 >> 3) % N;
  f = -1; r = f++; c = (Y >> 7) % N; s = 1;
}
void M()
{
  if (r < -1) r = -1; else if (c < 0) c = 0; else if (c > N - 1) c--; else {
    char *a = A + r * N + c, *b;
    if (r < 0 || *a) return;
    if (f *= 6 - s - s) {
    #define I(R, C) \
      if (b = A + (R) * N + C, h < N * N && R >= 0 && R < N - 1 && C >= 0 && C < N && \
        *b < 2 && (*b || *a == 2 && !((R - r) * (C - c)))) \
        *b |= 4, q[t++] = b - A, h += N * N * !(R);
    #define i(n, o) \
      *a = n; h = t = 0; \
      F(C, N) I(N - 2, C) \
      while (h < t) { \
        char R = q[h] / N, C = q[h++] % N; \
        I(R - 1, C) I(R, C + 1) I(R, C - 1) \
      } \
      F(r, N * N - N) A[r] &= 3; \
      f |= (h o N * N);
      i(2,<)i(1,>)
      if (!r) { h = 0; F(c, N) h += A[c]; if (h == N - 1) f |= 1; }
      f = 4 - (*a = 1 + (f & 1)) - s;
    } else {
      h = 0; F(c, N) h += A[c]; if (h == N - 2) r0 = c;
      *a = 1 + (s == 3 || c == r0);
      f ^= (r || c == r0);
    }
    #define f { F(i, N) a[i] = A[(i - (i > N - 2)) * N + c] = 1; a[c]++; }
    if (a -= c, a[c] == 2) f
    t = 1;
    while (t--)
      for (a = A; a < A + N * N - N; a += N) {
        h = 0; F(c, N) h += a[c];
        if (h == N - 1) F(c, N) if (t = !a[c]) f
      }
  }
}
#undef f
#undef i
#undef I

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

struct termios S, T;
void e()
{
  tcsetattr(0, TCSAFLUSH, &S);
}

FILE *a;

int main()
{
  tcgetattr(0, &S);
  atexit(e);
  T = S; T.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(0, 0, &T);

  a = popen("sox --buffer 1024 -t f32 -r 44100 -c 1 - -d 2>/dev/null", "w");
  setbuf(a, NULL);
  for (int i = 0; i < 44100 * 3; i++) {
    float sample = sinf(2 * (float)M_PI * 440 * i / 44100);
    fwrite(&sample, sizeof(float), 1, a);
    fflush(a);
  }

  while (1) {
    if (s & 4) {
      if (s == 4) {
        printf("Press Enter to continue\n");
        while (getchar() != '\n') { }
      }
      R(time(0) ^ clock() << 3);
    } else {
      printf("\e[%dA", N + 2);
    }
    printf("Move %d\e[K\n", s);
    for (char i = -1; i < N; i++) {
      for (char j = 0; j < N; j++)
        printf("%c%d%c", r == i && c == j ? '[' : ' ',
          i < 0 || i > N - 2 ? 3 : A[i * N + j], r == i && c == j ? ']' : ' ');
      printf("\n");
    }
    unsigned char m = getchar();
    char *a = "Aix6" + ((m += m == 'h') >= 'i');
    if ((m -= *a) < 4) m = a[2] >> (6-m-m), *(m & 1 ? &r : &c) += (m & 2) - 1;
    M();
    if (r > N - 2) printf("\\(^ ^)/\n"), s = 4;
    else if (r >= 0 && r < N - 1 && A[r * N + c] == 2) {
      r = -1;
      if (s++ == 3) printf("(> <)\n");
      else printf("(O O)\r");
    } else printf("\e[K");
  }
}
