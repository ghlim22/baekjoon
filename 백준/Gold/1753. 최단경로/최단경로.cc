#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {

	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int edgeCount, nodeCount, start;
	std::cin >> nodeCount >> edgeCount >> start;

	std::vector<std::vector<pii>> graph(nodeCount + 1);
	for (int i = 0; i < edgeCount; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		graph[u].push_back({w, v});
	}

	const int INF = -1;
	vector<int> costs(nodeCount + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	costs[start] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (pii edge : graph[node]) {
			int ncost = cost + edge.first;
			int adj = edge.second;
			if (costs[adj] == INF || ncost < costs[adj]) {
				costs[adj] = ncost;
				pq.push({ncost, adj});
			}
		}
	}

	for (int i = 1; i <= nodeCount; ++i) {
		if (costs[i] == INF)
			cout << "INF";
		else
			cout << costs[i];
		cout << '\n';
	}

	return 0;
}