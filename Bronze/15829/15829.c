#include <stdio.h>
#define MODULAR (1234567891)

/*
unsigned long long mod_power(int base, int exp, int mod)
{
	unsigned long long ans;

	ans = 1;
	while (exp)
	{
		if (exp & 1)
		{
			ans *= base % mod;
		}
		base = ((base % mod) * (base % mod)) % mod;
		base %= mod;
		ans %= MODULAR;
		exp >>= 1;
	}
	return (ans % MODULAR);
}
*/

int main(void)
{
	char		c;
	int			cnt;
	unsigned long long tmp;
	unsigned long long	ans;

	cnt = 0;
	ans = 0;

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; ++i)
	{
		scanf(" %c", &c);
		tmp = (int)c - 'a' + 1;
		for (int j = 0; j < i; ++j)
			tmp = ((tmp % MODULAR) * 31) % MODULAR;
		ans += tmp;
		ans %= MODULAR;
	}
	printf("%llu", ans);
	return (0);
}
