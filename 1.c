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
  4 > (R -= *a) ? (R = 2[a] >> 6-R-R, 0[R%2 ? &r : &c] += ~-(2 & R)) : (R = Z);
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
        f |= 0 > (h -~- Z) * (n - !n);
      }
    #define R { h = 0; F(c, N) h += b[c]; if (h == N
      if (!r ) R)
        f |= 1;
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
      if ((C = b - A) && N == h + 2) {
        F(r, N) Z |= !r[b - N] ^ !r[b];
        F(r, Z) {
          if (C - r && r != C - N && !(Z & 1))
            F(c, N) !c[b] && (c[A + r] += (t = !A[r + c]));
          r += Z / N;
        }
        Z &= -2;
      }
    }
  }
#undef f
#undef R
#undef I
  return Z - R ? r > N - 2 ? (s += 2) : *a - 2 ? 1 : (r |= (s++ - 3) >> 2, 2 + s >> 1) : 0;
}

#ifndef FUZZ
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

struct termios S, T;
FILE *a;

void e()
{
  tcsetattr(0, TCSAFLUSH, &S);
  a && fclose(a);
}

int main(int t, char *argv[])
{
  tcgetattr(0, &S);
  atexit(e);
  T = S; T.c_lflag &= ~ECHO & ~ICANON;
  tcsetattr(0, 0, &T);

  if (t && (a = fopen(argv[1], "wb"))) setbuf(a, 0);
  else printf("No audio device supplied, game will be silent (_ _)\n");

  while (t = 2) {
    if (4 & s) R(time(0) ^ clock() << 3); else q: printf("\e[%dA", N + 2);
    t & 4 || printf("Move %d\e[K\n", s);
    for (signed char i = -1; i - N; i++)
      for (char j = 0; j < N; j++)
        putchar((putchar(!~i * putchar((*q = r - i || c - j) * -';' + 91) | 2 > N - i ? 61 : A[i * N + j][".*o"]), 0[q]["] "])),
        j -~- N || putchar(10);
    if (t > 3) {
      printf("\nPress Enter to continue\n");
      while (getchar() != '\n') { }
      continue;
    }
    printf((const char *[]){"", "\e[K", "(O O)\r", "(> <)\n", "\\(>-<)/\n", "\\(^ ^)/\n"}[t = M(getchar())]);
    if (a && t) {
      static int16_t S[8290];
      unsigned s = sizeof S;
      int l = ((t > 1) + (t > 2)) * 2400, p = (('3'-t*5)*t-154)*t+144;
      for (int i = 0 * (p && (p = 1309 / p)); i < l + 3490; i++)
        S[i] = (i < 1090 ? i % 109 < 54 : i < l + 1090 ? p ? i / (p / 2) & 1 : !((s = s * 997) % 3) : 0) << 11;
      fwrite(S, sizeof(int16_t), l + 3490, a);
      fflush(a);
    }
    if (t++ > 2) goto q;
  }
}
#endif
