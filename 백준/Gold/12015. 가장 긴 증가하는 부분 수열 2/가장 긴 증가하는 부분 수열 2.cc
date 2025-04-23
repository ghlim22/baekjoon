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

	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
		std::cin >> v[i];

	std::vector<int> lis;
	lis.push_back(v[0]);

	for (int i = 1; i < n; ++i)
	{
		auto pos = std::lower_bound(lis.begin(), lis.end(), v[i]);
		if (pos == lis.end())
		{
			lis.push_back(v[i]);
		}
		else
		{
			*pos = v[i];
		}
	}

	std::cout << lis.size();

	return 0;
}