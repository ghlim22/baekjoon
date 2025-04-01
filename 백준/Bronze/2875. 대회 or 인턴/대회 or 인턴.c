#include <stdio.h>

int main(void) {
  int n, m, k;

  scanf("%d %d %d", &n, &m, &k);

  int team = 0;
  while (n >= 2 && m >= 1 && (n + m - 3) >= k) {
    n -= 2;
    m -= 1;
    team++;
  }

  printf("%d\n", team);

  return 0;
}