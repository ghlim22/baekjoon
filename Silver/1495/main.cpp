#include <cstring>
#include <iostream>

#define MAX_CNT 100
#define MAX_VOLUME 1000
#define CHECK_BOUND(x, y, z) ((x) <= (y) && (y) <= (z))

static int 	vol[MAX_CNT + 1];
static bool dp[MAX_CNT + 1][MAX_VOLUME + 1];
static int n;
static int s;
static int m;
static int ans = -1;

int main(void)
{
	std::cin >> n >> s >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> vol[i];
	memset(dp, 0x00, sizeof(bool) * (MAX_CNT + 1) * (MAX_VOLUME + 1));
	dp[0][s] = true;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (dp[i - 1][j])
			{
				if (CHECK_BOUND(0, j - vol[i], m))
					dp[i][j - vol[i]] = true;
				if (CHECK_BOUND(0, j + vol[0], m))
					dp[i][j + vol[i]] = true;
			}
		}
	}
	for (int i = 0; i <= m; ++i)
	{
		if (dp[n][i])
			ans = i;
	}
	std::cout << ans;
	
	return 0;
}
