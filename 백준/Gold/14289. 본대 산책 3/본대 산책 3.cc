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
    int n, m, d;

	std::cin >> n >> m;

	matrix M(n, std::vector<long>(n));
	for (int i = 0; i < n; ++i) {
		M[i][i] = 1;
	}

	matrix W(n, std::vector<long>(n));
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;
		W[a][b] = W[b][a] = 1;
	}

	std::cin >> d;

	while (d > 0) {
		if (d & 1) {
			M = M * W;
		}
		W = W * W;
		d >>= 1;
	}

	std::cout << M[0][0];

	return 0;
}