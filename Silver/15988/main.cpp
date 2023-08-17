#include <iostream>
#define DIVISOR (1000000009)
#define MAX_CNT (1000000)

static unsigned long long dp[MAX_CNT + 1];

int main(void)
{
	int	test_cnt;
	int	n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= MAX_CNT; ++i)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		dp[i] %= DIVISOR;
	}
	std::cin >> test_cnt;
	while (test_cnt--)
	{
		std::cin >> n;
		std::cout << dp[n] << std::endl;
	}
	return (0);	
}