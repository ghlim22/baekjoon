// <https://www.acmicpc.net/problem/7576>
// 7576번 

#include <iostream>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define pii pair<int, int>

using namespace std;

static int height;
static int width;
static int box[1000][1000];

signed main()
{
	fastio;
	int				zero_cnt;
	int				days;
	int				today_tomato;
	bool			bfs_done;
	pii				cur;
	queue< pii >	tq;

	zero_cnt = 0;
	days = 0;
	bfs_done = false;
	cin >> width >> height;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cin >> box[i][j];
			if (!box[i][j])
				zero_cnt++;
			else if (box[i][j] == 1)
				tq.push(make_pair(i, j));
		}
	}
	do
	{
		bfs_done = false;
		today_tomato = tq.size();
		while (today_tomato--)
		{
			cur = tq.front();
			if (cur.first > 0 && !box[cur.first - 1][cur.second])
			{
				zero_cnt--;
				bfs_done = true;
				box[cur.first - 1][cur.second] = 1;
				tq.push(make_pair(cur.first - 1, cur.second));
			}
			if (cur.first < height - 1 && !box[cur.first + 1][cur.second])
			{
				zero_cnt--;
				bfs_done = true;
				box[cur.first + 1][cur.second] = 1;
				tq.push(make_pair(cur.first + 1, cur.second));
			}
			if (cur.second > 0 && !box[cur.first][cur.second - 1])
			{
				zero_cnt--;
				bfs_done = true;
				box[cur.first][cur.second - 1] = 1;
				tq.push(make_pair(cur.first, cur.second - 1));
			}
			if (cur.second < width - 1 && !box[cur.first][cur.second + 1])
			{
				zero_cnt--;
				bfs_done = true;
				box[cur.first][cur.second + 1] = 1;
				tq.push(make_pair(cur.first, cur.second + 1));
			}
			tq.pop();
		}
		if (bfs_done)
			days++;
	} while (bfs_done);
	if (zero_cnt > 0)
		cout << -1;
	else
		cout << days;
	return (0);
}
