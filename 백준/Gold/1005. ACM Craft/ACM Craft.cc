#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

int D[1001];
int CACHE[1001];
std::vector<std::vector<int>> *dependencies = nullptr;

int backtrack(int node) {
	if (CACHE[node] != -1) {
		return CACHE[node];
	}
	int delayed = 0;
	for (int dependency : (*dependencies)[node]) {
		delayed = std::max(delayed, backtrack(dependency));
	}
	return CACHE[node] = delayed + D[node];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) {
		int N, K, W;
		std::cin >> N >> K;

		std::memset(CACHE, -1, sizeof(CACHE));
		dependencies = new std::vector<std::vector<int>>(N + 1);
		for (int i = 1; i <= N; ++i) {
			std::cin >> D[i];
		}
		for (int i = 0; i < K; ++i) {
			int x, y;
			std::cin >> x >> y;
			(*dependencies)[y].push_back(x);
		}
		std::cin >> W;

		std::cout << backtrack(W) << '\n';
		
		delete dependencies;
		dependencies = nullptr;
	}

	return 0;
}