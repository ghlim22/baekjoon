#include <algorithm>
#include <iostream>

int W[101];
int V[101];
int D[100001][101];

int main()
{
	int N;
	int K;
	std::cin >> N >> K;

	for (int i = 1; i <= N; ++i)
		std::cin >> W[i] >> V[i];

	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (W[j] <= i) {
				D[i][j] = std::max(D[i - W[j]][j - 1] + V[j], D[i][j - 1]);
			}
			else {
				D[i][j] = D[i][j - 1];
			}
		}
	}

	std::cout << D[K][N];

	return 0;
}