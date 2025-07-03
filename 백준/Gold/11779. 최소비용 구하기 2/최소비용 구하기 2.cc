#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#include <vector>

typedef std::pair<int, int> pii;

void solve(const std::vector<std::vector<pii>> &graph, int n, int src, int dst)
{
	const long long INF = 100000L * 100000 + 1;
	std::vector<long long> costs(n + 1, INF);
	std::vector<int> touch(n + 1);
	std::priority_queue<std::pair<long long, int>, 
						std::vector<std::pair<long long, int>>, 
						std::greater<std::pair<long long , int>>> pq; // (cost, vertex)

	// initialize
	costs[src] = 0;
	pq.push({0, src});
	
	// repeat
	while (!pq.empty()) {
		auto current = pq.top();
		pq.pop();

		long long cost = current.first;
		int vertex = current.second;

		if (vertex == dst) {
			break;
		}

		for (const auto &e : graph[vertex]) {
			long long nc = e.first + cost;
			if (costs[e.second] > nc) {
				costs[e.second] = nc;
				touch[e.second] = vertex;
				pq.push({nc, e.second}); // update the priority queue
			}
		}
	}

	int v = dst;
	int len = 0;

	std::stack<int> s;
	while (v != 0) {
		len += 1;
		s.push(v);
		v = touch[v];
	}

	std::cout << costs[dst] << '\n';
	std::cout << len << '\n';
	while (!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << '\n';
}

int main()
{
	int n;
	int m;

	std::cin >> n >> m;

	std::vector<std::vector<pii>> graph(n + 1); // (cost, vertex)

	for (int i = 0; i < m; ++i) {
		int src;
		int dst;
		int cost;
		std::cin >> src >> dst >> cost;
		graph[src].push_back({cost, dst});
	}

	int src;
	int dst;
	std::cin >> src >> dst;

	solve(graph, n, src, dst);

	return 0;
}