#include <bitset>
#include <iostream>

#define DIVISOR (1000000000)
#define MAX_LEN (100)

static unsigned long long dp[MAX_LEN + 1][10][(1 << 10)];

int main(void)
{
	int					n;
	unsigned long long	ans = 0;

	/* INITIALIZE */
	for (int i = 1; i <= 9; ++i)
	{
		dp[1][i][1 << i] = 1;
	}
	
	for (int i = 2; i <= MAX_LEN; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = 1; k < (1 << 10); ++k)
			{
				switch (j)
				{
				case 0:
					dp[i][j][k | (1 << j)] += dp[i - 1][1][k] % DIVISOR;
					break;
				case 9:
					dp[i][j][k | (1 << j)] += dp[i - 1][8][k] % DIVISOR;
					break;
				default:
					dp[i][j][k | (1 << j)] += (dp[i - 1][j - 1][k] % DIVISOR + dp[i - 1][j + 1][k] % DIVISOR) % DIVISOR;
					break;
				}
			}
		}
	}

	std::cin >> n;
	for (int i = 0; i <= 9; ++i)
	{
		ans += dp[n][i][(1 << 10) - 1] % DIVISOR;
	}
	std::cout << ans % DIVISOR << std::endl;	

	return (0);
}
