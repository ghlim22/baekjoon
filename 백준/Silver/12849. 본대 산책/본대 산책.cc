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

typedef std::vector<std::vector<long>> matrix;

matrix operator*(const matrix &a, const matrix &b) {
	matrix retval(a.size(), std::vector<long>(b[0].size()));

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b[0].size(); ++j) {
			for (int k = 0; k < a[0].size(); ++k) {
				retval[i][j] += a[i][k] * b[k][j];
				retval[i][j] %= 1000000007;
			}
		}
	}

	return retval;
}

int main(void) {
  fastio;

  int d;
  std::cin >> d;

  matrix W(8, std::vector<long>(8));
  matrix I(8, std::vector<long>(8));

  W[0][1] = W[1][0] = 1;
  W[0][2] = W[2][0] = 1;
  W[1][2] = W[2][1] = 1;
  W[1][3] = W[3][1] = 1;
  W[2][3] = W[3][2] = 1;
  W[3][4] = W[4][3] = 1;
  W[2][4] = W[4][2] = 1;
  W[3][5] = W[5][3] = 1;
  W[4][5] = W[5][4] = 1;
  W[5][6] = W[6][5] = 1;
  W[4][7] = W[7][4] = 1;
  W[6][7] = W[7][6] = 1;

  for (int i = 0; i < 8; ++i) {
	I[i][i] = 1;
  }

  while (d > 0) {
	if (d & 1) {
		I = I * W;
	}
	W = W * W;
	d >>= 1;
  }

  std::cout << I[0][0];

  return 0;
}