#include <ncurses.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
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

int main()
{
  initscr();
  noecho();
  cbreak();
  while (1) {
    if (s & 4) {
      if (s == 4) {
        printw("Press Enter to continue\n");
        while (getch() != '\n') { }
      }
      rs -= time(0) ^ clock() << 3;
      reset();
    }
    clear();
    printw("Move %d\n", s);
    for (char i = -1; i < N; i++) {
      for (char j = 0; j < N; j++)
        printw("%c%d%c", r == i && c == j ? '[' : ' ',
          i < 0 || i > N - 2 ? 3 : A[i][j], r == i && c == j ? ']' : ' ');
      printw("\n");
    }
    char m = getch();
    switch (m) { case 'k': r -= 2; case 'j': r++; c++; case 'h': c -= 2; case 'l': c++; }
    M();
    if (r > N - 2) printw("\\(^ ^)/\n"), s++;
    else if (r >= 0 && r < N - 1 && A[r][c] == 2) {
      r = -1;
      if (s++ == 3) printw("(> <)\n");
    }
  }
}
