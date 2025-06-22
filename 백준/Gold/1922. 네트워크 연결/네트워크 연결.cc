#include <iostream>
#include <queue>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> graph[1001];
bool tree[1001];

typedef std::pair<int, std::pair<int, int>> edge;

int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if (a!=b) {
			graph[a].push_back({b, c});
			graph[b].push_back({a, c});
		}
	}

	tree[1] = true;
	std::priority_queue<edge> pq;
	for (const auto &e : graph[1]) {
		pq.push({-e.second, {1, e.first}});
	}

	int cost = 0;
	int treeSize = 1;
	while (treeSize < n) {
		edge e = pq.top();
		pq.pop();

		int weight = -e.first;
		int u = e.second.first;
		int v = e.second.second;
		if (tree[v]) {
			continue;
		}

		cost += weight;
		tree[v] = true;
		treeSize += 1;
		for (const auto &e : graph[v]) {
			int adj = e.first;
			int weight = e.second;
			if (tree[adj]) {
				continue;
			}
			pq.push({-weight, {v, adj}});
		}
	}

	std::cout << cost << std::endl;
	
	return 0;
}