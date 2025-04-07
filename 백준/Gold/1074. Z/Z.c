#include <stdio.h>

int f(int y, int x, int n) {
  if (n == 1) {
    return (y * 2 + x);
  }

  int half = (1 << (n - 1));
  int halfsize = (1 << (2 * n - 2));
  if (y < half) {
    if (x < half) {
      return f(y, x, n - 1);
    } else {
      return halfsize + f(y, x - half, n - 1);
    }
  } else {
    if (x < half) {
      return halfsize * 2 + f(y - half, x, n - 1);
    } else {
      return halfsize * 3 + f(y - half, x - half, n - 1);
    }
  }
}

int main(void) {
  int n, r, c;
  scanf("%d %d %d", &n, &r, &c);
  printf("%d\n", f(r, c, n));

  return 0;
}