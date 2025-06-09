#include <cstring>
#include <iostream>

int N, M, K;
int mod = 1000001;
long long D[101][101][101];

long long f(int height, int width, int rook)
{
	if (rook == 0) {
		return 1;
	}

	if (rook < 0) {
		return 0;
	}

	if (height <= 0 || width <= 0) {
		return 0;
	}

	long long& ret = D[height][width][rook];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	ret += f(height - 1, width, rook);
	ret += f(height - 1, width - 1, rook - 1) * width;
	ret += f(height - 1, width - 2, rook - 2) * width * (width - 1) / 2;
	ret += f(height - 2, width - 1, rook - 2) * (height - 1) * width;
	ret %= mod;

	return ret;
}

int main()
{
	std::cin >> N >> M >> K;
	std::memset(D, -1, sizeof(D));
	std::cout << f(N, M, K) << std::endl;
	return 0;
}
