#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int arr[5005];

int cmp(const void *a, const void *b)
{
	int *first = (int *)a;
	int *second = (int *)b;
	if (*first > *second)
		return 1;
	if (*first == *second)
		return 0;
	return -1;
}

static long long get_abs(long long n)
{
	return n < 0 ? -n : n;
}

int main(void)
{
	int N;
	long long ans = LLONG_MAX;
	int x = 0;
	int y = 0;
	int z = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), cmp);
	for (int i = 0; i < N; ++i)
	{
		int j = 0;
		int k = N - 1;
		while (j < i && i < k)
		{
			long long tmp = arr[j] + arr[i] + arr[k];
			if (get_abs(tmp) < get_abs(ans))
			{
				x = j;
				y = i;
				z = k;
				ans = tmp;
			}
			if (tmp < 0)
				j++;
			else if (tmp > 0)
				k--;
			else
			{
				printf("%d %d %d\n", arr[x], arr[y], arr[z]);
				return 0;
			}
		}
	}
	printf("%d %d %d\n", arr[x], arr[y], arr[z]);
	return 0;
}