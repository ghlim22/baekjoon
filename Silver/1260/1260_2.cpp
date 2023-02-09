// <https://www.acmicpc.net/problem/1260_2>
// 1260_2번 

#include <iostream>
#include <stack>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX_NODE (1000)
using namespace std;

static int node_cnt = 0;
static int edge_cnt = 0;
static bool graph[MAX_NODE + 1][MAX_NODE + 1];
static bool dfs_visited[MAX_NODE + 1];

static void dfs(int start)
{
	dfs_visited[start] = true;
	cout << start << ' ';
	for (int i = 1; i <= node_cnt; ++i)
	{
		if (graph[start][i] == true && dfs_visited[i] == false)
		{
			dfs_visited[i] = true;
			dfs(i);
		}
	}
}

static void bfs(int start)
{
	queue<int> graph_que;
	bool visited[MAX_NODE + 1] = {false, };

	graph_que.push(start);
	visited[start] = true;
	cout << start;

	while (!graph_que.empty())
	{
		int cur_node = graph_que.front();

		for (int i = 1; i <= node_cnt; ++i)
		{
			if (visited[i] == false && graph[cur_node][i] == true)
			{
				graph_que.push(i);
				visited[i] = true;
				cout << ' ' << i;
			}
		}
		if (!graph_que.empty())
			graph_que.pop();
	}
}

static void dfs_stack(int start)
{
	bool visited[MAX_NODE + 1] = {false, };
	stack<int> stk;

	stk.push(start);

	while (stk.size() > 0)
	{
		int tmp = stk.top();
		stk.pop();
		if (visited[tmp] == true)
			continue;
		cout << tmp << ' ';
		visited[tmp] = true;
		for (int i = MAX_NODE; i >= 0; --i)
		{
			if (graph[tmp][i] == true && visited[i] == false)
				stk.push(i);
		}
	}
}

signed main() {
	fastio;
	int start = 0;

	cin >> node_cnt >> edge_cnt >> start;
	for (int i = 0; i < edge_cnt; ++i)
	{
		int a, b;

		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	dfs_stack(start);
	cout << '\n';
	bfs(start);

	return (0);
}