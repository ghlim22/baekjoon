#include <stdio.h>

int main(void)
{
	int test_cnt;
	int	height;
	int width;
	int	order;

	scanf("%d", &test_cnt);
	for (int i = 0; i < test_cnt; ++i)
	{
		scanf("%d %d %d", &height, &width, &order);
		printf("%d%.2d\n", (order % height) ? order % height : height, (order - 1) / height + 1);
	}
	return 0;
}
