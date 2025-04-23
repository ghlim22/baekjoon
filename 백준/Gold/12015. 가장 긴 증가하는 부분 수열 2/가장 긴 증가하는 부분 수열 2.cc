#include <algorithm>
#include <iostream>
#include <vector>

#define fastio                            \
	do                                    \
	{                                     \
		std::ios::sync_with_stdio(false); \
		std::cin.tie(0);                  \
		std::cout.tie(0);                 \
	} while (0)

int main()
{
	fastio;

	int n;
	std::cin >> n;

	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		auto it = std::lower_bound(v.begin(), v.end(), num);
		if (it == v.end())
			v.push_back(num);
		else
			*it = num;
	}

	std::cout << v.size();

	return 0;
}