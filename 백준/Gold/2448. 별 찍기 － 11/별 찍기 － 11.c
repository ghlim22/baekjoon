#include <stdio.h>

char board[3072][6145];

void f(int sy, int sx, int n) {
  if (n == 3) {
    board[sy][sx + 2] = '*';
    board[sy + 1][sx + 1] = '*';
    board[sy + 1][sx + 3] = '*';
    board[sy + 2][sx] = '*';
    board[sy + 2][sx + 1] = '*';
    board[sy + 2][sx + 2] = '*';
    board[sy + 2][sx + 3] = '*';
    board[sy + 2][sx + 4] = '*';
    return;
  }

  f(sy, sx + n / 2, n / 2);
  f(sy + n / 2, sx, n / 2);
  f(sy + n / 2, sx + n, n / 2);
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < 2 * n; ++x) {
      board[y][x] = ' ';
    }
  }

  f(0, 0, n);

  for (int i = 0; i < n; ++i) {
    printf("%s\n", board[i]);
  }

  return 0;
}
