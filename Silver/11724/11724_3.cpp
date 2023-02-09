// <https://www.acmicpc.net/problem/11724_3>
// 11724_3번 

#include <iostream>
#include <vector>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

static vector< vector<int> > graph_list;
static vector<bool> visited;

static void dfs(int start)
{
	stack<int> dfs_stk;
	dfs_stk.push(start);

	while (dfs_stk.empty() == false)
	{
		int tmp = dfs_stk.top();
		dfs_stk.pop();
		if (visited[tmp] == true)
			continue;
		visited[tmp] = true;
		for (int i : graph_list[tmp])
		{
			if (visited[i] == false)
				dfs_stk.push(i);
		}
	}
}

signed main() {
	fastio;

	int vertex_cnt = 0;
	int edge_cnt = 0;
	int ans = 0;

	cin >> vertex_cnt >> edge_cnt;
	graph_list.resize(vertex_cnt + 1);
	visited.resize(vertex_cnt + 1);

	for (int i = 0; i < edge_cnt; ++i)
	{
		int x, y;

		cin >> x >> y;
		graph_list[x].push_back(y);
		graph_list[y].push_back(x);
	}

	for (int i = 1; i <= vertex_cnt; ++i)
	{
		if (visited[i] == false)
		{
			dfs(i);
			ans++;
		}
	}

	cout << ans;

	return (0);
}