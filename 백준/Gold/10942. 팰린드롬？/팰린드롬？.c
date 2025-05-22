#include <stdio.h>
#include <string.h>

int A[2000];
int D[2000][2000];

int solve(int i, int j)
{
	if (D[i][j] != -1) {
		return D[i][j];
	}

	if (i == j) {
		return D[i][j] = 1;
	} 
	else if (i + 1 == j) {
		return D[i][j] = (A[i] == A[j] ? 1 : 0);
	} 
	else if (A[i] == A[j]) {
		return D[i][j] = solve(i + 1, j - 1);
	} 
	else {
		return D[i][j] = 0;
	}
}

int main()
{
	int N, M, x, y;
	
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}
	
	memset(D, -1, sizeof(D));

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &x, &y);
		printf("%d\n", solve(x - 1, y - 1));
	}

	return 0;
}