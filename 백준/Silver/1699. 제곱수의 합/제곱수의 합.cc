#include <algorithm>
#include <iostream>

#define MAX (100000)

int cache[MAX + 1];

int main(void)
{
	int n;

	std::cin.tie(NULL)->sync_with_stdio(false);

	std::cin >> n;

	cache[1] = 1;
	for (int i = 2; i <= n; ++i) {
		cache[i] = cache[i - 1] + 1;
		for (int j = 2; j * j <= i; ++j) {
			cache[i] = std::min(cache[i], cache[i - j * j] + 1);
		}
	}

	std::cout << cache[n];

	return 0;
}
