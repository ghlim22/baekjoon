#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int dp[10001];

int main()
{
	int N, K;
	std::cin >> N >> K;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> v[i];
	}

	std::memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= K; ++j) {
			int prev = j - v[i];
			if (prev < 0)
				continue;
			if (dp[prev] == -1)
				continue;
			if (dp[j] == -1) {
				dp[j] = dp[prev] + 1;
			}
			else {
				dp[j] = std::min(dp[j], dp[prev] + 1);
			}
		}
	}

	std::cout << dp[K];

	return 0;
}