#include <iostream>

int V[51];
int D[51][1001];

int main()
{
	int N, S, M;
	std::cin >> N >> S >> M;
	for (int i = 1; i <= N; ++i) {
		std::cin >> V[i];
	}

	D[0][S] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			if (D[i - 1][j] == 0) {
				continue;
			}
			if (j + V[i] <= M) {
				D[i][j + V[i]] = 1;
			}
			if (j - V[i] >= 0) {
				D[i][j - V[i]] = 1;
			}
		}
	}

	int answer = -1;
	for (int i = M; i >= 0; --i) {
		if (D[N][i]) {
			answer = i;
			break;
		}
	}
	std::cout << answer;

	return 0;
}