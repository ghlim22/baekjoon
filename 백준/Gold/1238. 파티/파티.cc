#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int find(int from, int to, int n, const vector<vector<pii>> &graph) {
	priority_queue<pii> pq; // {-cost, to}
	for (pii p : graph[from]) {
		pq.push({-p.second, p.first});
	}
	
	vector<bool> visited(n+1);
	visited[from] = true;
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		int curCost = cur.first; // negative
		int curNode = cur.second;
		if (curNode == to) {
			return -curCost;
		}
		if (visited[curNode]) {
			continue;
		}
		visited[curNode] = true;

		for (pii p : graph[curNode]) {
			if (visited[p.first]) 
				continue;
			pq.push({curCost-p.second, p.first});
		}
	}

	return -1;
}

int main() {
	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<pii>> graph(N + 1);
	for (int i = 0; i < M; ++i) {
		int from, to, cost;
		std::cin >> from >> to >> cost;
		graph[from].push_back({to, cost});
	}

	int maxCost = 0;
	for (int i = 1; i <= N; ++i) {
		int toParty = find(i, X, N, graph);
		int toHome = find(X, i, N, graph);
		maxCost = std::max(maxCost, toParty + toHome);
	}

	cout << maxCost << endl;

	return 0;
}