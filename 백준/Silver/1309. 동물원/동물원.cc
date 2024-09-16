#include <algorithm>
#include <climits>
#include <iostream>

#define DIVISOR (9901)
#define EMPTY (0)
#define LEFT (1)
#define RIGHT (2)
#define CURRENT (0)
#define NEXT (1)

int cache[2][3];

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;

	std::cin >> n;

	cache[CURRENT][EMPTY] = 1;
	cache[CURRENT][LEFT] = 1;
	cache[CURRENT][RIGHT] = 1;

	for (int i = 2; i <= n; ++i) {
		cache[NEXT][EMPTY] = cache[CURRENT][EMPTY] + cache[CURRENT][LEFT] + cache[CURRENT][RIGHT];
		cache[NEXT][LEFT] = cache[CURRENT][EMPTY] + cache[CURRENT][RIGHT];
		cache[NEXT][RIGHT] = cache[CURRENT][EMPTY] + cache[CURRENT][LEFT];

		cache[CURRENT][EMPTY] = cache[NEXT][EMPTY] % DIVISOR;
		cache[CURRENT][LEFT] = cache[NEXT][LEFT] % DIVISOR;
		cache[CURRENT][RIGHT] = cache[NEXT][RIGHT] % DIVISOR;
	}

	std::cout << (cache[CURRENT][EMPTY] + cache[CURRENT][LEFT] + cache[CURRENT][RIGHT]) % DIVISOR;

	return 0;
}
