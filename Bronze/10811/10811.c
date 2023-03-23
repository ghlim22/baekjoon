#include <stdio.h>

static void swap_element(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int arr[101], n, m, i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i)
		arr[i] = i;
	while (m--)
	{
		scanf("%d %d", &i, &j);
		while (i < j)
		{
			swap_element(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	for (i = 1; i <= n; ++i)
		printf("%d ", arr[i]);
	return (0);
}