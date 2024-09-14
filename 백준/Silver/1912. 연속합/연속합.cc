#include <iostream>

int main(void)
{
	int n;
	int num;
	int cache;
	int ans;

	std::cin.tie(NULL)->sync_with_stdio(false);

	std::cin >> n;
	std::cin >> cache;
	ans = cache;
	for (int i = 1; i < n; ++i) {
		std::cin >> num;
		if (cache < 0)
			cache = num;
		else
		 	cache += num;

		if (cache > ans)
			ans = cache;
	}

	std::cout << ans;

	return 0;
}
