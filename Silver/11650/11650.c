#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} point;

static int compare_point(const void *a, const void *b)
{
	point *first = (point *)a;
	point *second = (point *)b;

	if (first->x == second->x)
	{
		if (first->y > second->y)
			return 1;
		else if (first->y == second->y)
			return 0;
		else
			return -1;
	}
	else
	{
		if (first->x > second->x)
			return 1;
		else if (first->x == second->x)
			return 0;
		else
			return -1;
	}
}

int main(void)
{
	int point_cnt;
	point *arr;

	scanf("%d", &point_cnt);
	arr = (point *)malloc(sizeof(point) * point_cnt);
	for (int i = 0; i < point_cnt; ++i)
	{
		scanf("%d %d", &(arr[i].x), &(arr[i].y));
	}
	qsort(arr, point_cnt, sizeof(point), compare_point);
	for (int i = 0; i < point_cnt; ++i)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}
