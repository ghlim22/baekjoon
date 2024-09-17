#include <algorithm>
#include <iostream>

#define MAX (1000)
#define RED (0)
#define GREEN (1)
#define BLUE (2)

unsigned int cache[MAX + 1][3];

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;
	int r;
	int g;
	int b;

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> r >> g >> b;
		cache[i][RED] = std::min(cache[i - 1][GREEN], cache[i - 1][BLUE]) + r;
		cache[i][GREEN] = std::min(cache[i - 1][RED], cache[i - 1][BLUE]) + g;
		cache[i][BLUE] = std::min(cache[i - 1][RED], cache[i - 1][GREEN]) + b;
	}
	unsigned int cost = std::min(cache[n][RED], cache[n][GREEN]);
	cost = std::min(cost, cache[n][BLUE]);
	std::cout << cost;

	return 0;
}
