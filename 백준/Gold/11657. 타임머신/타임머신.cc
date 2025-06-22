#include <climits>
#include <iostream>
#include <vector>

struct edge
{
	int from;
	int to;
	int time;
};

int main()
{
	int N, M;
	std::cin >> N >> M;

	const long long inf = 5000001;
	std::vector<long long> dist(N + 1, inf);
	std::vector<edge> edges(M);

	for (int i = 0; i < M; ++i) {
		std::cin >> edges[i].from
				 >> edges[i].to
				 >> edges[i].time;
	}

	dist[1] = 0;
	bool bHasNegativeCycle = false;
	for (int i = 0; i < N; ++i) {
		for (edge &e : edges) {
			if (dist[e.from] == inf) {
				continue;
			}
			if (dist[e.to] > dist[e.from] + e.time) {
				dist[e.to] = dist[e.from] + e.time;
				if (i == N - 1) {
					bHasNegativeCycle = true;
				}
			}
		}
	}

	if (bHasNegativeCycle) {
		std::cout << -1 << '\n';
	} else {
		for (int i = 2; i <= N; ++i) {
			if (dist[i] == inf)
				dist[i] = -1;
			std::cout << dist[i] <<'\n';
		}
	}

	return 0;
}
