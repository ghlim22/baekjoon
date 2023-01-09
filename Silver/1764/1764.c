#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool b_search(char **arr, char *key, int start, int end)
{
	int left = start;
	int right = end;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int res = strcmp(key, arr[mid]);
		if (res == 0)
			return (true);
		else if (res < 0)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (false);
}

int my_cmp(const void *a, const void *b)
{
	int res = strcmp(*(char **)a, *(char **)b);
	if (res < 0)
		return (-1);
	if (res == 0)
		return (0);
	return (1);
}

int main(void)
{
	int N, M;
	int cnt = 0;
	char tmp[21];

	scanf("%d %d", &N, &M);

	char **unheard = (char **)calloc(N, sizeof(char *));
	char **both = (char **)calloc(N, sizeof(char *));
	for (int i = 0; i < N; ++i)
	{
		unheard[i] = calloc(21, sizeof(char));
	}

	for (int i = 0; i < N; ++i)
		scanf(" %s", unheard[i]);
	qsort(unheard, N, sizeof(char *), my_cmp);

	for (int i = 0; i < M; ++i)
	{
		scanf(" %s", tmp);
		if (b_search(unheard, tmp, 0, N - 1))
		{
			both[cnt] = calloc(21, sizeof(char));
			strcpy(both[cnt++], tmp);
		}
	}
	
	// print answer.
	printf("%d\n", cnt);
	if (cnt)
	{
		qsort(both, cnt, sizeof(char *), my_cmp);
		for (int i = 0; i < cnt; ++i)
			printf("%s\n", both[i]);
	}

	// free.
	for (int i = 0; i < N; ++i)
	{
		free(unheard[i]);
	}
	for (int i = 0; i < cnt; ++i)
	{
		free(both[i]);
	}
	free(unheard);
	free(both);

	return (0);
}
