#include <stdio.h>

int main(void)
{
	int n = 0;
	int ans = 0;

	scanf("%d", &n);
	while (n--)
	{
		int tmp = 0;
		scanf("%1d", &tmp);
		if (tmp == 1)
			ans++;
	}
	printf("%d", ans);
	return (0);
}