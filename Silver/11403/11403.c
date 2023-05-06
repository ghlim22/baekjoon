#include <stdio.h>
#include <string.h>
#define MAX_SIZE (100)

static int input_arr[MAX_SIZE][MAX_SIZE];
static int visited[MAX_SIZE];
static int n;

static void get_input(void);
static void solve(void);
static int find_route(int start, int dest, int depth);

int main(void)
{
	get_input();
	solve();
	return (0);
}

static void get_input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%1d", &input_arr[i][j]);
		}
	}
}

static void solve(void)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{	
			memset(visited, 0x00, sizeof(int) * MAX_SIZE);
			if (find_route(i, j, 0))
				printf("1");
			else
				printf("0");
			if (j < n - 1)
				printf(" ");
		}
		printf("\n");
	}
}

static int find_route(int start, int dest, int depth)
{
	if (depth > n)
		return (0);
	if (depth > 0 && start == dest)
		return (1);
	for (int i = 0; i < n; ++i)
	{
		if (input_arr[start][i] && !visited[i])
		{
			visited[i] = 1;
			if (i == dest)
				return (1);
			if (find_route(i, dest, depth + 1))
				return (1);
			visited[i] = 0;
		}
	}
	return (0);	 
}