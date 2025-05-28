#include <algorithm>
#include <iostream>

long D[101];

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i) {
		D[i] = D[i - 1] + 1;
		for (int j = 1; j <= i - 3; ++j) {
			D[i] = std::max(D[i], D[i - (j + 2)] * (j + 1));
		}
	}

	std::cout << D[N];

	return 0;
}
