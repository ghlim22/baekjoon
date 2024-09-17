#include <algorithm>
#include <iostream>

#define MAX (1000)
#define DIVISOR (10007)

unsigned int cache[MAX + 1][10];

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;

	std::cin >> n;
	
	for (int i = 0; i < 10; ++i) {
		cache[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k <= j; ++k) {
				cache[i][j] += cache[i - 1][k];
			}
			cache[i][j] %= DIVISOR;
		}
	}

	unsigned int cnt = 0;
	for (int i = 0; i < 10; ++i) {
		cnt += cache[n][i];
	}
	std::cout << cnt % DIVISOR;

	return 0;
}
