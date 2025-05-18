#include <algorithm>
#include <iostream>
#include <queue>

struct coord
{
	int y;
	int x;
};

const int dy[3] = { 1, 0, 1 };
const int dx[3] = { 0, 1, 1 };

int dp[1000][1000];

int main()
{
	int N, M;

	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			std::cin >> dp[i][j];
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int cur = dp[y][x];
			int max_val = cur;
			for (int i = 0; i < 3; ++i) {
				int py = y - dy[i];
				int px = x - dx[i];
				if (!(py >= 0 && py < N && px >= 0 && px < M)) {
					continue;
				}
				int val = cur + dp[py][px];
				max_val = std::max(max_val, val);
			}
			dp[y][x] = max_val;
		}
	}

	std::cout << dp[N - 1][M - 1];

	return 0;
}