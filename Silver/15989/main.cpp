#include <iostream>
#define MAX_CNT (10000)

static unsigned long long dp[MAX_CNT + 1];

int main(void)
{
	int	test_cnt;
	int	n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	for (int i = 5; i <= MAX_CNT; ++i)
	{
		dp[i] = dp[i - 1];
		if ((i - 2) % 2 == 0 || (i - 2) % 3 == 0)
			dp[i] += dp[i - 2] - dp[i - 3];
		if ((i - 3) % 2 == 0 || (i - 3) % 3 == 0)
			dp[i] += dp[i - 3] - dp[i - 4];
		
	}
	std::cin >> test_cnt;
	while (test_cnt--)
	{
		std::cin >> n;
		std::cout << dp[n] << std::endl;
	}
	
	return (0);
}