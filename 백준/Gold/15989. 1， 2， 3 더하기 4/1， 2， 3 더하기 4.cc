#include <iostream>

int D[10001][4];

int main()
{
	int T;
	std::cin >> T;

	D[1][1] = 1;
	D[2][1] = 1;
	D[2][2] = 1;
	D[3][1] = 1;
	D[3][2] = 1;
	D[3][3] = 1;

	for (int i = 4; i <= 10000; ++i) {
		D[i][1] = D[i - 1][1];
		D[i][2] = D[i - 2][1] + D[i - 2][2];
		D[i][3] = D[i - 3][1] + D[i - 3][2] + D[i - 3][3];
	}

	while (T--) {
		int n;
		std::cin >> n;
		std::cout << D[n][1] + D[n][2] + D[n][3] << '\n';
	}

	return 0;
}