#include <iostream>

#define MAX (11)
#define DIVISOR (10007)

int cache[MAX + 1];

int main(void) {
  std::cin.tie(NULL)->sync_with_stdio(false);

  int t;
  int n;

  cache[1] = 1;
  cache[2] = 2;
  cache[3] = 4;

  for (int i = 4; i <= MAX; ++i) {
    cache[i] = cache[i - 3] + cache[i - 2] + cache[i - 1];
  }

  std::cin >> t;

  while (t--) {
    std::cin >> n;
    std::cout << cache[n] << '\n';
  }

  return 0;
}