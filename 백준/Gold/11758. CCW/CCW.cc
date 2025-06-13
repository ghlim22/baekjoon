#include <iostream>

int main()
{
	int x[4], y[4];
	for (int i = 0; i < 3; ++i) {
		std::cin >> x[i] >> y[i];
	}
	x[3] = x[0];
	y[3] = y[0];
	
	int cp = 0;
	for (int i = 0; i < 3; ++i) {
		cp += x[i] * y[i + 1];
	}
	for (int i = 0; i < 3; ++i) {
		cp -= y[i] * x[i + 1];
	}

	if (cp < 0) {
		std::cout << -1;
	} else if (cp == 0) {
		std::cout << 0;
	} else {
		std::cout << 1;
	}

	return 0;
}