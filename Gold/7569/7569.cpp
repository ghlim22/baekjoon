// <https://www.acmicpc.net/problem/7569>
// 7569번 

#include <iostream>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int boxes[100][100][100];
static int length, width, height;

struct	s_tomato
{
	int i;
	int	j;
	int	k;
};

signed main()
{
	fastio;

	int day = 0;
	bool bfs_done = false;
	int zero_cnt = 0;
	queue <struct s_tomato> tq;

	cin >> length >> width >> height;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			for (int k = 0; k < length; ++k)
			{
				cin >> boxes[i][j][k];
				if (boxes[i][j][k] == 1)
				{
					struct s_tomato tmp = {i, j, k};
					tq.push(tmp);
				}
				if (boxes[i][j][k] == 0)
					zero_cnt++;
			}
		}
	}

	do
	{
		int cnt = tq.size();
		bfs_done = false;
		while (cnt--)
		{
			struct s_tomato cur = tq.front();

			if (cur.i > 0 && boxes[cur.i - 1][cur.j][cur.k] == 0)
			{
				boxes[cur.i - 1][cur.j][cur.k] = 1;
				struct s_tomato tmp = {cur.i - 1, cur.j, cur.k};
				tq.push(tmp);
				zero_cnt--;
				bfs_done = true;
			}
				
			if (cur.i < height - 1 && boxes[cur.i + 1][cur.j][cur.k] == 0)
			{
				boxes[cur.i + 1][cur.j][cur.k] = 1;
				struct s_tomato tmp = {cur.i + 1, cur.j, cur.k};
				tq.push(tmp);
				zero_cnt--;
				bfs_done = true;
			}
				
			if (cur.j > 0 && boxes[cur.i][cur.j - 1][cur.k] == 0)
			{
				boxes[cur.i][cur.j - 1][cur.k] = 1;
				struct s_tomato tmp = {cur.i, cur.j - 1, cur.k};
				tq.push(tmp);
				zero_cnt--;
				bfs_done = true;
			}
				
			if (cur.j < width - 1 && boxes[cur.i][cur.j + 1][cur.k] == 0)
			{
				boxes[cur.i][cur.j + 1][cur.k] = 1;
				struct s_tomato tmp = {cur.i, cur.j + 1, cur.k};
				tq.push(tmp);
				zero_cnt--;
				bfs_done = true;
			}
				
			if (cur.k > 0 && boxes[cur.i][cur.j][cur.k - 1] == 0)
			{
				boxes[cur.i][cur.j][cur.k - 1] = 1;
				struct s_tomato tmp = {cur.i, cur.j, cur.k - 1};
				tq.push(tmp);
				zero_cnt--;
				bfs_done = true;
			}
				
			if (cur.k < length - 1 && boxes[cur.i][cur.j][cur.k + 1] == 0)
			{
				boxes[cur.i][cur.j][cur.k + 1] = 1;
				struct s_tomato tmp = {cur.i, cur.j, cur.k + 1};
				tq.push(tmp);
				zero_cnt--;
				bfs_done = true;
			}
				
			tq.pop();
		}
		if (bfs_done)
			day++;
	} while (bfs_done);

	if (zero_cnt == 0)
		cout << day;
	else
		cout << -1;
	return (0);
}