#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

static void swp(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

static int partition(char dict[][21], int order_arr[], int left, int right)
{
	int mid = (left + right) / 2;
	swp(&order_arr[left], &order_arr[mid]);
	int i = left;
	int j = right;
	int pivot = left;

	while (i < j)
	{
		while (i < j && strcmp(dict[order_arr[j]], dict[order_arr[pivot]]) > 0)
			j--;
		while (i < j && strcmp(dict[order_arr[i]], dict[order_arr[pivot]]) <= 0)
			i++;
		swp(&order_arr[i], &order_arr[j]);
	}
	swp(&order_arr[pivot], &order_arr[i]);
	return (i);
}

static void my_qsort(char dict[][21], int order_arr[], int left, int right)
{
	if (left >= right)
		return;
	int part = partition(dict, order_arr, left, right);
	my_qsort(dict, order_arr, left, part - 1);
	my_qsort(dict, order_arr, part + 1, right);
}

static int my_bsearch(char dict[][21], int order_arr[], int left, int right, char *key)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cmp_res = strncmp(key, dict[order_arr[mid]], 20);
		if (cmp_res == 0)
			return (mid);
		else if (cmp_res < 0)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (-1);
}

int main(void)
{
	int pocketmon_cnt;
	int quiz_cnt;
	static char pocketmon_dict[100000][21];
	static int order_arr[100000];

	scanf("%d %d", &pocketmon_cnt, &quiz_cnt);
	for (int i = 0; i < pocketmon_cnt; ++i)
	{
		scanf("%s", pocketmon_dict[i]);
		order_arr[i] = i;
	}
	my_qsort(pocketmon_dict, order_arr, 0, pocketmon_cnt - 1);
	/*
	for (int i = 0; i < pocketmon_cnt; ++i)
		printf("%s\n", pocketmon_dict[order_arr[i]]);
	printf("\n");
	*/

	for (int i = 0; i < quiz_cnt; ++i)
	{
		char tmp[22];
		char c;
		char *del_line_p;

		scanf(" %[^\n]", tmp);

		if (isdigit(tmp[0]))
		{
			int num = atoi(tmp);
			printf("%s\n", pocketmon_dict[num - 1]);
		}
		else
		{
			int idx = my_bsearch(pocketmon_dict, order_arr, 0, pocketmon_cnt - 1, tmp);
			printf("%d\n", order_arr[idx] + 1);
		}
	}
	return (0);
}