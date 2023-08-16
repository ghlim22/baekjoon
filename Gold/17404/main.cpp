#include <algorithm>
#include <iostream>
#include <limits.h>
#define SIZE (1000)
#define INF (3000)

typedef enum
{
	COLOR_RED = 0,
	COLOR_GREEN = 1,
	COLOR_BLUE = 2
}	e_color;

static unsigned int	cost[SIZE][3];
static unsigned	int dp[SIZE][3];
static unsigned int	ans = INT_MAX;

int main(void)
{
	int	cnt;

	std::cin >> cnt;
	for (int i = 0; i < cnt; ++i)
		std::cin >> cost[i][COLOR_RED] >> cost[i][COLOR_GREEN] >> cost[i][COLOR_BLUE];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == j)
				dp[0][j] = cost[0][j];
			else
				dp[0][j] = INT_MAX;
		}
		for (int j = 1; j < cnt; ++j)
		{
			dp[j][COLOR_RED] = cost[j][COLOR_RED] + std::min(dp[j - 1][COLOR_BLUE], dp[j - 1][COLOR_GREEN]);
			dp[j][COLOR_GREEN] = cost[j][COLOR_GREEN] + std::min(dp[j - 1][COLOR_RED], dp[j - 1][COLOR_BLUE]);
			dp[j][COLOR_BLUE] = cost[j][COLOR_BLUE] + std::min(dp[j - 1][COLOR_RED], dp[j - 1][COLOR_GREEN]);
		}
		for (int j = 0; j < 3; ++j)
		{
			if (i != j && ans > dp[cnt - 1][j])
				ans = dp[cnt - 1][j];
		}
	}
	std::cout << ans;
	return (0);
}
