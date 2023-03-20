#include <stdio.h>

static int arr[101];

int main(void)
{
	int N, M, i, j, k;

	scanf("%d %d", &N, &M);
	while (M--)
	{
		scanf("%d %d %d", &i, &j, &k);
		while (i <= j)
		{
			arr[i] = k;
			++i;
		}
	}
	i = 1;
	while (i <= N)
	{
		printf("%d ", arr[i]);
		++i;
	}
	return (0);
}