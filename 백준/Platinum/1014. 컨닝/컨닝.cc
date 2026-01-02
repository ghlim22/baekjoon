#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)


int map[10][10];
long cache[10][1 << 10];
std::vector<std::vector<int>> allSeatings(11);
int n, m;


void findAllSeating(int cursor, int colSize, int seating) {
	if (cursor == colSize) {
		allSeatings[colSize].push_back(seating);
		return;
	}
	if (cursor == 0 || !(seating & (1 << (cursor - 1)))) {
		findAllSeating(cursor + 1, colSize, seating | (1 << cursor));
	}
	findAllSeating(cursor + 1, colSize, seating);
}


long solve(int cursor, int status) {
	if (cursor == n) {
		return 0;
	}
	if (cache[cursor][status] != -1) {
		return cache[cursor][status];
	}
	cache[cursor][status] = 0;
	long maxval = 0;
	for (int curStatus : allSeatings[m]) {
		long count = 0;
		for (int i = 0; i < m; ++i) {
			int put = curStatus & (1 << i);
			if (!put) {
				continue;
			} else if (!map[cursor][i] || (i > 0 && (status & (1 << (i - 1)))) || (i < m - 1 && (status & (1 << (i + 1))))) {
				goto NEXT;
			}
			count++;
		}
		maxval = std::max(maxval, count + solve(cursor + 1, curStatus));
		NEXT: ;
	}
	return cache[cursor][status] = maxval;
}

int main(void) {
  fastio;

  for (int i = 1; i <= 10; ++i) {
	findAllSeating(0, i, 0);
  }

  int c;
  std::cin >> c;
  while (c--) {
	memset(map, 0, sizeof(map));
	memset(cache, -1, sizeof(cache));
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '.') {
				map[i][j] = 1;
			}
		}
	}
	std::cout << solve(0, 0) << '\n';
  }

  return 0;
}