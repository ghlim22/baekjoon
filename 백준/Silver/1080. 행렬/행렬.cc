#include <stdio.h>

int a[50][50];
int b[50][50];
int n;
int m;

int is_same() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j])
        return 0;
    }
  }
  return 1;
}

void flip(int y, int x) {
  for (int i = y; i < y + 3; ++i) {
    for (int j = x; j < x + 3; ++j) {
      a[i][j] ^= 1;
    }
  }
}

int main(void) {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf(" %1d", &a[i][j]);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%1d", &b[i][j]);
    }
  }

  int count = 0;
  for (int col = 0; col < m; ++col) {
    for (int row = 0; row < n; ++row) {
      if (col + 3 <= m && row + 3 <= n && a[row][col] != b[row][col]) {
        flip(row, col);
		count++;
      }
    }
  }

  if (is_same()) {
	printf("%d\n", count);
  } else {
	printf("-1\n");
  }

  return 0;
}