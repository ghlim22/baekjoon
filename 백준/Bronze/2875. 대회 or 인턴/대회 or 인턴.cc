#include <iostream>

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	while (m > 0 && k > 0)
	{
		while (n > m * 2 && k > 0)
		{
			n--;
			k--;
		}
		if (k > 0)
		{
			m--;
			k--;
		}
	}

	int teams = 0;
	while (m > 0 && n >= 2)
	{
		n -= 2;
		m--;
		teams++;
	}

	std::cout << teams;

	return 0;
}