#include <iostream>
#define MAX_CNT (100000)
#define DIVISOR (1000000009)
#define ODD (0)
#define EVEN (1)

static unsigned int dp[MAX_CNT + 1][2];

int main(void)
{
	int t;
	int n;

	/* INITIALZE */
	dp[1][ODD] = 1;
	dp[2][ODD] = 1;
	dp[2][EVEN] = 1;
	dp[3][ODD] = 2;
	dp[3][EVEN] = 2;

	/* CACULATE */
	for (int i = 4; i <= MAX_CNT; ++i)
	{
		dp[i][ODD] = (dp[i - 1][EVEN] + dp[i - 2][EVEN] + dp[i - 3][EVEN]) % DIVISOR;
		dp[i][EVEN] = (dp[i - 1][ODD] + dp[i - 2][ODD] + dp[i - 3][ODD]) % DIVISOR;
	}

	/* PRINT */
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		std::cout << (dp[n][ODD]) % DIVISOR << " " << (dp[n][EVEN]) % DIVISOR << std::endl;
	}

	return (0);
}
