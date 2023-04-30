#include <stdio.h>

int main(void)
{
	int a[10] = {1, };
	int i, j, n, m;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; ++i)
	{
		a[0] *= (n - i + 1);
		for (j = 1; j < 10; ++j)
		{
			a[j] *= (n - i + 1);
			a[j] += a[j - 1] / 10000;
			a[j - 1] %= 10000;
		}
		for (j = 9; j > 0; --j)
		{
			a[j - 1] += (a[j] % i) * 10000;
			a[j] /= i;
		}
		a[j] /= i;
	}
	for (j = 10; !a[--j]; )
		;
	for (printf("%d", a[j]); j--; printf("%04d", a[j]))
		;
	return (0);
}
