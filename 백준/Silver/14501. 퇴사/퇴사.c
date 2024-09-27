#include <stdio.h>

#define MAX (1000)

int N;
int T[MAX];
int P[MAX];
int answer = 0;

void solve(int curr, int sum) {
	if (curr > N) {
		return;
	}

	if (answer < sum) {
		answer = sum;
	}

	if (curr == N) {
		return;
	}

	solve(curr + T[curr], sum + P[curr]);
	solve(curr + 1, sum);
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &T[i], &P[i]);
	}
	solve(0, 0);
	printf("%d", answer);
	return 0;
}