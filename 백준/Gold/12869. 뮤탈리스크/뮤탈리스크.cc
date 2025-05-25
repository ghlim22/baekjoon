
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

int D[61][61][61];

int f(int a, int b, int c)
{
	if (D[a][b][c] != -1) {
		return D[a][b][c];
	}

	if (a == 0 && b == 0 && c == 0) {
		return 0;
	}

	int cnt = 61;
	std::vector<int> v = { 1, 3, 9 };
	do {
		int na = std::max(0, a - v[0]);
		int nb = std::max(0, b - v[1]);
		int nc = std::max(0, c - v[2]);
		cnt = std::min(cnt, f(na, nb, nc));
	} while (std::next_permutation(v.begin(), v.end()));

	D[a][b][c] = cnt + 1;
	return D[a][b][c];
}

int main()
{
	int N;
	std::cin >> N;

	int num[3] = { 0,0,0 };
	for (int i = 0; i < N; ++i)
		std::cin >> num[i];

	std::memset(D, -1, sizeof(D));
	std::cout << f(num[0], num[1], num[2]);

	return 0;
}