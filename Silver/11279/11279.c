#include <stdio.h>
#define MAX_SIZE (100000)

static int arr[MAX_SIZE + 1];
static int element_cnt;

static void	insert(int key)
{
	int	cur_idx;
	int	parent_idx;
	int	tmp;

	element_cnt++;
	cur_idx = element_cnt;
	arr[cur_idx] = key;
	while (cur_idx > 1)
	{
		parent_idx = cur_idx / 2;
		if (arr[parent_idx] < arr[cur_idx])
		{
			tmp = arr[parent_idx];
			arr[parent_idx] = arr[cur_idx];
			arr[cur_idx] = tmp;
		}
		cur_idx = parent_idx;
	}
}

static int	extract(void)
{
	int	max;
	int	cur_idx;
	int	child_idx;
	int	left_key;
	int	right_key;
	int	tmp;

	if (element_cnt == 0)
		return (0);
	max = arr[1];
	arr[1] = arr[element_cnt];
	arr[element_cnt] = 0;
	element_cnt--;
	cur_idx = 1;
	while (cur_idx < element_cnt)
	{
		child_idx = 0;
		left_key = arr[cur_idx * 2];
		right_key = arr[cur_idx * 2 + 1];
		if (left_key >= right_key && arr[cur_idx] < left_key)
			child_idx = cur_idx * 2;
		else if (right_key > arr[cur_idx])
			child_idx = cur_idx * 2 + 1;
		if (child_idx > element_cnt || child_idx == 0)
			break ;
		tmp = arr[cur_idx];
		arr[cur_idx] = arr[child_idx];
		arr[child_idx] = tmp;
		cur_idx = child_idx;
	}
	return (max);
}

int main(void)
{
	int	op_cnt;
	int	input;

	scanf("%d", &op_cnt);
	while (op_cnt--)
	{
		scanf("%d", &input);
		if (!input)
		{
			printf("%d\n", extract());
		}
		else
		{
			insert(input);
		}
	}
	return (0);
}
