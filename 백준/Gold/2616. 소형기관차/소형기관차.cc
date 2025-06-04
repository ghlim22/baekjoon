
#include <algorithm>
#include <iostream>
#include <vector>

int A[50001];
int S[50001];
int D[50001][4];
bool used[50001];

int main()
{
	int N;
	int K;
	std::cin >> N;
	for (int i = 1; i <= N; ++i) {
		std::cin >> A[i];
		S[i] = A[i] + S[i - 1];
	}
	std::cin >> K;

	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j <= 3; ++j) {
			D[i][j] = S[i] - S[0];
		}
	}

	for (int i = K + 1; i <= N; ++i) {
		for (int j = 1; j <= 3; ++j) {
			D[i][j] = std::max(D[i - 1][j], D[i - K][j - 1] + S[i] - S[i - K]);
		}
	}

	std::cout << D[N][3];

	return 0;
}