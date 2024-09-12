#include <stdio.h>

#define MAX (100000)
#define DIVISOR (1000000009)

int cache[MAX + 1][4];

int main(void) {
  int n;
  int t;
  int ans;

  cache[1][1] = 1;
  cache[2][2] = 1;
  cache[3][1] = 1;
  cache[3][2] = 1;
  cache[3][3] = 1;

  for (int i = 4; i <= MAX; ++i) {
    for (int j = 1; j <= 3; ++j) {
      for (int k = 1; k <= 3; ++k) {
        if (k == j)
          continue;
        cache[i][j] += cache[i - j][k] % DIVISOR;
      }
      cache[i][j] %= DIVISOR;
    }
  }

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans = 0;
    for (int i = 1; i <= 3; ++i) {
      ans += cache[n][i] % DIVISOR;
      ans %= DIVISOR;
    }
    printf("%d\n", ans);
  }

  return 0;
}