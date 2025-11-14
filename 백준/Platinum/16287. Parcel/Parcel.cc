#include <iostream>

#define LMT (2 * 200000)
int n;
int w;
int a[5001];
int cache[LMT][2];

int main() {
	std::cin >> w >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int sum = a[i] + a[j];
			int pair = w - sum;
			if (pair > 0 && pair < LMT && cache[pair][0] != 0) {
				int k = cache[pair][0];
				int l = cache[pair][1];
				if (i != k && i != l && j != k && j != l) {
					std::cout << "YES\n";
					return 0;
				}
			}
			if (cache[sum][0] == 0) {
				cache[sum][0] = i;
				cache[sum][1] = j;
			}
		}
	}

	std::cout << "NO\n";

	return 0;
}