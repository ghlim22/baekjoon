#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
	int n;
	int ans;
	std::vector<int> seq;
	std::vector<int> cache;

	std::cin.tie(NULL)->sync_with_stdio(false);

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int num;
		std::cin >> num;
		seq.push_back(num);
	}

	cache.push_back(seq[0]);
	ans = seq[0];
	for (int i = 1; i < n; ++i) {
		if (cache[i - 1] < 0)
			cache.push_back(seq[i]);
		else
		 	cache.push_back(cache[i - 1] + seq[i]);
		ans = std::max(ans, cache.back());
	}

	std::cout << ans;
	

	return 0;
}
