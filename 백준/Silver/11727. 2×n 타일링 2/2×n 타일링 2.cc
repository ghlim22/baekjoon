#include <iostream>

#define MAX (1000)
#define DIVISOR (10007)

int cache[MAX + 1];

int main(void) {
  std::cin.tie(NULL)->sync_with_stdio(false);

  int n;

  std::cin >> n;

  cache[1] = 1;
  cache[2] = 3;

  for (int i = 3; i <= n; ++i) {
    cache[i] = cache[i - 2] * 2 % DIVISOR + cache[i - 1] % DIVISOR;
    cache[i] %= DIVISOR;
  }

  std::cout << cache[n];

  return 0;
}