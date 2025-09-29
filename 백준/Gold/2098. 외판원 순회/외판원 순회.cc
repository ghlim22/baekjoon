#include <algorithm>
#include <iostream>
#include <vector>

#define INF 15000000

int N;
int W[16][16];
int D[16][1<<16];

int size_of_set(int32_t set) {
	int size = 0;
	for (int i = 0; i < N; ++i) {
		if ((set >> i) & 1) {
			size++;
		}
	}
	return size;
}

bool has_elem(int set, int elem) {
	return (set >> elem) & 1;
}

// V0가 시작점.
int main() {
	std::cin >> N;

	const int LMT = (1 << N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < LMT; ++j)
			D[i][j] = INF;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> W[i][j];
			if (W[i][j] == 0 && i != j) {
				W[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		D[i][0] = W[i][0];
	}

	for (int k = 1; k <= N - 2; ++k) {
		for (int subset = 1; subset < LMT; ++subset) {
			if (size_of_set(subset) != k)
				continue;
			if (has_elem(subset, 0))
				continue;
			for (int i = 1; i < N; ++i) {
				if (has_elem(subset, i))
					continue;
				for (int j = 1; j < N; ++j) {
					if (i == j)
						continue;
					if (has_elem(subset, j)) {
						D[i][subset] = std::min(D[i][subset], W[i][j] + D[j][subset ^ (1 << j)]);
					}
				}	
			}		
		}
	}

	for (int j = 1; j < N; ++j) {
		D[0][(LMT - 1) ^ 1] = std::min(D[0][(LMT - 1) ^ 1], W[0][j] + D[j][(LMT - 1) ^ 1 ^ (1 << j)]);
	}
	std::cout << D[0][(LMT - 1) ^ 1] << std::endl;

	return 0;
}