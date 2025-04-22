#include <stdio.h>
#include <string.h>

int a[100000];
int b[100000];
int c[100000];

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%1d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%1d", &c[i]);
	}

	int cnt = 0;
	memmove(b, a, sizeof(int) * n);
	/* don't switch 1 */
	for (int i = 1; i < n; ++i)
	{
		if (b[i - 1] != c[i - 1])
		{
			cnt++;
			b[i - 1] ^= 1;
			b[i] ^= 1;
			if (i < n - 1)
				b[i + 1] ^= 1;
		}
	}

	if (b[n - 1] == c[n - 1])
	{
		printf("%d\n", cnt);
		return 0;
	}

	/* switch 1 */
	memmove(b, a, sizeof(int) * n);
	cnt = 1;
	b[0] ^= 1;
	b[1] ^= 1;
	for (int i = 1; i < n; ++i)
	{
		if (b[i - 1] != c[i - 1])
		{
			cnt++;
			b[i - 1] ^= 1;
			b[i] ^= 1;
			if (i < n - 1)
				b[i + 1] ^= 1;
		}
	}

	if (b[n - 1] == c[n - 1])
	{
		printf("%d\n", cnt);
		return 0;
	}

	printf("-1");

	return 0;
}