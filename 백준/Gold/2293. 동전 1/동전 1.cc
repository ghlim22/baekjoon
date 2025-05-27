#include <algorithm>
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

	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (j - v[i] >= 0)
				dp[j] += dp[j - v[i]];
		}
	}

	std::cout << dp[K];

	return 0;
}