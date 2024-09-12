#include <stdio.h>

#define MAX (100000)
#define DIVISOR (1000000009)
#define ONE (0)
#define TWO (1)
#define THREE (2)

int cache[MAX + 1][3];

int main(void) {
  int n;
  int t;
  int ans;

  cache[1][ONE] = 1;
  cache[2][TWO] = 1;
  cache[3][ONE] = 1;
  cache[3][TWO] = 1;
  cache[3][THREE] = 1;

  for (int i = 4; i <= MAX; ++i) {
    cache[i][ONE] = (cache[i - 1][TWO] % DIVISOR + cache[i - 1][THREE] % DIVISOR) % DIVISOR;
    cache[i][TWO] = (cache[i - 2][ONE] % DIVISOR + cache[i - 2][THREE] % DIVISOR) % DIVISOR;
    cache[i][THREE] = (cache[i - 3][ONE] % DIVISOR + cache[i - 3][TWO] % DIVISOR) % DIVISOR;
  }

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans = 0;
    for (int i = 0; i < 3; ++i) {
      ans += cache[n][i] % DIVISOR;
      ans %= DIVISOR;
    }
    printf("%d\n", ans);
  }

  return 0;
}