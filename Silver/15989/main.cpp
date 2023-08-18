#include <iostream>
#define MAX_CNT (10000)
#define ONE (0)
#define TWO (1)
#define THREE (2)

static unsigned int	dp[MAX_CNT + 1][3];

int main(void)
{
	int	t;
	int	n;

	/* DP INIT */
	dp[1][ONE] = 1;
	dp[2][ONE] = 1;
	dp[2][TWO] = 1;
	dp[3][ONE] = 1;
	dp[3][TWO] = 1;
	dp[3][THREE] = 1;

	for (int i = 4; i <= MAX_CNT; ++i)
	{
		dp[i][ONE] = dp[i - 1][ONE];
		dp[i][TWO] = dp[i - 2][ONE] + dp[i - 2][TWO];
		dp[i][THREE] = dp[i - 3][ONE] + dp[i - 3][TWO] + dp[i - 3][THREE];
	}

	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		std::cout << dp[n][ONE] + dp[n][TWO] + dp[n][THREE] << std::endl;
	}

	return (0);
}
