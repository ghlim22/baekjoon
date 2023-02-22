// <https://www.acmicpc.net/problem/1757>
// 1757번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_TIME (10000)
#define MAX_EX (500)
#define RUN (0)
#define REST (1)

using namespace std;

static int dp[MAX_TIME][MAX_EX][2];
static int dist[MAX_TIME];

signed main() {
	fastio;

	int time = 0;
	int max_factor = 0;

	/*
		dp[i][j][2]
		i: current minute.
		j: current exhaustion factor.
		0: run
		1: rest
	*/

	cin >> time >> max_factor;
	for (int i = 0; i < time; ++i)
		cin >> dist[i];
	
	dp[0][1][RUN] = dist[0];
	dp[0][0][REST] = 0;

	for (int i = 1; i < time; ++i)
	{
		for (int j = 0; j <= max_factor; ++j)
		{
			if (j == 0)
			{
				dp[i][j][REST] = max(dp[i - 1][j + 1][REST], dp[i - 1][j + 1][RUN]);
				dp[i][j][REST] = max(dp[i][j][REST], dp[i - 1][j][REST]); // rest consecutively.
			}
			else if (j == max_factor)
			{
				dp[i][j][RUN] = dp[i - 1][j - 1][RUN];
			}
			else
			{
				dp[i][j][RUN] = max(dp[i - 1][0][REST], dp[i - 1][j - 1][RUN]) + dist[i];
				dp[i][j][REST] = max(dp[i - 1][j + 1][REST], dp[i - 1][j - 1][RUN]);
			}
		}
	}

	cout << dp[time - 1][0][REST];













		/*
	dp[0][0] = 0; // rest at first minute.
	dp[0][1] = dist[0]; // run at first minute.
	for (int i = 1; i < time; ++i)
	{
		for (int j = 0; j <= max_factor; ++j)
		{
			if (j == 0) // rest at i minute. run at last min and rest at current min or rest at last min and current min consecutively.
				dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]);
			else if (j == 1)
				dp[i][j] = max(dp[i - 1][0] + dist[i], dp[i - 1][2]);
			else if (j == max_factor)
				dp[i][j] = dp[i - 1][max_factor - 1] + dist[i];
			else // rest or run...
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j + 1]);
		}
	}
	cout << dp[time - 1][0];
	*/
	return (0);
}