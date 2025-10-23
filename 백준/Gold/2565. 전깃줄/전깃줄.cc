#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

int dp[100];

int main(void) {
  fastio;

  int n;
  std::cin >> n;

  std::vector<pii_t> v;
  for (int i = 0; i < n; ++i) {
	int a, b;
	std::cin >> a >> b;
	v.push_back({a, b});
  }

  std::sort(v.begin(), v.end());

  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
	dp[i] = 1;
	for (int j = 0; j < i; ++j) {
		if (v[i].second > v[j].second) {
			dp[i] = std::max(dp[i], dp[j] + 1);
		}
	}
  }

  int answer = n - *std::max_element(dp, dp + n);
  std::cout << answer;

  return 0;
}