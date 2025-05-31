#include <iostream>

char answer[31];
bool D[31][30][30][500];
int N, K;

bool f(int i, int a, int b, int p)
{
	if (i == N) {
		if (p == K) {
			return true;
		} else {
			return false;
		}
	}

	if (D[i][a][b][p]) {
		return false;
	}

	D[i][a][b][p] = true;

	answer[i] = 'A';
	if (f(i + 1, a + 1, b, p)) {
		return true;
	}

	answer[i] = 'B';
	if (f(i + 1, a, b + 1, p + a)) {
		return true;
	}

	answer[i] = 'C';
	if (f(i + 1, a, b, p + a + b)) {
		return true;
	}

	return false;
}

int main()
{
	std::cin >> N >> K;
	if (f(0, 0, 0, 0)) {
		std::cout << answer;
	} else {
		std::cout << -1;
	}
	return 0;
}