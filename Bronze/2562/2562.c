#include <stdio.h>

#define MAX (9)

static int numbers[MAX];

int main(void)
{
	int max = 0;
	int max_idx = 0;
	for (int i = 0; i < MAX; ++i)
	{
		scanf("%d", &numbers[i]);
		if (numbers[i] > max)
		{
			max = numbers[i];
			max_idx = i;
		}
	}
	printf("%d\n%d", max, max_idx + 1);

	return 0;
}