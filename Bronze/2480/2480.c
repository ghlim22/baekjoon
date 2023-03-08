#include <stdio.h>

int main(void)
{
	int first;
	int	second;
	int	third;
	int reward;

	scanf("%d %d %d", &first, &second, &third);
	if ((first == second) && (second == third) && (first == second))
		reward = 10000 + first * 1000;
	else if ((first == second) || (first == third))
		reward = 1000 + first * 100;
	else if (second == third)
		reward = 1000 + third * 100;
	else if (first >= second && first >= third)
		reward = first * 100;
	else if (second >= first && second >= third)
		reward = second * 100;
	else
		reward = third * 100;
	printf("%d", reward);
	return (0);
}
