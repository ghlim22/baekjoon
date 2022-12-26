#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static int compare(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

static bool is_right_triangle(int a, int b, int c)
{
	return (c * c == b * b + a * a);
}

int main(void)
{
	int nums[3];

	while (true)
	{
		scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
		if (!nums[0])
			break;
		qsort(nums, 3, sizeof(int), compare);
		if (is_right_triangle(nums[0], nums[1], nums[2]))
			printf("right\n");
		else
			printf("wrong\n");
	}	

	return 0;
}