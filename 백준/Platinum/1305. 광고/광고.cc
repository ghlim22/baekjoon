#include <algorithm>
#include <iostream>
#include <vector>

int solve(const std::string &s, int l)
{
	std::vector<int> v(l);
	v[0] = 0;
	int j = 0;
	for (int i = 1; i < l; ++i)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = v[j - 1];
		}

		if (s[i] == s[j])
		{
			v[i] = j + 1;
			j++;
		}
		else
		{
			v[i] = 0;
		}
	}

	return l - v[l - 1];
}

int main()
{
	int l;
	std::string s;

	std::cin >> l >> s;
	std::cout << solve(s, l);

	return 0;
}