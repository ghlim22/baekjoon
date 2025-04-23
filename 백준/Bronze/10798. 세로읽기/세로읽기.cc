#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string> v;

	size_t width = 0;
	for (int i = 0; i < 5; ++i)
	{
		std::string l;
		std::cin >> l >> std::ws;
		v.push_back(l);
		width = std::max(width, l.size());
	}

	std::string ans;
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i >= v[j].size())
				continue;
			ans.push_back(v[j][i]);
		}
	}

	std::cout << ans;
}