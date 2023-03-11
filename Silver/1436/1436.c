#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int cnt;
	int	num;
	int tmp;

	cnt = 0;
	num = 666;
	tmp = num;
	scanf("%d", &n);
	while (cnt < n)
	{
		int tmp2 = tmp;
		while (tmp2 >= 666)
		{
			if (tmp2 % 1000 == 666)
			{
				cnt++;
				num = tmp;
				break;
			}
			tmp2 /= 10;
		}
		tmp++;
	}
	printf("%d", num);
	return (0);
}
