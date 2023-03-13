#include <stdio.h>
#include <string.h>

typedef struct s_passwd
{
	char	addr[22];
	char	key[22];

}				t_passwd;

int			total_passwd;
int			tofind;
t_passwd	keys[100000];
int			order_arr[100000];

static void swp_order(int x, int y)
{
	int tmp = order_arr[x];
	order_arr[x] = order_arr[y];
	order_arr[y] = tmp;	
}

static int partition(int start, int end)
{
	int i = start;
	int j = end;
	int pivot = start;

	while (i < j)
	{
		while (j > start && strcmp(keys[order_arr[pivot]].addr, keys[order_arr[j]].addr) < 0)
			j--;
		while (i < j && strcmp(keys[order_arr[pivot]].addr, keys[order_arr[i]].addr) >= 0)
			i++;
		swp_order(i, j);
	}
	swp_order(pivot, i);
	return (i);
}

static void quicksort(int start, int end)
{
	if (start >= end)
		return ;
	int part = partition(start, end);
	quicksort(start, part - 1);
	quicksort(part + 1, end);
}

static int binary_search(int start, int end, char *key)
{
	int mid;
	int res;

	while (start <= end)
	{
		mid = (start + end) / 2;
		res = strcmp(keys[order_arr[mid]].addr, key);
		if (res == 0)
			return (mid);
		else if (res < 0)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (-1);
}

int main(void)
{
	char	tmp[21];
	int		idx;

	scanf("%d %d", &total_passwd, &tofind);
	for (int i = 0; i < total_passwd; ++i)
	{
		scanf(" %s %s", keys[i].addr, keys[i].key);	
		order_arr[i] = i;
	}
	quicksort(0, total_passwd - 1);
	for (int i = 0; i < tofind; ++i)
	{
		scanf(" %s", tmp);
		idx = binary_search(0, total_passwd - 1, tmp);
		printf("%s\n", keys[order_arr[idx]].key);
	}
	
	return (0);
}