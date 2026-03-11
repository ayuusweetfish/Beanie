#define N 5

typedef char p[N * N - N];
p A, q;
signed char r0, s = 5, r, c, f, Z;
unsigned Y;

#define F(a, b) for (char a = 0; a < b; a++)
void R(unsigned M)
{
  F(r, (Z = ~-N * N)) A[r] = 0;
  s = !(r = c[A], f = r--);
  c = ((Y = 1 + (Y - M) * 69069) / 2) % N;
  r0 = (Y + (Y & Z)) % N;
}
char M(unsigned R)
{
  char h = 'h', t = h < (R += R == h), *a = t + "Aix6", *b = A, C;
  4 > (R -= *a) && (R = 2[a] >> 6-R-R, 0[R%2 ? &r : &c] += ~-(2 & R));
  if (N + ~(r += (h = !~(c -= c / N - !~c)) < ~r) && ~r && !h[a = c + b + r * N]) {
    if (f *= s - 6 + s) {
    #define I(R, C) \
      -~C && h < Z & (unsigned)R < N && \
        2 > *(b = R + N * (C) + A) && *b | !(*a - 2 || C - r && R - c) && \
        (*b -= f + f, q[t++] = b - A, h += Z * !(C))
      F(n, 2 + s - *a) {
        t = !(*a = -~n);
        F(C, N) I(C, N - 2);
        F(T = h, t)
          R = (C = h[q]) % N, C /= N,
          I(R + T, C), I(~-R, C), I(R, C - T);
        F(r, Z) r[A] &= 3;
        f |= 0 > (h - ~ - Z) * (n - !n);
      }
    #define R { h = 0; F(c, N) h += b[c]; if (h == N
      if (!r)
        R) f |= 1;
        f |= r0++ && r0 < N & A[r0 - 2] & r0[b = A]; r0--;
      }
      f = 4 - (*a = -~(f & 1)) - s;
    } else
      R-2) r0 = c;
      *a = -~(s & 2 || c == r0 || r && 4 & Y && ~(r0 = c));
      f ^= r | c == r0;
    }
    #define f ) { F(i, N) b[i] = A[(i - (i > N - 2)) * N + c] = t; b[c]++;
    if (b = a - c, t = 1, *a / 2 f }
    while (t--)
      for (b = A; b < Z + A; b += N)
        R-1) F(c, N) if (t = !c[b] f break; }
        if (b - A && h == N - 2) {
          h = 0;
          F(r, N) h |= b[r] ^ b[r - N];
          if (!h) {
            F(r, N - 1) if (r * N != b - A && r * N != b - A - N)
              F(c, N) if (!b[c] && (t = !A[r * N + c])) A[r * N + c]++;
          }
        }
      }
  }
  return r > N - 2 ? ~-(s += 2) : *a - 2 ? 0 : (r |= (s++ - 3) >> 2, s >> 1);
}
#undef f
#undef R
#undef I

#ifndef FUZZ
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

void P()
{
  for (char i = -1; i - N; i++) {
    for (char j = 0; j < N; j++)
      putchar((*q = r - i | c - j) ? ' ' : '['),
      putchar((putchar(!~i | i > N - 2 ? '=' : A[i * N + j][".*o"]), " ]"[!*q]));
    putchar('\n');
  }
}
void Q() { printf("\e[%dA", N + 2); }

void B(int l, int p)
{
  unsigned s = 123;
  for (int i = 0; i < l; i++) {
    int16_t sample = p ? ((i % p < p / 2) ? 3000 : 0) : ((s = s * 997) % 3 == 0 ? 3000 : 0);
    fwrite(&sample, sizeof(int16_t), 1, a);
    fflush(a);
  }
}

int main(int argc, char *argv[])
{
  tcgetattr(0, &S);
  atexit(e);
  T = S; T.c_lflag &= ~ECHO & ~ICANON;
  tcsetattr(0, 0, &T);

  // ./a.out >(sox --buffer 1024 -t s16 -r 48000 -c 1 - -d 2>/dev/null)
  if (argc >= 1) a = fopen(argv[1], "wb");
  if (a) setbuf(a, 0);
  else printf("No audio device supplied, game will be silent (_ _)\n");

  while (1) {
    if (4 & s) R(time(0) ^ clock() << 3); else Q();
    printf("Move %d\e[K\n", s);
    P();
    char t;
    printf((const char *[]){"\e[K", "(O O)\r", "(> <)\n", "\\(>-<)/\n", "\\(^ ^)/\n"}[t = M(getchar())]);
    if (a) {
      if (t >= 3) B(4800, 54);
      else if (t == 2) B(4800, 218);
      else if (t == 1) B(2400, 0);
      else B(480, 109);
    }
    if (t >= 2) {
      Q(); P();
      printf("\nPress Enter to continue\n");
      while (getchar() != '\n') { }
    }
  }
}
#endif
