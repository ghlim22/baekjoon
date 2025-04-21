#include <iostream>

int ride[10000];

int main()
{
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	long n, m;

	std::cin >> n >> m;
	for (int i = 0; i < m; ++i)
		std::cin >> ride[i];

	long lo = 0;
	long hi = 60000000000;
	while (lo <= hi)
	{
		long mid = (lo + hi) / 2;

		long begin = 0;
		long last = m;

		for (int i = 0; i < m; ++i)
		{
			last += (mid / ride[i]);
		}

		begin = last;
		for (int i = 0; i < m; ++i)
		{
			if (mid % ride[i] == 0)
				begin--;
		}

		if (n <= begin)
		{
			hi = mid - 1;
		}
		else if (n > last)
		{
			lo = mid + 1;
		}
		else
		{
			for (int i = 0; i < m; ++i)
			{
				if (mid % ride[i] == 0)
				{
					begin++;
				}
				if (begin == n)
				{
					std::cout << i + 1;
					return 0;
				}
			}
		}
	}

	return 0;
}