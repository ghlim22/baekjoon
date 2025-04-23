#include <iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;

	char s[51];
	int countA = 0;
	for (int i = 0; i < n; ++i)
	{
		s[countA++] = 'A';
		if (countA * (n - countA) >= k)
			break;
	}
	for (int i = countA; i < n; ++i)
	{
		s[i] = 'B';
	}

	if (countA == n)
	{
		std::cout << -1;
		return 0;
	}

	int countPair = countA * (n - countA);
	for (int i = countA - 1; i < n - 1 && countPair > k; ++i)
	{
		std::swap(s[i], s[i + 1]);
		countPair--;
	}

	s[n] = '\0';
	std::cout << s;

	return 0;
}