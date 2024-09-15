#include <algorithm>
#include <iostream>

#define DIVISOR (1000000000)

int cache[201];

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;
	int k;

	std::cin >> n >> k;

	cache[0] = 0;
	for (int i = 1; i <= k; ++i) {
		cache[i] = 1;
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			cache[j] = cache[j - 1] + cache[j];
			cache[j] %= DIVISOR;
		}
	}

	std::cout << cache[k];
	
	return 0;
}
