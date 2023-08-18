#include <iostream>
#define MAX_CNT (1000)
#define DIVISOR (1000000009)

static unsigned int dp[MAX_CNT + 1][MAX_CNT + 1];

int main(void)
{
	int t;
	int n;
	int	m;

	/* INITIALZE */
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;

	/* CACULATE */
	for (int i = 4; i <= MAX_CNT; ++i)
	{
		for (int j = 1; j <= MAX_CNT; ++j)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % DIVISOR;
		}
	}

	/* PRINT */
	std::cin >> t;
	while (t--)
	{
		std::cin >> n >> m;
		std::cout << (dp[n][m]) % DIVISOR << std::endl;
	}

	return (0);
}
