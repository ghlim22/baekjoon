// <https://www.acmicpc.net/problem/2630_2>
// 2630_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX (128)
#define BLUE (1)
#define WHITE (0)
using namespace std;

static int	board[MAX][MAX] = {0, };
static int	white_cnt = 0;
static int	blue_cnt = 0;

void solve(int x, int y, int size) 
{
	if (size == 1)
	{
		if (board[x][y] == BLUE)
			blue_cnt++;
		else
			white_cnt++;
		return ;
	}

	bool	is_same_color = true;
	char	ref_color = board[x][y];
	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (board[i][j] != ref_color){
				is_same_color = false;
				goto DIVIDE;		
			}
		}
	}

	if (is_same_color)
	{
		if (ref_color == BLUE)
			blue_cnt++;
		else
			white_cnt++;
		return ;
	}

	DIVIDE:
	solve(x, y, size / 2);
	solve(x, y + size / 2, size / 2);
	solve(x + size / 2, y, size / 2);
	solve(x + size / 2, y + size / 2, size / 2);
}

signed main() {
	fastio;

	int size = 0;

	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cin >> board[i][j];
		}
	}
	solve(0, 0, size);
	cout << white_cnt << '\n' << blue_cnt;

	return (0);
}