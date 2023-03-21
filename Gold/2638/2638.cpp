// https://www.acmicpc.net/problem/2638
// 2638번 

#include <iostream>
#include <stack>
#include <string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define pii pair<int, int>
#define MAX_SIZE (100)

using namespace std;

static int board[MAX_SIZE][MAX_SIZE];
static int height;
static int width;
static int cheese_cnt;
static int air_cnt;
static int ans;


static void get_input(void)
{
	cin >> height >> width;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cin >> board[i][j];
			if (board[i][j])
				cheese_cnt++;
			else
				air_cnt++;
		}
	}
}

static void check_air(int row_idx, int col_idx, bool visited[][MAX_SIZE], int *vis_cnt, bool air[][MAX_SIZE])
{
	stack< pii > dfs_stk;
	stack< pii > vis_stk;
	bool is_external = true;

	visited[row_idx][col_idx] = true;
	dfs_stk.push(make_pair(row_idx, col_idx));
	vis_stk.push(make_pair(row_idx, col_idx));
	while (!dfs_stk.empty())
	{
		int row = dfs_stk.top().first;
		int col = dfs_stk.top().second;
		dfs_stk.pop();
		++*vis_cnt;
		if (row == 0 || row == height - 1 || col == 0 || col == width - 1)
			is_external = false;
		if (row > 0 && !visited[row - 1][col] && !board[row - 1][col])
		{
			visited[row - 1][col] = true;
			dfs_stk.push(make_pair(row - 1, col));
			vis_stk.push(make_pair(row - 1, col));
		}
		if (row < height - 1 && !visited[row + 1][col] && !board[row + 1][col])
		{
			visited[row + 1][col] = true;
			dfs_stk.push(make_pair(row + 1, col));
			vis_stk.push(make_pair(row + 1, col));
		}
		if (col > 0 && !visited[row][col - 1] && !board[row][col - 1])
		{
			visited[row][col - 1] = true;
			dfs_stk.push(make_pair(row, col - 1));
			vis_stk.push(make_pair(row, col - 1));
		}
		if (col < width - 1 && !visited[row][col + 1] && !board[row][col + 1])
		{
			visited[row][col + 1] = true;
			dfs_stk.push(make_pair(row, col + 1));
			vis_stk.push(make_pair(row, col + 1));
		}
	}
	if (is_external)
	{
		while (!vis_stk.empty())
		{
			air[vis_stk.top().first][vis_stk.top().second] = true;
			vis_stk.pop();
		}
	}
}

static void spoil_cheese(bool is_internal[][MAX_SIZE])
{
	stack< pii > spoiled_cheeses;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			int contact_air_cnt = 0;
			if (board[i][j])
			{
				if (!board[i - 1][j] && !is_internal[i - 1][j])
					contact_air_cnt++;
				if (!board[i + 1][j] && !is_internal[i + 1][j])
					contact_air_cnt++;
				if (!board[i][j - 1] && !is_internal[i][j - 1])
					contact_air_cnt++;
				if (!board[i][j + 1] && !is_internal[i][j + 1])
					contact_air_cnt++;
				if (contact_air_cnt >= 2)
					spoiled_cheeses.push(make_pair(i, j));
			}
		}
	}
	while (!spoiled_cheeses.empty())
	{
		int i = spoiled_cheeses.top().first;
		int j = spoiled_cheeses.top().second;

		board[i][j] = 0;
		spoiled_cheeses.pop();
		cheese_cnt--;
		air_cnt++;
	}
}

static void solve(void) 
{
	get_input();
	while (cheese_cnt > 0)
	{
		bool visited[MAX_SIZE][MAX_SIZE];
		bool is_internal[MAX_SIZE][MAX_SIZE];
		int vis_cnt = 0;

		memset(visited, 0, sizeof(visited));
		memset(is_internal, 0, sizeof(is_internal));
		for (int i = 0; i < height && vis_cnt < air_cnt; ++i)
		{
			for (int j = 0; j < width && vis_cnt < air_cnt; ++j)
			{
				if (!board[i][j] && !visited[i][j])
				{
					check_air(i, j, visited, &vis_cnt, is_internal);
				}
			}
		}
		spoil_cheese(is_internal);
		ans++;
	}
	cout << ans;
}

signed main() 
{
	fastio;
	solve();
	return (0);
}