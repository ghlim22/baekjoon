#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

typedef long long ll;
typedef std::pair<long long, long long> pll;

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);
	
	int N, M, A, B;

	std::cin >> N >> M;

	std::vector<std::vector<pll>> graph(N + 1); // graph[i]: <weight, vertex>

	for (int i = 0; i < M; ++i) {
		int from, to, weight;
		std::cin >> from >> to >> weight;
		graph[from].push_back({weight, to});
	}
	std::cin >> A >> B;

	const long long INF = 100000L*100000+1;
	std::priority_queue<pll, std::vector<pll>, std::greater<pll>> pq; // <distance, vertex>
	std::vector<long long> distances(N + 1, INF); // distance of the current shortest path starting from A.
	std::vector<bool> visited(N+1);

	pq.push({0, A});
	while (!pq.empty() && !visited[B]) {
		auto current = pq.top();
		pq.pop();
		ll distance = current.first;
		ll vertex = current.second;

		if (visited[vertex]) {
			continue;
		}

		for (const auto &e : graph[vertex]) {
			ll nd = distance + e.first;
			if (nd < distances[e.second]) {
				distances[e.second] = nd;
				pq.push({nd, e.second});
			}
		}

		visited[vertex] = true;
	}

	std::cout << distances[B] << std::endl;

	return 0;
}