#include <stdio.h>

#define MAX (200)
#define DIVISOR (1000000000)

unsigned int cache[MAX + 1];

int main(void) {
  int n;
  int k;

  scanf("%d %d", &n, &k);

  // d[0][x] = 1 for 1 <= i <= k
  for (int i = 1; i <= k; ++i) {
    cache[i] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      cache[j] += cache[j - 1];
      cache[j] %= DIVISOR;
    }
  }

  printf("%d\n", cache[k]);

  return 0;
}