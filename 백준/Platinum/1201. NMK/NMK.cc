#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;

	if (!(n >= k + m - 1 && n <= m * k))
	{
		std::cout << -1;
		return 0;
	}

	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
		v[i] = i + 1;

	std::vector<int> b(m);
	b[0] = k;
	if (m > 1)
	{
		int q = (n - k) / (m - 1);
		int r = (n - k) % (m - 1);
		for (int i = 1; i < m; ++i)
		{
			b[i] = q;
			if (r > 0)
			{
				b[i]++;
				r--;
			}
		}
	}

	for (int i = 0, start = 0; i < m; ++i)
	{
		int end = start + b[i];
		std::sort(v.begin() + start, v.begin() + end, std::greater());
		start = end;
	}

	for (int num : v)
		std::cout << num << ' ';

	return 0;
}