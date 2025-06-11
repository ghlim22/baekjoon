#include <iostream>

bool check[1000001];

int main()
{
	long long min, max;
	std::cin >> min >> max;

	int counter = 0;
	for (long long i = 2; i * i <= max; ++i) {
		long long start = i * i - min % (i * i);
		if (start == i * i) {
			start = 0;
		}

		for (long long j = start; j <= max - min; j += i * i) {
			if (!check[j]) {
				check[j] = true;
				counter++;
			}
		}
	}	

	std::cout << (max - min - counter + 1) << std::endl;

	return 0;
}