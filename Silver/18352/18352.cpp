// <https://www.acmicpc.net/problem/18352>
// 18352번 

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static vector< vector<int> > list;
static vector<bool> visited;
static vector<int> ans;
static vector<int> distances;
static int city_cnt = 0;
static int road_cnt = 0;
static int dist = 0;
static int start_idx = 0;

static void bfs(int start)
{
	int bfs_dist = 0;
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int tmp = q.front();
		for (int i : list[tmp])
		{
			if (visited[i] == false)
			{
				distances[i] = distances[tmp] + 1;
				visited[i] = true;
				q.push(i);
				if (distances[i] == dist)
					ans.push_back(i);
			}
		}
		q.pop();
	}

	if (ans.empty())
		cout << -1;
	else
	{
		sort(ans.begin(), ans.end());
		for (int i : ans)
			cout << i << '\n';
	}
}

signed main() {
	fastio;

	cin >> city_cnt >> road_cnt >> dist >> start_idx;
	list.resize(city_cnt + 1);
	visited.resize(city_cnt + 1);
	distances.resize(city_cnt + 1);

	for (int i = 0; i < road_cnt; ++i)
	{
		int s, d;

		cin >> s >> d;
		list[s].push_back(d);
	}
	
	bfs(start_idx);

	return (0);
}