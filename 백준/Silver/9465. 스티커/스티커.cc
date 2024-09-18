#include <algorithm>
#include <iostream>

#define MAX (1000000)

unsigned int cache[2][MAX];

int main(void) {
  int n;
  int t;

  std::cin.tie(NULL)->sync_with_stdio(false);

  std::cin >> t;

  while (t--) {
    /* Input */
    std::cin >> n;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j)
        std::cin >> cache[i][j];
    }

    /* Solve */
    unsigned int score = std::max(cache[0][0], cache[1][0]);
	for (int x = 1; x < n; ++x) {
		for (int y = 0; y < 2; ++y) {
			cache[y][x] = std::max(cache[y ^ 1][x - 1] + cache[y][x], cache[y][x - 1]);
			score = std::max(score, cache[y][x]);
		}
	}
	std::cout << score << '\n';
  }

  return 0;
}
