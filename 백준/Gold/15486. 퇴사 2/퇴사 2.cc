#include <algorithm>
#include <iostream>

int T[1500001];
int P[1500001];
int D[1500002];

int main()
{
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; ++i)
		std::cin >> T[i] >> P[i];

	for (int i = 1; i <= N; ++i) {
		if (i + T[i] <= N + 1) {
			D[i + T[i]] = std::max(D[i + T[i]], D[i] + P[i]);
		}
		if (i + 1 <= N + 1) {
			D[i + 1] = std::max(D[i + 1], D[i]);
		}
	}

	std::cout << D[N + 1];

	return 0;
}