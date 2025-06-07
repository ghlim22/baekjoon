#include <cstring>
#include <iostream>

int D[5001][5001];
int S[10];
int N, M, T;

void f(int i, int j)
{
	if (i > N) {
		return;
	}

	if (j > N) {
		return;
	}

	if (D[i][j]) {
		return;
	}

	D[i][j] = 1;
	
	for (int k = 0; k < M; ++k) {
		int s = S[k];
		f(i + j + s, j + s);
	}
}

int main()
{
	std::cin >> T;
	while (T--) {
		std::memset(D, 0, sizeof(D));

		std::cin >> N >> M;
		for (int i = 0; i < M; ++i) {
			std::cin >> S[i];
		}

		f(0, 0);
		int answer = -1;
		for (int i = 5000; i >= 0; --i) {
			if (D[N][i]) {
				answer = i;
				break;
			}
		}
		std::cout << answer << '\n';
	}
		
	return 0;
}