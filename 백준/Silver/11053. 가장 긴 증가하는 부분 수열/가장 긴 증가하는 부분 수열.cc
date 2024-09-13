#include <algorithm>
#include <iostream>
#include <vector>

#define MAX (1000)

int a[MAX];
int cache[MAX];

int main(void)
{
	int n;
	int ans = 0;

	std::cin.tie(NULL)->sync_with_stdio(false);

	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		cache[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i])
				cache[i] = std::max(cache[i], cache[j] + 1);
		}
		ans = std::max(ans, cache[i]);
	}

	std::cout << ans;

	return 0;
}
