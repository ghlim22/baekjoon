#include <stdio.h>
#include <stdlib.h>

int	compare(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a == *(int*)b)
		return 0;
	return -1;
}

int b_search(int *arr, int key, int arr_size)
{
	int left = 0;
	int right = arr_size - 1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == key)
			return 1;
		else if (key < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}

int main(void)
{
	int N, M;

	scanf("%d", &N);

	int inputs[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &inputs[i]);
	}
	qsort(inputs, N, sizeof(int), compare);
	
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int key;
		scanf("%d", &key);
		int res = b_search(inputs, key, N);
		printf("%d\n", res);
	}

	return 0;
}