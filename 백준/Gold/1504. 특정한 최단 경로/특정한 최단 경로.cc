#include <algorithm>
#include <iostream>

int D[801][801];

int main() {
	int n, e, a, b, c, v1, v2;
	const int INF = 3 * ((800 - 1) * 1000 + 1);

	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	std::cin >> n >> e;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
				D[i][j] = ((i == j) ? 0 : INF);
		}
	}
	for (int i = 0; i < e; ++i) {
		std::cin >> a >> b >> c;
		D[a][b] = c;
		D[b][a] = c;
	}
	std::cin >> v1 >> v2;

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	long dist1 = D[1][v1] + D[v1][v2] + D[v2][n];
	long dist2 = D[1][v2] + D[v2][v1] + D[v1][n];
	long answer = std::min(dist1, dist2);

	std::cout << ((answer >= INF) ? -1 : answer) << std::endl;

	return 0;
}