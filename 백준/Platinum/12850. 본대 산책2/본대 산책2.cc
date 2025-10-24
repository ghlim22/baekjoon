#include <cassert>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<long>> matrix;

int mod = 1000000007;

matrix operator*(const matrix &a, const matrix &b) {
	int height_a = a.size();
	int width_a = a[0].size();
	int width_b = b[0].size();

	matrix retval(height_a, std::vector<long>(width_b));
	for (int i = 0; i < height_a; ++i) {
		for (int j = 0; j < width_b; ++j) {
			retval[i][j] = 0;
			for (int k = 0; k < width_a; ++k) {
				retval[i][j] += a[i][k] * b[k][j];
				retval[i][j] %= mod;
			}
		}
	}

	return retval;
}

int main() {
	matrix answer(8, std::vector<long>(8));
	for (int i = 0; i < 8; ++i) {
		answer[i][i] = 1;
	}

	matrix graph(8, std::vector<long>(8));
	graph[0][1] = graph[1][0] = 1;
	graph[0][2] = graph[2][0] = 1;
	graph[1][2] = graph[2][1] = 1;
	graph[1][3] = graph[3][1] = 1;
	graph[2][3] = graph[3][2] = 1;
	graph[2][5] = graph[5][2] = 1;
	graph[3][4] = graph[4][3] = 1;
	graph[3][5] = graph[5][3] = 1;
	graph[4][5] = graph[5][4] = 1;
	graph[4][6] = graph[6][4] = 1;
	graph[6][7] = graph[7][6] = 1;
	graph[5][7] = graph[7][5] = 1;

	int d;
	std::cin >> d;

	while (d > 0) {
		if (d & 1) {
			answer = answer * graph;
		}
		graph = graph * graph;
		d >>= 1;
	}

	std::cout << answer[0][0];

	return 0;
}