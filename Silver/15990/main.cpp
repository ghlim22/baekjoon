#include <iostream>
#define MAX_CNT (100000)
#define DIVISOR (1000000009)
#define ONE (0)
#define TWO (1)
#define THREE (2)

static unsigned int	dp[MAX_CNT + 1][3];

int main(void)
{
	int	t;
	int	n;

	/* INITIALZE */
	dp[1][ONE] = 1;
	dp[2][TWO] = 1;
	dp[3][ONE] = 1;
	dp[3][TWO] = 1;
	dp[3][THREE] = 1;

	/* CACULATE */
	for (int i = 4; i <= MAX_CNT; ++i)
	{
		dp[i][ONE] = (dp[i - 1][TWO] + dp[i - 1][THREE]) % DIVISOR;
		dp[i][TWO] = (dp[i - 2][ONE] + dp[i - 2][THREE]) % DIVISOR;
		dp[i][THREE] = (dp[i - 3][ONE] + dp[i - 3][TWO]) % DIVISOR;
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
