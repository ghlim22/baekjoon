#include <stdio.h>

#define MAX (10)

int cache[MAX + 1];

int main(void) {
  int n;
  int t;

  cache[1] = 1;
  cache[2] = 2;
  cache[3] = 4;

  for (int i = 4; i <= MAX; ++i) {
    cache[i] = cache[i - 3] + cache[i - 2] + cache[i - 1];
  }

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", cache[n]);
  }

  return 0;
}