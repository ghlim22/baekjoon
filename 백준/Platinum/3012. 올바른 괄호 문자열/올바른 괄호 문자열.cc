#include <cstdio>
#include <cstring>
#include <iostream>

long long D[200][200];

char open[3] = {
	'(',
	'{',
	'['
};

char close[3] = {
	')',
	'}',
	']'
};

int M = 100000;

long long f(const std::string& s, int i, int j)
{
	if (i > j) {
		return 1;
	}

	if (D[i][j] != -1) {
		return D[i][j];
	}

	D[i][j] = 0;
	for (int k = i + 1; k <= j; k += 2) {
		for (int l = 0; l < 3; ++l) {
			if (s[i] != open[l] && s[i] != '?')
				continue;
			if (s[k] != close[l] && s[k] != '?')
				continue;
			
			D[i][j] += f(s, i + 1, k - 1) * f(s, k + 1, j);
			if (D[i][j] >= M) {
				D[i][j] = M + D[i][j] % M;
			}
		}
	}

	return D[i][j];
}

int main()
{
	int N;
	std::string S;
	std::cin >> N >> S;
	std::memset(D, -1, sizeof(D));
	f(S, 0, N - 1);
	if (D[0][N - 1] >= M) {
		std::printf("%05lld\n", D[0][N - 1] % M);
	}
	else {
		std::cout << D[0][N - 1] << '\n';
	}

	return 0;
}