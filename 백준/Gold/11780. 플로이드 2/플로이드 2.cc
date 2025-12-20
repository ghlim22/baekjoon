#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

int d[101][101];
int path[101][101];

void printPathRecursive(std::queue<int> &q, int i, int j) {
	if (path[i][j]) {
		int k = path[i][j];
		printPathRecursive(q, i, k);
		q.push(k);
		printPathRecursive(q, k, j);
	}

}

void printPath(int i, int j) {
	std::queue<int> q;
	q.push(i);
	printPathRecursive(q, i, j);
	q.push(j);

	std::cout << q.size() << ' ';
	while (q.size()) {
		std::cout << q.front() << ' ';
		q.pop();
	}
}

int main() {
	int n, m, a, b, c;
	const int INF = 100 * (100000 - 1) + 1;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			d[i][j] = ((i == j) ? 0 : INF);
		}
	}

	std::cin >> n >> m;

	while (m--) {
		std::cin >> a >> b >> c;
		if (d[a][b] > c) {
			d[a][b] = c;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int nd = d[i][k] + d[k][j];
				if (nd < d[i][j]) {
					d[i][j] = nd;
					path[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == INF) {
				d[i][j] = 0;
			}
			std::cout << d[i][j] << ' ';
		}
		std::cout << '\n';
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j]) {
				printPath(i, j);
			} else {
				std::cout << 0;
			}
			std::cout << '\n';
		}
	}
	
	return 0;
}