#include <algorithm>
#include <climits>
#include <iostream>

#define DIVISOR (1000000009)
#define MAX (1000000)

unsigned int cache[MAX + 1];

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;
	int t;

	std::cin >> t;

	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;

	for (int i = 4; i <= MAX; ++i) {
		cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
		cache[i] %= DIVISOR;
	}

	while (t--) {
		std::cin >> n;
		std::cout << cache[n] << '\n';
	}

	return 0;
}
