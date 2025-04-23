#include <iostream>

int main()
{
	int n, m, k, teams = 0;
	std::cin >> n >> m >> k;
	/* Form teams, leaving at least k students */
	while (n >= 2 && m >= 1 && (n + m - 3) >= k)
	{
		n -= 2;
		m -= 1;
		teams++;
	}
	std::cout << teams;

	return 0;
}