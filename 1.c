#define N 5
#define F(a, b) for (char a = 0; a < b; a++)

char A[N * N - N], r0, s = 5, r, c, f, q[N * N];
unsigned Y;

void R(unsigned x)
{
  F(r, N * N - N) A[r] = 0;
  c = (2 * (Y = (Y - x) * 1103515245u + 12345) >> 3) % N;
  r = 0; f = r--; r0 = (Y + Y >> 6) % N; s = 1;
}
void M()
{
  if (~r > 0) r++; else if (c < 0) c = 0; else if (c >= N) c--; else {
    char *a = A + r * N + c, *b, h, t;
    if (r < 0 | *a) return;
    if (f *= 6 - s - s) {
    #define I(R, C) \
      if (b = A + (R) * N + C, h < N * N & R >= 0 & R < N - 1 & C >= 0 & C < N & \
        *b < 2 & (*b | !(*a - 2 || R - r && C - c))) \
        *b |= 4, q[t++] = b - A, h += N * N * !(R);
      F(n, 2) {
        *a = -~n; h = t = 0;
        F(C, N) I(N - 2, C)
        while (h < t) {
          char R = q[h++], C = R % N; R /= N;
          I(R - 1, C) I(R, C + 1) I(R, C - 1)
        }
        F(r, N * N - N) A[r] &= 3;
        f |= (h - N * N) * (n - !n) < 0;
      }
    #define R h = 0; F(c, N) h += b[c]; if (h == N
      if (!r) { b = A; R) f |= Y /= 8; }
      f = 4 - (*a = -~(f & 1)) - s;
    } else {
      b = A; R-2) r0 = c;
      *a = 1 + (s == 3 | c == r0 || r && Y & 4);
      f ^= r || c == r0;
    }
    #define f { F(i, N) b[i] = A[(i - (i > N - 2)) * N + c] = 1; b[c]++; }
    if (b = a - c, *a == 2) f
    t = 1;
    while (t--)
      for (b = A; b < A + N * N - N; b += N) {
        R-1) F(c, N) if (t = !b[c]) f
      }
  }
}
#undef f
#undef R
#undef I

#ifndef FUZZ
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

int main(int argc, char *argv[])
{
  tcgetattr(0, &S);
  atexit(e);
  T = S; T.c_lflag &= ~ECHO & ~ICANON;
  tcsetattr(0, 0, &T);

  // ./a.out >(sox --buffer 1024 -t f32 -r 44100 -c 1 - -d 2>/dev/null)
  if (argc >= 1) {
    a = fopen(argv[1], "wb");
    if (a) {
      setbuf(a, NULL);
      for (int i = 0; i < 44100 * 3; i++) {
        float sample = sinf(2 * (float)M_PI * 440 * i / 44100);
        fwrite(&sample, sizeof(float), 1, a);
        fflush(a);
      }
    }
  }
  if (!a) printf("No audio device supplied, game will be silent (_ _)\n");

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
          i < 0 | i > N - 2 ? 3 : A[i * N + j], r == i && c == j ? ']' : ' ');
      printf("\n");
    }
    unsigned char m = getchar();
    char *a = "Aix6" + ((m += m == 'h') >= 'i');
    if ((m -= *a) < 4) m = a[2] >> (6-m-m), *(m & 1 ? &r : &c) += (m & 2) - 1;
    M();
    if (r > N - 2) printf("\\(^ ^)/\n"), s = 4;
    else if (r >= 0 && A[r * N + c] == 2) {
      r = -1;
      if (s++ == 3) printf("(> <)\n");
      else printf("(O O)\r");
    } else printf("\e[K");
  }
}
#endif
