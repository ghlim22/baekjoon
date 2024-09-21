#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX (50)

int board[MAX][MAX];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, 1, -1, 0};

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int check(int n, int y, int x, int c) {
  int row_cnt = 1;
  int col_cnt = 1;

  for (int i = y - 1; i >= 0 && board[i][x] == c; --i) {
    ++row_cnt;
  }
  for (int i = y + 1; i < n && board[i][x] == c; ++i) {
    ++row_cnt;
  }

  for (int i = x - 1; x >= 0 && board[y][i] == c; --i) {
    ++col_cnt;
  }
  for (int i = x + 1; x >= 0 && board[y][i] == c; ++i) {
    ++col_cnt;
  }

  return max(row_cnt, col_cnt);
}

void input(int *n) {
  char *line = NULL;
  size_t line_size;

  scanf("%d", n);
  getchar();
  for (int i = 0; i < *n; ++i) {
    getline(&line, &line_size, stdin);
    for (int j = 0; j < *n; ++j) {
      board[i][j] = line[j];
    }
  }
  free(line);
}

int main(void) {
  int n;
  int ans = 1;

  input(&n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int cnt = check(n, i, j, board[i][j]);
      for (int k = 0; k < 4; ++k) {
        int y = i + dy[k];
        int x = j + dx[k];
        if (!(y >= 0 && y < n))
          continue;
        if (!(x >= 0 && x < n))
          continue;
        if (board[i][j] == board[y][x])
          continue;
        swap(&board[i][j], &board[y][x]);
        cnt = max(cnt, check(n, i, j, board[i][j]));
        swap(&board[i][j], &board[y][x]);
      }
      ans = max(ans, cnt);
      if (ans == n)
        goto EXIT;
    }
  }

EXIT:
  printf("%d\n", ans);

  return 0;
}