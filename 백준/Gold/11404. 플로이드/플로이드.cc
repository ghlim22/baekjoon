#include <stdio.h>
#include <string.h>

int min(int x, int y) {
	return (x < y) ? x : y;
}

int D[101][101];

int main() {
	int n, m, a, b, c;
	const int INF = 100000 * (100 - 1) + 1;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			D[i][j] = ((i == j) ? 0 : INF);
		}
	}
	
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		if (D[a][b] > c) {
			D[a][b] = c;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int cost = D[i][j];
			if (cost == INF)
				cost = 0;
			printf("%d ", cost);
		}
		printf("\n");
	}

	return 0;
}