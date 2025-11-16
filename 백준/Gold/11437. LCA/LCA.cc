#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

#define LMT (50000)
#define LOG2_LMT (16)

int table[LOG2_LMT + 1][LMT + 1];
int depths[LMT + 1];
std::vector<int> graph[LMT + 1];
int N;

void dfs(int prev, int current, int dep) {
	depths[current] = dep;
	table[0][current] = prev;
	for (int child : graph[current]) {
		if (child != prev) {
			dfs(current, child, dep + 1);
		}
	}
}

int LCS(int x, int y) {
	if (depths[x] > depths[y]) {
		std::swap(x, y);
	}

	int diff = depths[y] - depths[x];
	for (int k = 0; diff > 0; ++k) {
		if (diff & 1) {
			y = table[k][y];
		}
		diff >>= 1;
	}

	if (x == y) {
		return x;
	}

	for (int k = LOG2_LMT; k >= 0; --k) {
		if (table[k][x] != table[k][y]) {
			x = table[k][x];
			y = table[k][y];
		}
	}

	return table[0][x];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	dfs(1, 1, 0);
	for (int k = 1; k <= LOG2_LMT; ++k) {
		for (int i = 1; i <= N; ++i) {
			int j = table[k - 1][i];
			table[k][i] = table[k - 1][j];
		}
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", LCS(x, y));
	}
	
	return 0;
}