// <https://www.acmicpc.net/problem/2293>
// 2293번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

static int coins[100];
static int dp[10001];

signed main() 
{
	fastio;

	int coin_cnt = 0;
	int total = 0;

	cin >> coin_cnt >> total;

	for (int i = 0; i < coin_cnt; ++i)
		cin >> coins[i];

	dp[0] = 1;
	
	for (int i = 0; i < coin_cnt; ++i)
	{
		for (int j = coins[i]; j <= total; ++j)
		{
			if (dp[j - coins[i]] > 0)
			{
				dp[j] += dp[j - coins[i]];
			}
		}
	}

	cout << dp[total];

	return (0);
}