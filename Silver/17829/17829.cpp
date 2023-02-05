// https://www.acmicpc.net/problem/17829
// 17829번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MIN_ELEMENT_VALUE (-10000)

using namespace std;

int get_second_biggest(int **matrix, int r, int c)
{
	int max = MIN_ELEMENT_VALUE;
	int second = MIN_ELEMENT_VALUE;

	for (int i = r; i < r + 2; ++i)
	{
		for (int j = c; j < c + 2; ++j)
		{
			if (matrix[i][j] > max)
			{
				second = max;
				max = matrix[i][j];
			}
			else if (matrix[i][j] > second)
			{
				second = matrix[i][j];
			}
		}
	}

	return (second);
}

int	**allocate_matrix(int size)
{
	int **matrix = (int **)malloc(sizeof(int *) * size);
	for (int i = 0; i < size; ++i)
		matrix[i] = (int *)malloc(sizeof(int) * size);
	
	return (matrix);
}

void	free_matrix(int ***matrix, int size)
{
	for (int i = 0; i < size; ++i)
		free((*matrix)[i]);
	free((*matrix));
	*matrix = NULL;
}

signed main() {
	fastio;

	int size = 0;

	cin >> size;

	int **matrix = allocate_matrix(size);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cin >> matrix[i][j];
	}

	while (size > 2)
	{
		int **next = allocate_matrix(size / 2);

		for (int i = 0; i < size / 2; ++i)
		{
			for (int j = 0; j < size / 2; ++j)
			{
				next[i][j] = get_second_biggest(matrix, i * 2, j * 2);
			}
		}

		free_matrix(&matrix, size);
		matrix = next;
		size >>= 1;
	}
	cout << get_second_biggest(matrix, 0, 0);
	free_matrix(&matrix, 2);

	return (0);
}