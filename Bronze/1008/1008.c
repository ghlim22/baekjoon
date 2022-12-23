#include <stdio.h>

int main(void)
{
	int a, b;
	double res;

	scanf("%d %d", &a, &b);
	res = (double)a / b;
	printf("%.12lf", res);

	return 0;
}