// <https://www.acmicpc.net/problem/24444>
// 24444번 

#include <iostream>
#include <queue>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static vector< vector<int> > graph_list;
static vector<int> dist;
static vector<int> visited;

int cnt = 1;

static void bfs(int start)
{
	queue<int> bfs_que;

	bfs_que.push(start);
	dist[start] = cnt;
	while (bfs_que.size() > 0)
	{
		int tmp = bfs_que.front();
		bfs_que.pop();
		if (visited[tmp] == true)
			continue;
		visited[tmp] = true;
		dist[tmp] = (cnt++);
		for (int i : graph_list[tmp])
		{
			if (!visited[i])
			{
				bfs_que.push(i);
			}
		}
	}
}

signed main() {
	fastio;
	int vertex_cnt = 0;
	int edge_cnt = 0;
	int start_num = 0;

	cin >> vertex_cnt >> edge_cnt >> start_num;
	graph_list.resize(vertex_cnt + 1);
	visited.resize(vertex_cnt + 1);
	dist.resize(vertex_cnt + 1);

	for (int i = 0; i < edge_cnt; ++i)
	{
		int x, y;
		
		cin >> x >> y;
		graph_list[x].push_back(y);
		graph_list[y].push_back(x);
	}

	for (int i = 1; i <= vertex_cnt; ++i)
		sort(graph_list[i].begin(), graph_list[i].end());

	bfs(start_num);
	
	for (int i = 1; i <= vertex_cnt; ++i)
		cout << dist[i] << '\n';

	return (0);
}