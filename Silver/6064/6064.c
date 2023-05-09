#include <stdio.h>

static int gcd(int x, int y);
static int lcm(int x, int y);

int main(void)
{
	int test_cnt;

	scanf("%d", &test_cnt);
	while (test_cnt--)
	{
		int M, N, x, y, year, limit;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		limit = lcm(M, N);
		for (year = x; year <= limit; year += M)
		{
			if ((year - 1) % N  + 1 == y)
				break;
		}
		printf("%d\n", year <= limit ? year : -1);
	}
	return (0);
}

static int lcm(int x, int y)
{
	return (x * y / gcd(x, y));
}

static int gcd(int x, int y)
{
	int r;

	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return (x);
}