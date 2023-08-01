#include <stdio.h>
#define M (1234567891)
#define R (31)

static unsigned long long hash_res = 0;

static unsigned long long my_power(unsigned long long base, int exp, int mod)
{
	unsigned long long res = 1;
	while (exp)
	{
		if (exp & 1)
		{
			res = ((res % mod) * (base % mod)) % mod;
		}
		base = ((base % mod) * (base % mod)) % mod;
		exp >>= 1;
	}
	return (res);
}

int main(void)
{
	int 	L;
	char	s[52];

	scanf("%d", &L);
	scanf("%s", s);
	for (int i = 0; i < L; ++i)
	{
		hash_res += (((s[i] - 'a' + 1) % M) * (my_power(R, i, M) % M)) % M;
		hash_res %= M;
	}
	printf("%lld\n", hash_res);
	return (0);
}