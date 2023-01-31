// https://www.acmicpc.net/problem/11727_2
// 11727_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define FACTOR (10007)

using namespace std;

static unsigned long long dp[1000];

signed main() {
	fastio;

	int n = 0;

	cin >> n;
	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 5;
	for (int i = 3; i < n; ++i)
		dp[i] = (dp[i - 2] % FACTOR * 2 + dp[i - 1] % FACTOR) % FACTOR;
	cout << dp[n - 1] % FACTOR;
	return (0);
}