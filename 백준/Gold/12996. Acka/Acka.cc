#include <cstring>
#include <iostream>

int D[51][51][51][51];

int f(int index, int a, int b, int c)
{
	if (index == 0) {
		if (a == 0 && b == 0 && c == 0) {
			return 1;
		} else {
			return 0;
		}
	}

	if (a < 0 || b < 0 || c < 0) {
		return 0;
	}

	if (D[index][a][b][c] != -1) {
		return D[index][a][b][c];
	}

	int &sum = D[index][a][b][c];
	sum = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (i + j + k == 0) {
					continue;
				}
				sum += f(index - 1, a - i, b - j, c - k);
				sum %= 1000000007;
			}
		}
	}
	sum %= 1000000007;
	return sum;
}

int main()
{
	int N, a, b, c;
	std::memset(D, -1, sizeof(D));
	std::cin >> N >> a >> b >> c;
	std::cout << f(N, a, b, c);
	return 0;
}