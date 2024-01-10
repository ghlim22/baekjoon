#include <cstring>
#include <iostream>
#include <stack>
#include <utility>

#define MAX_SIZE 500
#define pii std::pair<int, int>

static int board[MAX_SIZE][MAX_SIZE];
static int visited[MAX_SIZE][MAX_SIZE];
static int dx[4] = {0, -1, 1, 0};
static int dy[4] = {1, 0, 0, -1};

static int n;
static int m;
static int ans;

void input();
void search(int dep, int sum, int r, int c);
void solve();

int main(void)
{
	std::cin >> n >> m;

	input();
	solve();

	return 0;
}

void input()
{
	int num;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> num;
			board[i][j] = num;
		}
	}
}

bool is_valid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m && !visited[r][c];
}

void search(int dep, int sum, int r, int c)
{
	int ny;
	int nx;

	if (dep == 3)
	{
		int tmp = sum + board[r][c];
		ans = tmp > ans ? tmp : ans;
		return;
	}

	if (dep == 1)
	{
		int tmp = sum + board[r][c];
		if (is_valid(r - 1, c) && is_valid(r + 1, c))
		{
			int tmp2 = board[r - 1][c] + board[r + 1][c];
			ans = tmp + tmp2 > ans ? tmp + tmp2 : ans;
		}
		if (is_valid(r - 1, c) && is_valid(r, c + 1))
		{
			int tmp2 = board[r - 1][c] + board[r][c + 1];
			ans = tmp + tmp2 > ans ? tmp + tmp2 : ans;
		}
		if (is_valid(r - 1, c) && is_valid(r, c - 1))
		{
			int tmp2 = board[r - 1][c] + board[r][c - 1];
			ans = tmp + tmp2 > ans ? tmp + tmp2 : ans;
		}
		if (is_valid(r, c - 1) && is_valid(r + 1, c))
		{
			int tmp2 = board[r][c - 1] + board[r + 1][c];
			ans = tmp + tmp2 > ans ? tmp + tmp2 : ans;
		}
		if (is_valid(r, c + 1) && is_valid(r + 1, c))
		{
			int tmp2 = board[r][c + 1] + board[r + 1][c];
			ans = tmp + tmp2 > ans ? tmp + tmp2 : ans;
		}
		if (is_valid(r, c - 1) && is_valid(r, c + 1))
		{
			int tmp2 = board[r][c - 1] + board[r][c + 1];
			ans = tmp + tmp2 > ans ? tmp + tmp2 : ans;
		}
	}

	visited[r][c] = 1;
	for (int i = 0; i < 4; ++i)
	{
		ny = r + dy[i];
		nx = c + dx[i];

		if (is_valid(ny, nx))
		{
			search(dep + 1, sum + board[r][c], ny, nx);
		}
	}
	visited[r][c] = 0;
}

void solve()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			search(0, 0, i, j);
		}
	}

	std::cout << ans << "\n";
}
