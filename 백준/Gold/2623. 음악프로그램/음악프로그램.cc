#include <iostream>
#include <vector>
#include <queue>

int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<int> in_degree(N + 1, 0);
	std::vector<std::vector<int>> graph(N + 1);
	for (int i = 0; i < M; ++i) {
		int size;
		std::cin >> size;
		std::vector<int> order(size);
		for (int j = 0; j < size; ++j) {
			std::cin >> order[j];
			in_degree[order[j]] += j;
		}
		for (int j = 0; j < size; ++j) {
			for (int k = j + 1; k < size; ++k)
				graph[order[j]].push_back(order[k]);
		}
	}

	std::vector<bool> visited(N + 1, false);
	std::vector<int> res;
	std::queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (!visited[cur]) {
			res.push_back(cur);
			visited[cur] = true;
		}
		for (int child : graph[cur]) {
			in_degree[child] -= 1;
			if (in_degree[child] == 0) {
				q.push(child);
			}
		}
	}

	if (res.size() != N) {
		std::cout << 0;
	} else {
		for (int r : res)
			std::cout << r << '\n';
	}

	return 0;
}