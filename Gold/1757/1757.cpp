// <https://www.acmicpc.net/problem/1757>
// 1757번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX_TIME (10000)
#define MAX_EX (500)

using namespace std;

static int dp[MAX_TIME + 1][MAX_EX + 1];
static int dist[MAX_TIME + 1];

signed main() {
	fastio;

	int time = 0;
	int max_factor = 0;

	cin >> time >> max_factor;
	for (int i = 1; i <= time; ++i)
		cin >> dist[i];
	
	for (int cur_min = 1; cur_min <= time; ++cur_min)
	{
		dp[cur_min][0] = dp[cur_min - 1][0];	

		for (int factor = 1; factor <= max_factor; ++factor)
		{
			if (cur_min - factor >= 0)
				dp[cur_min][0] = max(dp[cur_min][0], dp[cur_min - factor][factor]);
			dp[cur_min][factor] = dp[cur_min - 1][factor - 1] + dist[cur_min];
		}
	}

	cout << dp[time][0];

	cout << "\n";

/*
	for (int i = 0; i <= time; ++i)
	{
		for (int j = 0; j <= max_factor; ++j)
			cout << dp[i][j] << ' ';
		cout << '\n';	
	}
*/

	return (0);
}