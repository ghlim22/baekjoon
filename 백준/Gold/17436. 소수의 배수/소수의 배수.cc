#include <iostream>

int main()
{
	long long n, m;
	int p[10];
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
		std::cin >> p[i];

	long long result = 0;
	int lmt = 1 << n;
	for (int i = 1; i < lmt; ++i) {
		int size = 0;
		long long intersect = 1;
		for (int j = 0; j < n; ++j) {
			if (1 & (i >> j)) {
				size += 1;
				intersect *= p[j];
			}
		}

		if (size % 2 == 0) {
			result -= m / intersect;
		}
		else {
			result += m / intersect;
		}
	}

	std::cout << result << std::endl;

	return 0;
}