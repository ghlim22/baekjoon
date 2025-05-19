#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int A[1000];
int dp[1000];

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}

	std::memset(dp, -1, sizeof(dp));

	std::queue<int> q;
	dp[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int jump = A[cur];
		for (int next = cur + 1; next <= cur + jump && next < N; ++next) {
			if (dp[next] == -1) {
				dp[next] = dp[cur] + 1;
				q.push(next);
			}
			else if (dp[next] > dp[cur] + 1) {
				dp[next] = dp[cur] + 1;
				q.push(next);
			}
		}
	}

	std::cout << dp[N - 1];

	return 0;
}