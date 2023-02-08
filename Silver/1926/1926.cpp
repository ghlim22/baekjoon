// https://www.acmicpc.net/problem/1926
// 1926번 

#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX_SIZE (500)

using namespace std;

static int paper[MAX_SIZE][MAX_SIZE];
static int height;
static int width;
static int max_area;
static int painting_cnt;

static void dfs(int r, int c, int *area)
{
	++*area;
	paper[r][c] = 0;
	if (c < width - 1 && paper[r][c + 1] == 1)
		dfs(r, c + 1, area);
	if (r < height - 1 && paper[r + 1][c] == 1)
		dfs(r + 1, c, area);
	if (c > 0 && paper[r][c - 1] == 1)
		dfs(r, c - 1, area);
	if (r > 0 && paper[r - 1][c] == 1)
		dfs(r - 1, c, area);
}

signed main() {
	fastio;

	cin >> height >> width;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
			cin >> paper[i][j];
	}

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (paper[i][j] == 1)
			{
				painting_cnt++;
				int tmp_area = 0;
				dfs(i, j, &tmp_area);
				max_area = max(tmp_area, max_area);
			}
		}
	}

	cout << painting_cnt << '\n' << max_area;

	return (0);
}