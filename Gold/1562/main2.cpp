#include <iostream>

#define DIVISOR (1000000000)
#define MAX_LEN (100)

static unsigned long long dp[MAX_LEN + 1][10][(1 << 2)];
static int n;

static unsigned long long func(int len, int digit, int bit)
{
	unsigned long long	&ret = dp[len][digit][bit];

	if (ret > 0)
		return (ret);
	if (len == n - 1)
		return ((bit == 3) ? 1 : 0);
	if (digit > 0)
	{
		ret += func(len + 1, digit - 1, bit | ((digit - 1 == 0) ? 1 : 0));
		ret %= DIVISOR;
	}
	if (digit < 9)
	{
		ret += func(len + 1, digit + 1, bit | ((digit + 1 == 9) ? 2 : 0));
		ret %= DIVISOR;
	}
	return (ret);
}

int main(void)
{
	unsigned long long	ans = 0;

	std::cin >> n;
	for (int i = 1; i <= 9; ++i)
	{
		ans += func(0, i, (i == 9) ? 2 : 0);
		ans %= DIVISOR;
	}
	std::cout << ans << std::endl;

	return (0);
}
