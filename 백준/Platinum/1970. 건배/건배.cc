
#include <algorithm>
#include <cstring>
#include <iostream>

int C[1001];
int D[1001][1001];

int f(int i, int j)
{
	if (i >= j) {
		return 0;
	}

	if (D[i][j] != -1) {
		return D[i][j];
	}

	int ret = f(i + 1, j);
	for (int k = i + 1; k <= j; ++k) {
		if (C[i] == C[k]) {
			int tmp = 1 + f(i + 1, k - 1) + f(k + 1, j);
			ret = std::max(ret, tmp);
		}
	}
	D[i][j] = ret;
	return D[i][j];
}

int main()
{
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; ++i) {
		std::cin >> C[i];
	}

	std::memset(D, -1, sizeof(D));
	std::cout << f(1, N) << std::endl;

	return 0;
}