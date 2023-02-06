// https://www.acmicpc.net/problem/1992
// 1992번 

#include <iostream>
#define MAX_SIZE (64)

using namespace std;

static int video[MAX_SIZE][MAX_SIZE];

static bool is_same_color(int r, int c, int size)
{
	int ref = video[r][c];
	for (int i = r; i < r + size; ++i)
	{
		for (int j = c; j < c + size; ++j)
		{
			if (ref != video[i][j])
				return (false);
		}
	}
	return (true);
}

void solve(int r, int c, int size) 
{
	if (size == 1 || is_same_color(r, c, size))
	{
		cout << video[r][c];
	}
	else
	{
		cout << '(';
		solve(r, c, size / 2);
		solve(r, c + size / 2, size / 2);
		solve(r + size / 2, c, size / 2);
		solve(r + size / 2, c + size / 2, size / 2);
		cout << ')';
	}
}

signed main() 
{
	int size = 0;

	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			scanf("%1d", &video[i][j]);
		}
	}
	solve(0, 0, size);

	return (0);
}