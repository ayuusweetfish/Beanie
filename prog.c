#ifndef N
#define N 5
#endif

typedef char p[N * N - N];
p A, B;
signed char r0, s = 5, r, c, f, Z;
unsigned Y;

#define F(a, b) for (char a = 0; a < b; a++)
void R(unsigned M)
{
  F(r, (Z = ~-N * N)) A[r] = 0;
  r0 = (s = !(r = c[A], f = r--), c = ((Y = 1 + (Y - M) * 69069) / 2) % N, (Y + (Y & Z)) % N);
}
char M(unsigned R)
{
  char h = 'h', C = R, t = R += C == h, *a = "Aix6", *b = A;
  4 > (R -= a++[t = h < t]) ? Y + (R = 1[t + a] >> 6-R-R, 0[R%2 ? &r : &c] += ~-(2 & R)) : (R = !(R - 8) | Z);
  if (N +~( r += (h = !~(c -= c / N - !~c)) < ~r) && ~r && !h[a = c + b + r * N]) {
    if (f *= s - 6 + s) {
    #define R(R, C) \
      -~C && h < Z & (unsigned)R < N && \
        2 > *(b = R + N * (C) + A) && *b | !(2 - *a || C - r && R - c) && \
        (*b -= f + f, B[t++] = b - A, h += Z * !(C))
      F(n, 2 + s - *a) {
        t = !(*a =-~ n);
        F(C, N) R = R(C, N - 2);
        F(T = h, t)
          R = (C = h[B]) % N, C /= N,
          R(R + T, C), R(~-R, C), R(R, C - T);
        F(r, Z) r[A] &= 3;
        f |= 0 > (h -~- Z) * (n - !n);
      }
    #undef R
    #define R { h = 0; F(c, N) h += b[c]; if (h == N
      if (!r)
        R) f |= 1;
        f |= r0++ && r0 < N & A[r0 - 2] & r0[b = A]; r0--;
      }
      f = 4 - (*a =-~ (f & 1)) - s;
    } else
      R-2) r0 = c;
      *a = 1 << (s & 2 || c == r0 || r && 4 & Y && ~(r0 = c));
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
          if (C - r && r + N - C && !(Z & 1))
            F(c, N) c[A + r] += !c[b] && (t = !A[r + c]);
          r += Z / N;
        }
        Z &= -2;
      }
    }
  }
#undef f
#undef R
  return 1 < R - Z ? r > N - 2 ? (s += 2) : *a - 2 ? 1 : (r |= (s++ - 3) >> 2, 2 + s >> 1) : 6 * (C = R - Z);
}

#ifndef NO_MAIN
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

struct termios S, U;
FILE *a;

void e(void)
{
  tcsetattr(a && fclose(a), TCSAFLUSH, &S);
}

void w(long long n)
{
  while (n) putchar(n % 128), n >>= 7;
}

int main(int T, char *argv[])
{
  tcgetattr(0, &S);
  U = S; U.c_lflag &= ~ECHO & ~ICANON;
  tcsetattr(atexit(e), 0, &U);

  T && (a = fopen(argv[1], "wb")) ? setbuf(a, 0)
    : (w(2368795716511872974), w(8495621981700207332), w(7440143561770350704),
       w(2367120232991520481), w(8421053345252782818), w(45414784422944));

  while (T = 2) {
    uint16_t S, E;
    if (4 & s) R(time(0) ^ clock() << 3 ^ (long long)A >> 12); else T:T - 7 ? w(17553960347 + (N << 21) - 2619392 * (N & 8)) : exit(0);
    for (signed char i = !(T++ & 4 || putchar((w(34359738368 * s + 0x4bb66d820cbdb7cd), 10))) - N; i - N * N;
      i += i + 2977 % putchar((putchar((i >> 7) * putchar((*B = T && r * N - i + c) * -';' + 91) | Z <= i ? 61 : A[i][".*o"]), 0[B]["] "])) && i % N -~- N || putchar(10));
    if (T > 4) {
      w(7965323610900178954), w(8054269566225527540), w(47482438056558);
      while (T = 10 - getchar())
        if (-T < s << 5 && s <~- (T = 2977 % T - ']' ? 1 | T % 8 : T / -13)) goto T;
      continue;
    }
    for (int p = (w((T = E = M(getchar()))[(long long []){0, 145*145*';', 457848661928, 354729598760, 5837632671028316, 5837641771095132, 0xa52aaf2dbca2e7e}]), (('3'-T*5)*T-154)*T+144), l = 3490 + ((T > 1) + (T > 2)) * 2400, i = (p && (p = 1309 / p)) & !E; (a && fflush(a) || i - l) && E; i += !a || fwrite(&S, 2, !(S & 4), a))
      S = (i < 1090 ? 54 > i % 109 : i < l - 2400 ? p ? i / (p / 2) & 1 : !((E *= 997) % 3) : 0) << 11;
    if (T ++> 2) goto T;
  }
}
#endif
