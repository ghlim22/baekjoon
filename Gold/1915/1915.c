#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE (1000)

static int board[MAX_SIZE][MAX_SIZE];
static int dp[MAX_SIZE][MAX_SIZE];
static int n, m;

static bool check(int x, int y)
{
	if (x - 1 < 0 || y - 1 < 0)
		return (false);
	return (board[y - 1][x] && board[y][x - 1] && board[y - 1][x - 1]);
}

static int get_max(int a, int b, int c)
{
	int max = a;

	if (b > max)
		max = b;
	return ((max > c) ? max : c);
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			scanf("%1d", &board[i][j]);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int cnt;

			if (i - 1 < 0 || j - 1 < 0)
				cnt = board[i][j];
			else
				cnt = get_max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);

			if (board[i][j] && i == j && check(j, i))
				dp[i][j] = cnt + 1;
			else
				dp[i][j] = cnt;
		}
	}

	printf("%d\n", dp[n - 1][m - 1]);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			printf("%d", dp[i][j]);
		printf("\n");
	}

	return (0);
}