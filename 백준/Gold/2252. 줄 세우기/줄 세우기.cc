#include <iostream>
#include <queue>

#define MAX 32000

int inDegree[MAX + 1];
std::vector<std::vector<int>> graph(MAX + 1);

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		inDegree[v] += 1;
	}

	std::queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		std::cout << u << ' ';

		for (int v : graph[u]) {
			inDegree[v] -= 1;
			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
	}
	std::cout << std::endl;

	return 0;
}