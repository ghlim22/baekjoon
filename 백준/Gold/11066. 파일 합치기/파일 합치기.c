#include <stdio.h>
#include <string.h>
#include <limits.h>

int F[501];
int C[501][501];

int cal(int i, int j)
{
	if (i == j) {
		return 0;
	}
	if (C[i][j] > 0) {
		return C[i][j];
	}

	int min_cost = INT_MAX;
	for (int k = i; k < j; ++k) {
		int cost = cal(i, k) + cal(k + 1, j) + F[j] - F[i - 1];
		if (cost < min_cost) {
			min_cost = cost;
		}
	}
	return C[i][j] = min_cost;
}

int main()
{
	int T, K;

	scanf("%d", &T);
	while (T--) {
		memset(C, 0, sizeof(C));
		scanf("%d", &K);
		for (int i = 1; i <= K; ++i) {
			int size;
			scanf("%d", &size);
			F[i] = F[i - 1] + size;
		}
		printf("%d\n", cal(1, K));
	}

	return 0;
}