#include <stdio.h>

int main(void)
{
	int x, y, w, h;
	int x_min = 0;
	int y_min = 0;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	if (w - x < 0 || h - y == 0)
		x_min = x;
	else
		x_min = (x <= w - x) ? x : w - x;
	
	if (h - y < 0 || h - y == 0)
		y_min = y;
	else
		y_min = (y <= h - y) ? y : h - y;
	printf("%d", x_min <= y_min ? x_min : y_min);
	
	return 0;
}