#include <algorithm>
#include <iostream>

int array[5000];

bool check(int n, int m, int k)
{
	int i = 1;
	int min = array[0];
	int max = array[0];
	for (int j = 0; j < n; ++j)
	{
		min = std::min(min, array[j]);
		max = std::max(max, array[j]);
		if (max - min > k)
		{
			i++;
			min = array[j];
			max = array[j];
		}
	}
	return (i <= m);
}

int main()
{
	int n, m;

	std::cin >> n >> m;

	for (int i = 0; i < n; ++i)
		std::cin >> array[i];

	int lo = 0;
	int hi = 10000;

	while (lo < hi) {
		int mid = (lo + hi) /2;
		if (check(n, m, mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	std::cout << hi;

	return 0;
}