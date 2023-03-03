// https://www.acmicpc.net/problem/22983
// 22983번 

#include <iostream>
#include <algorithm>
#define ll long long
#define MAX_LEN (3000)

using namespace std;

static char chess[MAX_LEN][MAX_LEN];
static ll dp[MAX_LEN + 1];

static bool check_chess(int x, int y)
{
	char cur, left, up, dia_left;

	cur = chess[y][x];
	left = chess[y][x - 1];
	up = chess[y - 1][x];
	dia_left = chess[y - 1][x - 1];

	return ((cur == dia_left) && (cur != left) && (cur != up));
}

signed main() 
{
	int n, m;
	ll	ans, prev, temp;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf(" %c", &chess[i][j]);
		}
	}

	ans = n * m;
	prev = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			temp = dp[j];
			if (check_chess(j, i))
			{
				dp[j] = min(min(dp[j], dp[j - 1]), prev) + 1;
			}
			else
			{
				dp[j] = 0;
			}
			prev = temp;
			ans += dp[j];
		}
	}

	printf("%lld", ans);

	return (0);
}