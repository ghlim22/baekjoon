#include <stdio.h>

int paper[2187][2187];

int minusone = 0;
int one = 0;
int zero = 0;

void f(int sy, int sx, int size) {
  // check
  int same = 1;
  for (int i = sy; i < sy + size && same; ++i) {
    for (int j = sx; j < sx + size; ++j) {
      if (paper[sy][sx] != paper[i][j]) {
        same = 0;
        break;
      }
    }
  }

  if (same) {
    switch (paper[sy][sx]) {
    case -1:
      minusone++;
      break;
    case 0:
      zero++;
      break;
    case 1:
      one++;
      break;
    }
    return;
  }

  size /= 3;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      f(sy + size * i, sx + size * j, size);
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &paper[i][j]);
    }
  }
  f(0, 0, n);
  printf("%d\n%d\n%d\n", minusone, zero, one);

  return 0;
}