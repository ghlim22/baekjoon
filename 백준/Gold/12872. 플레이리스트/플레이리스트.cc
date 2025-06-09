#include <algorithm>
#include <cstring>
#include <iostream>

long long D[101][101];
int N, M, P;
int mod = 1000000007;

long long f(int p, int x)
{
	if (p == P) {
		if (x == N) {
			return 1;
		}
		else {
			return 0;
		}
	}

	if (D[p][x] != -1) {
		return D[p][x];
	}

	long long ret = 0;
	int y = N - x;
	if (y > 0) {
		ret += y * f(p + 1, x + 1);
	}
	if (x > M) {
		ret += (x - M) * f(p + 1, x);
	}

	D[p][x] = ret % mod;

	return D[p][x];
}

int main()
{
	std::cin >> N >> M >> P;
	std::memset(D, -1, sizeof(D));
	std::cout << f(0, 0) << std::endl;
	return 0;
}