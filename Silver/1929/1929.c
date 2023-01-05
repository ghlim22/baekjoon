#include <stdio.h>
#include <math.h>

static char prime[1000001];

int main(void)
{
	int m;
	int n;

	scanf("%d %d", &m, &n);
	int upper = (int)sqrt(n) + 1;
	prime[0] = 1;
	prime[1] = 1;
	 for (int i = 2; i <= upper; ++i)
	 {
		 if (prime[i] == 1)
		 	continue;
		for (int j = 2; i * j <= n; ++j)
			prime[i * j] = 1;
	 }
	 for (int i = m; i <= n; ++i)
	 {
		 if (prime[i] == 0)
		 	printf("%d\n", i);
	 }
	 return 0;
}