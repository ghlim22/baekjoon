#include <stdio.h>
#define MAX_SIZE (1000)

static int	matrix[MAX_SIZE][MAX_SIZE];
static int	dp[MAX_SIZE][MAX_SIZE];
/*
 * dp[i][j]: (i, j)를 우하단의 끝점으로 가정할 때, 해당 영역에 고를 수 있는 최대 크기의 정사각형의 한 변의 길이.
 * matrix[i][j] == 1 이면, 해당 칸을 우하단 모서리로 둔다. dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
 */
static int	maximum_size;

static int get_min(int x, int y)
{
	return (x < y ? x : y);
}

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			scanf("%1d", &matrix[i][j]);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == 0 || j == 0)
				dp[i][j] = matrix[i][j];
			else if (matrix[i][j] == 1)
				dp[i][j] = get_min(get_min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
			else
				dp[i][j] = 0;
			
			if (dp[i][j] > maximum_size)
				maximum_size = dp[i][j];
		}
	}

	printf("%d", maximum_size * maximum_size);

	return (0);
}