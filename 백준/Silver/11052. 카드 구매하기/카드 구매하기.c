#include <stdio.h>

#define MAX (1000)

int cache[MAX + 1];

int main(void) {
  int n;

  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &cache[i]);
  }

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i / 2; ++j) {
      if (cache[i] < cache[j] + cache[i - j])
        cache[i] = cache[j] + cache[i - j];
    }
  }

  printf("%d", cache[n]);

  return 0;
}