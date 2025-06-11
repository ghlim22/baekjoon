
#include <iostream>
#include <vector>

typedef std::vector<std::vector<long long>> matrix;

matrix operator*(const matrix& lhs, const matrix& rhs)
{
	int n = lhs.size();
	int r = lhs[0].size();
	int m = rhs[0].size();
	int mod = 1000000007;

	matrix result(n, std::vector<long long>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < r; ++k) {
				result[i][j] += (lhs[i][k] * rhs[k][j]) % mod;
			}
			result[i][j] %= mod;
		}
	}

	return result;
}

int main()
{
	long long n;
	std::cin >> n;

	matrix base = { 
		{1, 1}, 
		{1, 0} 
	};

	matrix result = {
		{1, 0},
		{0, 1}
	};

	while (n > 0) {
		if (n & 1) {
			result = base * result;
		}
		base = base * base;
		n >>= 1;
	}

	std::cout << result[0][1] << std::endl;

	return 0;
}