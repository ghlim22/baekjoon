#include <algorithm>
#include <iostream>

int D[1500001];

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		int T, P;
		std::cin >> T >> P;
		if (i + T <= N) {
			D[i + T] = std::max(D[i + T], D[i] + P);
		}
		D[i + 1] = std::max(D[i + 1], D[i]);
	}
	std::cout << D[N];

	return 0;
}
