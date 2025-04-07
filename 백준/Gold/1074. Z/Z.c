#include <stdio.h>

long f(int y, int x, int n) {
  if (n == 1) {
    return (y * 2 + x);
  }

  int half = (1 << (n - 1));
  long halfsize = (1l << (2 * n - 2));
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
  printf("%ld\n", f(r, c, n));

  return 0;
}