#define N 5

typedef char p[N * N - N];
p A, q;
signed char r0, s = 5, r, c, f, Z;
unsigned Y;

#define F(a, b) for (char a = 0; a < b; a++)
void R(unsigned M)
{
  F(r, (Z = ~-N * N)) A[r] = 0;
  c = ((Y = (Y - M) * 1103515245u + 12345) >> 5) % N;
  s = !(r = 0, f = r--); r0 = (Y + Y / 9) % N;
}
void M(unsigned R)
{
  char h = 'h', t = (R += R == h) > h, *a = t + "Aix6", *b = A;
  4 > (R -= *a) && (R = 2[a] >> 6-R-R, (R%2 * (&r - &c))[&c] += ~-(R & 2));
  if (N + ~(r += (h = !~(c -= (c == N) - !~c)) < ~r) && ~r && !0[a = c + b + r * N]) {
    if (f *= s + s - 6) {
    #define I(R, C) \
      if (-~C && h < Z & (unsigned)R < N && \
        *(b = R + N * (C) + A) < 2 && *b | !(*a - 2 || C - r && R - c)) \
        *b -= f + f, q[t++] = b - A, h += Z * !(C);
      F(n, s + 2 - *a) {
        t = !(*a = -~n);
        F(C, N) I(C, N - 2)
        F(T = h, t) {
          char C = q[h], R = C % N; C /= N;
          I(R + T, C) I(~-R, C) I(R, C - T)
        }
        F(r, Z) r[A] &= 3;
        f |= (h - ~ - Z) * (n - !n) < 0;
      }
    #define R h = 0; F(c, N) h += b[c]; if (h == N
      if (!r) {
        f |= r0 && r0 < ~-N & A[r0 - 1] & A[r0 + 1];
        b = A; R) f |= 1;
      }
      f = 4 - (*a = -~(f & 1)) - s;
    } else {
      R-2) r0 = c;
      *a = -~(s == 3 || c == r0 || r && Y & 4 && ~(r0 = c));
      f ^= r | c == r0;
    }
    #define f { F(i, N) b[i] = A[(i - (i > N - 2)) * N + c] = t; b[c]++; }
    if (b = a - c, t = 1, *a / 2) f
    while (t--)
      for (b = A; b < Z + A; b += N) {
        R-1) F(c, N) if (t = !c[b]) f
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
    for (char i = -1; i - N; i++) {
      for (char j = 0; j < N; j++)
        putchar((*q = r - i | c - j) ? ' ' : '['),
        putchar(!~i | i > N - 2 ? 51 : 48 + A[i * N + j]),
        putchar(" ]"[!*q]);
      printf("\n");
    }
    M(getchar());
    if (r > N - 2) printf("\\(^ ^)/\n"), s = 4;
    else if (r >= 0 && A[r * N + c] == 2) {
      r = -1;
      if (s++ == 3) printf("(> <)\n");
      else printf("(O O)\r");
    } else printf("\e[K");
  }
}
#endif
