#include <algorithm>
#include <cstring>
#include <iostream>

int M[101][101];
long D[101][101];

int main()
{
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			std::cin >> M[i][j];
	}

	D[1][1] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (D[i][j] == 0) {
				continue;
			}
			if (M[i][j] == 0) {
				continue;
			}
			int nextCol = j + M[i][j];
			int nextRow = i + M[i][j];
			if (nextCol <= N) {
				D[i][nextCol] += D[i][j];
			}
			if (nextRow <= N) {
				D[nextRow][j] += D[i][j];
			}
		}
	}
	std::cout << D[N][N];
	return 0;
}