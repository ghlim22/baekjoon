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
			if (!(open[l] == s[i] || '?' == s[i])) {
				continue;
			}
			if (!(close[l] == s[k] || '?' == s[k])) {
				continue;
			}
			long long tmp = f(s, i + 1, k - 1) * f(s, k + 1, j);
			D[i][j] += tmp;
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
		printf("%05lld", D[0][N - 1] % M);
	}
	else {
		std::cout << D[0][N - 1];
	}
	return 0;
}
