#include <stdio.h>

int main(void)
{
	int ball_cnt;
	int max = 0;
	int cnt = 0;
	int init_top;
	int cur_top;
	int prev;

	scanf("%d", &ball_cnt);
	for (int i = 0; i < ball_cnt; ++i)
	{
		int weight;
		scanf("%d", &weight);
		if (i == 0)
		{
			init_top = weight;
			cur_top = weight;
		}
		if (i > 0)
		{
			if (prev > weight)
			{
				if (cnt == 0)
					cur_top = weight;
				else if (cur_top >= weight)
					cur_top = weight;
				else
					
			}
			else
				prev = weight;
		}
	}
	printf("%d\n", cnt);

	return (0);
}