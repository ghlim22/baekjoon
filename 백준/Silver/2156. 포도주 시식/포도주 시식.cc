#include <algorithm>
#include <iostream>

#define MAX (10000)

int cache[MAX + 1][3];
int input[MAX + 1];

int main(void) {
  std::cin.tie(NULL)->sync_with_stdio(false);

  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> input[i];
  }

  cache[1][1] = input[1];
  cache[1][2] = input[1];
  for (int i = 2; i <= n; ++i) {
    cache[i][0] =
        std::max(cache[i - 1][0], std::max(cache[i - 1][1], cache[i - 1][2]));
    cache[i][1] = cache[i - 1][0] + input[i];
    cache[i][2] = cache[i - 1][1] + input[i];
  }
  unsigned int ans = std::max(cache[n][0], std::max(cache[n][1], cache[n][2]));
  std::cout << ans;

  return 0;
}