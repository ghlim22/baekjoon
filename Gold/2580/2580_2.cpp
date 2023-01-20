// https://www.acmicpc.net/problem/2580_2
// 2580_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ROW (9)
#define COL (9)
#define TOTAL (81)

using namespace std;

static int board[ROW][COL];

static bool check_row(int idx, int cur)
{
	int row = idx / 9;
	for (int i = 0; i < COL; ++i)
	{
		if (board[row][i] == cur)
		{
			return (false);
		}
	}
	return (true);
}

static bool check_col(int idx, int cur)
{
	int col = idx % 9;
	for (int i = 0; i < ROW; ++i)
	{
		if (board[i][col] == cur)
		{
			return (false);
		}
	}
	return (true);
}

static bool check_box(int idx, int cur)
{
	int row = idx / 9;
	int col = idx % 9;
	int start_row;
	int end_row;
	int start_col;
	int end_col;

	if (row < 3)
	{
		start_row = 0;
		end_row = 3;
	}
	else if (row < 6)
	{
		start_row = 3;
		end_row = 6;
	}
	else
	{
		start_row = 6;
		end_row = 9;
	}

	if (col < 3)
	{
		start_col = 0;
		end_col = 3;
	}
	else if (col < 6)
	{
		start_col = 3;
		end_col = 6;
	}
	else
	{
		start_col = 6;
		end_col = 9;
	}

	for (int i = start_row; i < end_row; ++i)
	{
		for (int j = start_col; j < end_col; ++j)
		{
			if (board[i][j] == cur)
			{
				return (false);
			}
		}
	}
	return (true);
}

void solve(int idx) 
{
	if (idx == TOTAL)
	{
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COL; ++j)
			{
				cout << board[i][j];
				if (j == 8 && i < 8)
					cout << '\n';
				else if (j < 8)
					cout << ' ';
			}
		}
		exit(0);
	}
	if (board[idx / 9][idx % 9])
	{
		solve(idx + 1);
	}
	else
	{
		for (int i = 1; i <= 9; ++i)
		{
			if (check_row(idx, i) && check_col(idx, i) && check_box(idx, i))
			{
				board[idx / 9][idx % 9] = i;
				solve(idx + 1);
			}
		}
		board[idx / 9][idx % 9] = 0;
	}
}

signed main() 
{
	fastio;
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			cin >> board[i][j];	
		}
	}
	solve(0);
	return (0);
}