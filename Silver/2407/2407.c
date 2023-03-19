#include <stdio.h>
#define MAX_NUM (100)
#define FACTOR (10000000000000000)
static long long arr1[MAX_NUM + 1][MAX_NUM + 1];
static long long arr2[MAX_NUM + 1][MAX_NUM + 1]; 

int main(void)
{
	int 		n;
	int 		m;
	int 		i;
	int 		j;
	int 		cnt = 15;
	long long 	tmp;

	scanf("%d %d", &n, &m);
	for (i = 0; i <= n; ++i)
	{
		arr1[i][0] = 1;
		arr1[i][i] = 1;
	}
	for (i = 0; i <= n; ++i)
	{
		for (j = 0; j <= n; ++j)
			arr2[i][j] = 0;
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j < i; ++j)
		{
			arr1[i][j] = arr1[i - 1][j - 1] + arr1[i - 1][j];
			arr2[i][j] = arr2[i - 1][j - 1] + arr2[i - 1][j];
			if (arr1[i][j] >= FACTOR)
			{
				arr2[i][j]++;
				arr1[i][j] -= FACTOR;
			}
		}
	}
	tmp = arr1[n][m];
	while (tmp > 9)
	{
		tmp /= 10;
		cnt--;
	}
	if (arr2[n][m] == 0)
		printf("%lld\n", arr1[n][m]);
	else
	{
		printf("%lld", arr2[n][m]);
		while (cnt--)
			printf("0");
		printf("%lld", arr1[n][m]);
	}
	return (0);
}