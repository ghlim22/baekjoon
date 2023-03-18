#include <stdio.h>
#define MAX_SIZE (1000000)

typedef struct s_element
{
	int	key;
}				t_element;

static void	swap_element(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	is_max_level(int node_idx)
{
	int	cnt;

	cnt = 0;	
	while (node_idx)
	{
		node_idx >>= 1;
		cnt++;
	}
	cnt--;
	return (cnt % 2);
}








int main(void)
{

}