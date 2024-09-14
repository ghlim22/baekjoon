#include <algorithm>
#include <iostream>

#define DIVISOR (1000000000)

int cache[201][201];

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;
	int k;

	std::cin >> n >> k;
	
	for (int i = 0; i <= n; ++i)
		cache[i][1] = 1;
	for (int i = 1; i <= k; ++i)
		cache[0][i] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			cache[i][j] = cache[i][j - 1] + cache[i - 1][j];
			cache[i][j] %= DIVISOR;
		}
	}

	std::cout << cache[n][k];

	return 0;
}
