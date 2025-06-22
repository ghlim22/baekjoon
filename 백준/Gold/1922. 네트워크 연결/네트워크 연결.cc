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
			graph[a].push_back({-c, b}); /* cost, to */
			graph[b].push_back({-c, a});
		}
	}

	tree[1] = true;
	std::priority_queue<std::pair<int, int>> pq; /* cost, to */
	for (const auto &e : graph[1]) {
		pq.push(e);
	}

	int cost = 0;
	int treeSize = 1;
	while (treeSize < n) {
		auto e = pq.top();
		pq.pop();

		int weight = -e.first;
		int v = e.second;
		if (tree[v]) {
			continue;
		}

		cost += weight;
		tree[v] = true;
		treeSize += 1;

		for (const auto &e : graph[v]) {
			if (tree[e.second]) {
				continue;
			}
			pq.push(e);
		}
	}

	std::cout << cost << std::endl;
	
	return 0;
}