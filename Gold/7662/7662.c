#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE (1000000)

static int	arr[MAX_SIZE + 1];
static int	min_arr[MAX_SIZE + 1];
static int	element_cnt;

static void	swap_element(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	maxheap_insert(int num)
{
	int	parent_idx;
	int	cur_idx;
	int	prev_last_idx;

	element_cnt++;
	cur_idx = element_cnt;
	arr[cur_idx] = num;
	while (cur_idx > 1)
	{
		parent_idx = cur_idx / 2;
		if (arr[parent_idx] < arr[cur_idx])
			swap_element(&arr[parent_idx], &arr[cur_idx]);
		else
			break ;
		cur_idx = parent_idx;
	}
}

static void	extract_min(void)
{
	if (element_cnt == 0)
		return ;
	if (element_cnt > 1 && arr[element_cnt - 1] < arr[element_cnt])
		swap_element(&arr[element_cnt - 1], &arr[element_cnt]);	
	arr[element_cnt--] = 0;
}

static void	maxheap_extract_max(void)
{
	int	l_child;
	int	r_child;
	int	next_idx;
	int	cur;

	if (element_cnt == 0)
		return ;
	arr[1] = arr[element_cnt--];
	cur = 1;
	while (cur < element_cnt)
	{
		l_child = cur * 2;
		r_child = cur * 2 + 1;
		if (l_child > element_cnt)
			break;
		if (r_child <= element_cnt)
		{
			if (arr[l_child] < arr[r_child])
				next_idx = r_child;
			else
				next_idx = l_child;
		}
		else if (l_child <= element_cnt && arr[l_child] > arr[cur])
		{
			next_idx = l_child;
		}
		else
			break;
		swap_element(&arr[cur], &arr[next_idx]);
		cur = next_idx;
	}
}

int main(void)
{
	int		test_cnt;
	int		op_cnt;
	int		input_num;
	char	op;

	scanf("%d", &test_cnt);
	while (test_cnt--)
	{
		scanf("%d", &op_cnt);
		memset(arr, 0, sizeof(int) * MAX_SIZE);
		element_cnt = 0;
		while (op_cnt--)
		{
			scanf(" %c %d", &op, &input_num);
			if (op == 'I')
				insert(input_num);
			else if (op == 'D')
			{
				if (input_num == 1)
					extract_max();
				else if (input_num == -1)
					extract_min();
				
			}
		}
		if (element_cnt == 0)
			printf("%s\n", "EMPTY");
		else
			printf("%d %d", arr[1], arr[element_cnt]); } return (0); }