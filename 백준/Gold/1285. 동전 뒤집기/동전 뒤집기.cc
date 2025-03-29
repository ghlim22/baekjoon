#include <stdio.h>
#include <algorithm>

using namespace std;

static int ans = 400;
static int n;
static int arr[20][20];

signed main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char c;
			scanf(" %1c", &c);
			if (c == 'H')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}

	int limit = 1 << n;

	for (int mask = 0; mask < limit; ++mask)
	{
		int sum = 0;

		for (int col = 0; col < n; ++col)
		{
			int tail_cnt = 0;

			for (int row = 0; row < n; ++row)
			{
				if ((mask >> row) & 1)
				{
					if (arr[row][col] == 1)
						tail_cnt++;
				}
				else if (arr[row][col] == 0)
					tail_cnt++;
			}
			sum += min(tail_cnt, n - tail_cnt);
		}
		ans = min(ans, sum);
	}

	printf("%d", ans);

	return (0);
}