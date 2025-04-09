#include <stdio.h>

char board[6561][6562];

void f(int n, int sy, int sx) {
  /* n = 3 pattern */
  if (n == 3) {
    for (int y = sy; y < sy + n; ++y) {
      if (y > sy && y < sy + n - 1) {
        board[y][sx] = '*';
        board[y][sx + n - 1] = '*';
      } else {
        for (int x = sx; x < sx + n; ++x)
          board[y][x] = '*';
      }
    }
    return;
  }

  n /= 3;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i == 1 && j == 1)
        continue;
      f(n, sy + i * n, sx + j * n);
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      board[y][x] = ' ';
    }
  }

  f(n, 0, 0);
  for (int i = 0; i < n; ++i)
    printf("%s\n", board[i]);

  return 0;
}