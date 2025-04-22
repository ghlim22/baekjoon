#include <stdio.h>

char arr[20][20];

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			scanf(" %c", &arr[i][j]);
	}

	int answer = 400;
	for (int i = 0; i < (1 << n); ++i)
	{
		int sum = 0;
		for (int x = 0; x < n; ++x)
		{
			int tail = 0;
			for (int y = 0; y < n; ++y)
			{
				if (1 & (i >> y))
				{
					tail += (arr[y][x] == 'H' ? 1 : 0);
				} else {
					tail += (arr[y][x] == 'T' ? 1 : 0);
				}
			}
			sum += min(tail, n - tail);
		}
		
		answer = min(answer, sum);
	}

	printf("%d", answer);

	return 0;
}