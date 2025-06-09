#include <algorithm>
#include <cstring>
#include <climits>
#include <iostream>

int D[301][301];

int f(int i, int j)
{
	if (D[i][j] != -1) {
		return D[i][j];
	}

	int ret = INT_MAX;
	for (int k = 1; k <= i / 2; ++k) {
		int tmp = 1 + f(k, j) + f(i - k, j);
		ret = std::min(ret, tmp);
	}

	for (int k = 1; k <= j / 2; ++k) {
		int tmp = 1 + f(i, k) + f(i, j - k);
		ret = std::min(ret, tmp);
	}

	D[i][j] = ret;
	return D[i][j];
}

int main()
{
	int N, M;
	std::cin >> N >> M;
	std::memset(D, -1, sizeof(D));
	D[1][1] = 0;
	std::cout << f(N, M) << std::endl;
	return 0;
}