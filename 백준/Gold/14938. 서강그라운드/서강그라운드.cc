#include <algorithm>
#include <iostream>

int INF = (100 - 1) * 15 + 1;
int region[31];
int graph[101][101];
int n, m, r;

int main() {
	std::cin >> n >> m >> r;
	for (int i = 0; i < n; ++i) {
		std::cin >> region[i + 1];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			graph[i][j] = ((i == j) ? 0 : INF);
		}
	}

	for (int i = 0; i < r; ++i) {
		int a, b, l;
		std::cin >> a >> b >> l;
		if (graph[a][b] > l) {
			graph[a][b] = l;
			graph[b][a] = l;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 1; j <= n; ++j) {
			if (graph[i][j] <= m)
				sum += region[j];
		}
		answer = std::max(answer, sum);
	}
	std::cout << answer << std::endl;

	return 0;
}