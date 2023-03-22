#include <stdio.h>
#include <string.h>

static void swp(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int arr[101], n, m, i, j;

	memset(arr, 0, sizeof(arr));
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i)
		arr[i] = i;
	while (m--)
	{
		scanf("%d %d", &i, &j);
		swp(arr + i, arr + j);
	}
	for (i = 1; i <= n; ++i)
		printf("%d ", arr[i]);
	return (0);
}