#include <stdio.h>
#define MAX_SIZE (1000)

static int	matrix[MAX_SIZE][MAX_SIZE];
static int	dp[MAX_SIZE + 1];

static int get_min(int x, int y)
{
	return (x < y ? x : y);
}

int main(void)
{
	int n, m, prev, temp, maxsqlen;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			scanf("%1d", &matrix[i][j]);
	}

	prev = 0;
	maxsqlen = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			temp = dp[j];
			if (matrix[i - 1][j - 1] == 1)
			{
				dp[j] = get_min(get_min(dp[j], dp[j - 1]), prev) + 1;
			}
			else
			{
				dp[j] = 0;
			}
			if (dp[j] > maxsqlen)
				maxsqlen = dp[j];
			prev = temp;
		}
	}
	printf("%d", maxsqlen * maxsqlen);

	return (0);
}