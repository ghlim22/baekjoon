#include <stdio.h>
#include <stdlib.h>

int arr[500000];
int cnt[8001];
int N;

int compare(const void *first, const void *second)
{
	int a;
	int b;

	a = *(int *)first;
	b = *(int *)second;
	if (a > b)
		return (1);
	else if (a == b)
		return (0);
	return (-1);
}

int get_mean(int *arr, int size)
{
	double res;

	res = 0.0;
	for (int i = 0; i < size; ++i)
		res += arr[i];
	res /= size;
	return ((res == 0.0 || res > 0.0) ? (int)(res + 0.5) : (int)(res - 0.5));
}

int get_median(int *arr, int size)
{
	if (size % 2 == 0)
		return ((arr[size / 2] + arr[size / 2 - 1]) / 2);
	return (arr[size / 2]);
}

int get_mode(void)
{
	int mode;
	int max_seq;
	int j;

	max_seq = 1;
	for (int i = 0; i - 4000 <= arr[N - 1]; ++i)
	{
		if (cnt[i] == max_seq || cnt[i] > max_seq)
		{
			max_seq = cnt[i];
		}
	}

	j = 0;
	for (int i = 0; i - 4000 <= arr[N - 1]; ++i)
	{
		if (cnt[i] ==  max_seq)
		{
			mode = i;
			j++;
			if (j == 2)
				break;
		}
	}

	return (mode - 4000);
}

int get_range(int *arr, int size)
{
	return (arr[size - 1] - arr[0]);
}

int main(void)
{
	int mean;
	int median;
	int mode;
	int range;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
		cnt[arr[i] + 4000]++;
	}
		
	qsort(arr, N, sizeof(int), compare);
	mean = get_mean(arr, N);
	median = get_median(arr, N);
	mode = get_mode();
	range = get_range(arr, N);
	printf("%d\n%d\n%d\n%d", mean, median, mode, range);
	return (0);
}