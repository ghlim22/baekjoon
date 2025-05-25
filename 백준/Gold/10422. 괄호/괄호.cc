#include <iostream>

long D[5001];

int main()
{
	int T;
	int L;

	int m = 1000000007;
	D[0] = 1;
	for (int len = 2; len <= 5000; len += 2) {
		for (int i = 2; i <= len; i += 2) {
			D[len] += (D[i - 2] % m * D[len - i] % m) % m;
			D[len] %= m;
		}
		D[len] %= m;
	}

	std::cin >> T;
	while (T--) {
		std::cin >> L;
		std::cout << D[L] << '\n';
	}

	return 0;
}
