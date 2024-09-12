#include <algorithm>
#include <iostream>

#define MAX (1000000)

int dp[MAX + 1];

int main(void) {
  std::cin.tie(NULL)->sync_with_stdio(false);

  int n;

  std::cin >> n;

  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1];
    if (i % 2 == 0)
      dp[i] = std::min(dp[i], dp[i / 2]);
    if (i % 3 == 0)
      dp[i] = std::min(dp[i], dp[i / 3]);
    dp[i] += 1;
  }

  std::cout << dp[n];

  return 0;
}