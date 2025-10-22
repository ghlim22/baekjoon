#include <algorithm>
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

int N;
std::vector<std::vector<pii_t>> W;
std::vector<std::vector<pii_t>> B;
std::vector<bool> RDIA(2 * 10 - 1);

int solve(std::vector<std::vector<pii_t>> &bishops, int index) {
	if (index == bishops.size()) {
		return 0;
	}

	int retval = solve(bishops, index + 1);
	for (auto p : bishops[index]) {
		int rdia = p.first + p.second;
		if (RDIA[rdia]) continue;
		RDIA[rdia] = true;
		retval = std::max(retval, 1 + solve(bishops, index + 1));
		RDIA[rdia] = false;
	}

	return retval;
}

int main() {
	fastio;
	std::cin >> N;

	W.resize(2 * N - 1, std::vector<pii_t>());
	B.resize(2 * N - 1, std::vector<pii_t>());

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			int p;
			std::cin >> p;
			if (p == 0) {
				continue;
			}

			int dia = y - x + N - 1;
			if (y % 2 == 0) {
				if (x % 2 == 0) {
					W[dia].push_back({y, x});
				} else {
					B[dia].push_back({y, x});
				}
			} else {
				if (x % 2) {
					W[dia].push_back({y, x});
				} else {
					B[dia].push_back({y, x});
				}
			}
		}
	}

	int retval = solve(W, 0) + solve(B, 0);
	std::cout << retval;

	return 0;
}
