#include <algorithm>
#include <iostream>

int D[1001][1001];

int main()
{
	int N, M;
	std::cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			std::cin >> D[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			D[i][j] = std::max(D[i - 1][j], D[i][j - 1]) + D[i][j];
		}
	}

	std::cout << D[N][M];

	return 0;
}