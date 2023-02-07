// https://www.acmicpc.net/problem/2606
// 2606번 

#include <iostream>
#include <algorithm>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static bool graph[100][100];
static bool visited[100];
static int ans;

void solve(int computer_cnt) 
{
	queue<int> bfs_queue;

	bfs_queue.push(0);
	visited[0] = true;
	while (!bfs_queue.empty())
	{
		if (visited[bfs_queue.front()] == false)
		{
			visited[bfs_queue.front()] = true;
			ans++;
		}

		for (int i = 0; i < computer_cnt; ++i)
		{
			if (visited[i] == false && graph[bfs_queue.front()][i] == true)
			{
				bfs_queue.push(i);
			}
		}

		bfs_queue.pop();
	}
}

signed main() {
	fastio;

	int computer_cnt = 0;
	int pair_cnt = 0;

	cin >> computer_cnt >> pair_cnt;
	for (int i = 0; i < pair_cnt; ++i)
	{
		int a, b;

		cin >> a >> b;
		graph[a - 1][b - 1] = true;
		graph[b - 1][a - 1] = true;
	}
	solve(computer_cnt);
	cout << ans;

	return (0);
}
