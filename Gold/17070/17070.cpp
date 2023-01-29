// https://www.acmicpc.net/problem/17070
// 17070번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX (16)

using namespace std;

static int mapsize;
static int ans;
static int map[MAX][MAX];

typedef enum
{
	HORIZONTAL, VERTICAL, DIAGONAL
} t_status;

void solve(int cur_row, int cur_col, t_status cur_status) 
{
	if (cur_row == mapsize - 1 && cur_col == mapsize - 1)
	{
		ans++;
		return;
	}

	switch (cur_status)
	{
	case HORIZONTAL:
		if (cur_col < mapsize - 1 && map[cur_row][cur_col + 1] == 0)
			solve(cur_row, cur_col + 1, HORIZONTAL);
		if (cur_row < mapsize - 1 && cur_col < mapsize - 1 && map[cur_row][cur_col + 1] == 0 && \
		map[cur_row + 1][cur_col] == 0 && map[cur_row + 1][cur_col + 1] == 0)
			solve(cur_row + 1, cur_col + 1, DIAGONAL);
		break;
	case VERTICAL:
		if (cur_row < mapsize - 1 && map[cur_row + 1][cur_col] == 0)
			solve(cur_row + 1, cur_col, VERTICAL);
		if (cur_row < mapsize - 1 && cur_col < mapsize - 1 && map[cur_row][cur_col + 1] == 0 && \
		map[cur_row + 1][cur_col] == 0 && map[cur_row + 1][cur_col + 1] == 0)
			solve(cur_row + 1, cur_col + 1, DIAGONAL);
		break;
	case DIAGONAL: 
		if (cur_row < mapsize - 1 && cur_col < mapsize - 1 && map[cur_row][cur_col + 1] == 0 && \
		map[cur_row + 1][cur_col] == 0 && map[cur_row + 1][cur_col + 1] == 0)
			solve(cur_row + 1, cur_col + 1, DIAGONAL);
		if (cur_col < mapsize - 1 && map[cur_row][cur_col + 1] == 0)
			solve(cur_row, cur_col + 1, HORIZONTAL);
		if (cur_row < mapsize - 1 && map[cur_row + 1][cur_col] == 0)
			solve(cur_row + 1, cur_col, VERTICAL);
	default:
		break;
	}
}

signed main() {
	fastio;

	cin >> mapsize;
	for (int i = 0; i < mapsize; ++i)
	{
		for (int j = 0; j < mapsize; ++j)
		{
			cin >> map[i][j];
		}
	}

	solve(0, 1, HORIZONTAL);
	cout << ans;

	return (0);
}