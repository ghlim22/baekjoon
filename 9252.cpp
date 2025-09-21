#include <algorithm>
#include <iostream>

int len[1001][1001];
std::string a, b;
int m, n;

std::string backtrack(int i, int j) {
	if (i == 0 || j == 0) {
		return "";
	}

	if (a[i] == b[j]) {
		return backtrack(i - 1, j - 1) + a[i];
	} else if (len[i - 1][j] > len[i][j - 1]) {
		return backtrack(i - 1, j);
	} else {
		return backtrack(i, j - 1);
	}
}

int main() {
	std::cin >> a >> b;
	m = a.size();
	n = b.size();
	a = ' ' + a; // a <- ' ' + a[0] + a[1] + a[2] + ... + a[m - 1]
	b = ' ' + b; 
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i] == b[j]) {
				len[i][j] = len[i - 1][j - 1] + 1;
			} else {
				len[i][j] = std::max(len[i - 1][j], len[i][j - 1]);
			}
		}
	}

	std::cout << len[m][n] << '\n';
	std::cout << backtrack(m, n) << '\n';

	return 0;
}