#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

int cache[2][5][5];

int move_cost(int cur, int next) {
	if (cur == next)
		return 1;
	else if (cur == 0)
		return 2;
	else if (std::abs(cur - next) == 2)
		return 4;
	else
		return 3;
}

int main(void) {
  fastio;
  int p;
  int answer = 0;

  std::memset(cache, -1, sizeof(cache));
  cache[0][0][0] = 0;

  for (;;) {
	std::cin >> p;
	if (p == 0) break;

	int min_cost = 400001;
	// left
	for (int i = 0; i <= 4; ++i) {
		for (int j = 0; j <= 4; ++j) {
			if (cache[0][i][j] == -1) continue;

			int left_cost = move_cost(i, p);
			if (cache[1][p][j] == -1) {
				cache[1][p][j] = left_cost + cache[0][i][j];
			} else {
				cache[1][p][j] = std::min(cache[1][p][j], left_cost + cache[0][i][j]);
			}

			int right_cost = move_cost(j, p);
			if (cache[1][i][p] == -1) {
				cache[1][i][p] = right_cost + cache[0][i][j];
			} else {
				cache[1][i][p] = std::min(cache[1][i][p], right_cost + cache[0][i][j]);
			}

			min_cost = std::min(min_cost, std::min(cache[1][i][p], cache[1][p][j]));
		}
	}

	answer = min_cost;
	std::memcpy(cache[0], cache[1], sizeof(cache[0]));
	std::memset(cache[1], -1, sizeof(cache[1]));
  }

  std::cout << answer << std::endl;

  return 0;
}