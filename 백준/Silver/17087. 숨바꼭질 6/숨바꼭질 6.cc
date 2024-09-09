#include <iostream>
#include <valarray>
#include <vector>

int findGCD(int a, int b)
{
	if (a < b) {
		std::swap(a, b);
	}

	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int gcd = 0;
	int subinLocation = 0;
	int sisterLocation = 0;
	int sisterCount = 0;

	std::cin >> sisterCount >> subinLocation;

	while (sisterCount--) {
		std::cin >> sisterLocation;
		gcd = findGCD(gcd, std::abs(sisterLocation - subinLocation));
	}

	std::cout << gcd;

	return 0;
}
