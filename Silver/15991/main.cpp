#include <iostream>
#define MAX_CNT (100000)
#define DIVISOR (1000000009)
#define ONE (0)
#define TWO (1)
#define THREE (2)

static unsigned int dp[MAX_CNT + 1][3];

int main(void)
{
	int t;
	int n;

	/* INITIALZE */
	dp[1][ONE] = 1;
	dp[2][ONE] = 1;
	dp[2][TWO] = 1;
	dp[3][ONE] = 1;
	dp[3][THREE] = 1;
	dp[4][ONE] = 2;
	dp[4][TWO] = 1;
	dp[5][ONE] = 2;
	dp[5][TWO] = 1;
	dp[6][ONE] = 3;
	dp[6][TWO] = 2;
	dp[6][THREE] = 1;

	/* CACULATE */
	for (int i = 7; i <= MAX_CNT; ++i)
	{
		dp[i][ONE] = (dp[i - 2][ONE] + dp[i - 2][TWO] + dp[i - 2][THREE]) % DIVISOR;
		dp[i][TWO] = (dp[i - 4][ONE] + dp[i - 4][TWO] + dp[i - 4][THREE]) % DIVISOR;
		dp[i][THREE] = (dp[i - 6][ONE] + dp[i - 6][TWO] + dp[i - 6][THREE]) % DIVISOR;
	}

	/* PRINT */
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		std::cout << (dp[n][ONE] + dp[n][TWO] + dp[n][THREE]) % DIVISOR << std::endl;
	}

	return (0);
}
