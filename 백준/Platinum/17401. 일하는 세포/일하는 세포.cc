#include <iostream>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

#define MODULUS 1000000007

typedef std::vector<std::vector<long>> matrix;

matrix operator*(const matrix &a, const matrix &b) {
	int a_height = a.size();
	int a_width = a[0].size(); // == b_height
	int b_width = b[0].size();
	matrix retval(a_height, std::vector<long>(b_width));
	for (int i = 0; i < a_height; ++i) {
		for (int j = 0; j < b_width; ++j) {
			for (int k = 0; k < a_width; ++k) {
				retval[i][j] += (a[i][k] * b[k][j]) % MODULUS;
			}
			retval[i][j] %= MODULUS;
		}
	}
	return retval;
}

int main(void) {
  fastio;

  int t, n, d;
  std::cin >> t >> n >> d;
  
  std::vector<matrix> maps;
  for (int i = 0; i < t; ++i) {
	matrix tmp(n, std::vector<long>(n));
	int m;
	std::cin >> m;
	for (int j = 0; j < m; ++j) {
		int a, b, c;
		std::cin >> a >> b >> c;
		tmp[a - 1][b - 1] = c;
	}
	maps.push_back(tmp);
  }

  matrix idenity(n, std::vector<long>(n));
  for (int i = 0; i < n; ++i) {
	idenity[i][i] = 1;
  }

  matrix period = idenity;
  for (int i = 0; i < t; ++i) {
	period = period * maps[i];
  }

  int x = d / t;
  int y = d % t;

  matrix answer = idenity;
  while (x > 0) {
	if (x & 1) {
		answer = answer * period;
	}
	period = period * period;
	x >>= 1;
  }
  for (int i = 0; i < y; ++i) {
	answer = answer * maps[i];
  }

  for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j) {
		std::cout << answer[i][j] << ' ';
	}
	std::cout << '\n';
  }

  return 0;
}