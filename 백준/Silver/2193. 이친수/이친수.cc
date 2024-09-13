#include <iostream>

#define MAX (90)

long cache[MAX + 1][2];

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;

	std::cin >> n;

	cache[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
		cache[i][1] = cache[i - 1][0];
	}

	std::cout << cache[n][0] + cache[n][1];

	return 0;
}
