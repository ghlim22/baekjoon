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

	if (n <= m)
	{
		std::cout << n;
		return 0;
	}

	long lo = 1;
	long hi = 60000000000;
	int answer = 0;
	while (lo <= hi)
	{
		long mid = (lo + hi) / 2;

		long prevSum = m;
	    long sum = m;
		for (int i = 0; i < m; ++i)
		{
			prevSum += (mid - 1) / ride[i];
			sum += mid / ride[i];
			if (n <= prevSum)
				break;
		}

		if (n <= sum)
		{
			if (n <= prevSum)
			{
				hi = mid - 1;
			}
			else
			{
				long count = prevSum;
				for (int i = 0; i < m; ++i)
				{
					if (mid % ride[i] == 0)
					{
						count++;
					}
					if (count == n)
					{
						answer = i + 1;
						break;
					}
				}
				break;
			}
		}
		else
		{
			lo = mid + 1;
		}
	}

	std::cout << answer;

	return 0;
}