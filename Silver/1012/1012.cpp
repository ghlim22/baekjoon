// https://www.acmicpc.net/problem/1012
// 1012번

#include <iostream>
#include <stack>
#include <string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define pii pair<int, int>
#define MAX_SIZE (50)

using namespace std;

static bool arr[MAX_SIZE][MAX_SIZE];
static bool visited[MAX_SIZE][MAX_SIZE];

static bool dfs(int start_x, int start_y, int width, int height)
{
	stack<pii> dfs_stack;

	if (visited[start_y][start_x])
		return (false);

	dfs_stack.push(make_pair(start_y, start_x));
	visited[start_y][start_x] = true;
	while (!dfs_stack.empty())
	{
		int cur_x, cur_y;

		cur_y = dfs_stack.top().first;
		cur_x = dfs_stack.top().second;
		dfs_stack.pop();
		if (cur_y > 0 && arr[cur_y - 1][cur_x] && !visited[cur_y - 1][cur_x])
		{
			visited[cur_y - 1][cur_x] = true;
			dfs_stack.push(make_pair(cur_y - 1, cur_x));
		}
		if (cur_y < height - 1 && arr[cur_y + 1][cur_x] && !visited[cur_y + 1][cur_x])
		{
			visited[cur_y + 1][cur_x] = true;
			dfs_stack.push(make_pair(cur_y + 1, cur_x));
		}
		if (cur_x > 0 && arr[cur_y][cur_x - 1] && !visited[cur_y][cur_x - 1])
		{
			visited[cur_y][cur_x - 1] = true;
			dfs_stack.push(make_pair(cur_y, cur_x - 1));
		}
		if (cur_x < width - 1 && arr[cur_y][cur_x + 1] && !visited[cur_y][cur_x + 1])
		{
			visited[cur_y][cur_x + 1] = true;
			dfs_stack.push(make_pair(cur_y, cur_x + 1));
		}
	}
	return (true);
}

signed main()
{
	fastio;
	int width, height, cabbage_cnt, ans, test_cnt;

	cin >> test_cnt;
	while (test_cnt--)
	{
		cin >> width >> height >> cabbage_cnt;
		memset(arr, 0x00, sizeof(arr[0][0]) * MAX_SIZE * MAX_SIZE);
		memset(visited, 0x00, sizeof(visited[0][0]) * MAX_SIZE * MAX_SIZE);
		while (cabbage_cnt--)
		{
			int x, y;

			cin >> x >> y;
			arr[y][x] = true;
		}
		ans = 0;
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (!visited[i][j] && arr[i][j])
				{
					if (dfs(j, i, width, height))
						ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return (0);
}