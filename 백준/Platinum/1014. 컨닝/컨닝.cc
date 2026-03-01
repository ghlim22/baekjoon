#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int c, n, m;
bool map[10][10];
int match[2][50];
bool adjAB[50][50];
bool visitedA[50];
int sizeA, sizeB, total;

int ind(int row, int col) {
	return (col / 2) * n + row;
}

void buildGraph() {
	for (int col = 0; col < m - 1; ++col) {
		for (int row = 0; row < n; ++row) {
			if (!map[row][col]) continue;
			int set = col % 2;
			int u = ind(row, col);
			pair<int, int> end[3] = {{row - 1, col + 1}, {row, col + 1}, {row + 1, col + 1}};
			for (int i = 0; i < 3; ++i) {
				int r = end[i].first;
				int c = end[i].second;
				if (r < 0 || r >= n) continue;
				if (!map[r][c]) continue;

				int v = ind(r, c);
				if (!set) {
					adjAB[u][v] = true;
				} else {
					adjAB[v][u] = true;
				}
			}
		}
	}
}

bool dfs(int nodeA) {
	if (visitedA[nodeA]) {
		return false;
	}
	visitedA[nodeA] = true;
	for (int nodeB = 0; nodeB < sizeB; ++nodeB) {
		if (!adjAB[nodeA][nodeB]) continue;
		if (match[1][nodeB] == -1 || dfs(match[1][nodeB])) {
			match[0][nodeA] = nodeB;
			match[1][nodeB] = nodeA;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> c;
	while (c--)
	{
		memset(map, 0, sizeof(map));
		memset(match, -1, sizeof(match));
		memset(adjAB, 0, sizeof(adjAB));

		cin >> n >> m;
		sizeA = (m + 1) / 2 * n;
		sizeB = m / 2 * n;
		total = 0;

		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			for (int j = 0; j < m; ++j)
			{
				if (s[j] == '.') {
					map[i][j] = true;
					++total;
				}
			}
		}

		buildGraph();

		int matched = 0;
		for (int nodeA = 0; nodeA < sizeA; ++nodeA) {
			memset(visitedA, 0, sizeof(visitedA));
			if (dfs(nodeA)) {
				++matched;
			}
		}

		cout << total - matched << endl;
	}

	return 0;
}
