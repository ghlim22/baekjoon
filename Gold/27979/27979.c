#include <stdio.h>

int main(void)
{
	int ans = 0;
	int prev = 0;
	int ball_cnt = 0;
	int max = 0;
	int arr[200000] = {0, };

	scanf("%d", &ball_cnt);
	for (int i = 0; i < ball_cnt; ++i)
	{
		scanf("%d", &arr[i]);
		if (i == 0)
		{
			prev = arr[i];
		}
		else
		{
			if (prev > arr[i])
			{
				ans++;
				if (max < arr[i])
					max = arr[i];
				arr[i] = 1000001;
			}
			else if (prev < arr[i])
			{
				prev = arr[i];
			}
		}
	}
	for (int i = 0; i < ball_cnt; ++i)
	{
		if (arr[i] < max)
			ans++;
	}
	printf("%d\n", ans);
	return (0);
}
