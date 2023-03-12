#include <stdio.h>

int main(void)
{
	int tree_height;
	int	up_meter;
	int down_meter;
	int day;

	scanf("%d %d %d", &up_meter, &down_meter, &tree_height);	
	day = (tree_height - down_meter - 1) / (up_meter - down_meter) + 1;
	printf("%d", day);
	return (0);
}