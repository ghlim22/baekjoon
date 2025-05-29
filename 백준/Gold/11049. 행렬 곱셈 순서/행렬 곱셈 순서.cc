#include <algorithm>
#include <climits>
#include <iostream>

struct matrix
{
	int r;
	int c;
};

matrix M[500];
int D[500][500];

int f(int i, int j) 
{
	if (i == j) {
		return 0;
	}
	if (D[i][j] != 0) {
		return D[i][j];
	}

	D[i][j] = INT_MAX;
	for (int k = i; k < j; ++k) {
		int mul = f(i, k) + f(k + 1, j) + M[i].r * M[k].c * M[j].c;
		D[i][j] = std::min(D[i][j], mul);
	}

	return D[i][j];
}

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> M[i].r >> M[i].c;
	}
	std::cout << f(0, N - 1);
	return 0;
}