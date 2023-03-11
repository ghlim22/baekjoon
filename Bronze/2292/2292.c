#include <stdio.h>

int main(void)
{
	int cnt;
	int n;
	int incre;
	int num;

	cnt = 1;
	incre = 6;
	scanf("%d", &n);
	num = 1;
	while (num < n)
	{
		num += incre;
		incre += 6;
		cnt++;
	}
	printf("%d", cnt);
	return (0);
}
