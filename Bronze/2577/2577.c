#include <stdio.h>

int main(void)
{
	int a, b, c, mul;
	int cnt[10] = {0, };

	mul = 0;
	scanf("%d %d %d", &a, &b, &c);
	mul = a * b * c;
	while (mul > 0)
	{
		cnt[mul % 10]++;
		mul /= 10;
	}
	for (int i = 0; i < 10; ++i)
		printf("%d\n", cnt[i]);
	return (0);
}
