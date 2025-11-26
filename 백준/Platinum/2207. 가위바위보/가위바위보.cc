#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int>> g(20001);
std::vector<std::vector<int>> g_t(20001);
std::vector<bool> v(20001);
std::vector<int> scc(20001);

void dfs1(int node, std::stack<int> &s) {
	v[node] = true;
	for (int adj : g[node]) {
		if (!v[adj]) {
			dfs1(adj, s);
		}
	}
	s.push(node);
}

void dfs2(int node, int sccIndex) {
	v[node] = true;
	scc[node] = sccIndex;
	for (int adj : g_t[node]) {
		if (!v[adj]) {
			dfs2(adj, sccIndex);
		}
	}
}

int main() {
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int n, m;

	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)	{
		int x, y;
		std::cin >> x >> y;
		g[-x + m].push_back(y + m);
		g[-y + m].push_back(x + m);

		g_t[y + m].push_back(-x + m);
		g_t[x + m].push_back(-y + m);
	}

	std::stack<int> s;
	for (int i = 0; i <= 2 * m; ++i) {
		if (!v[i]) {
			dfs1(i, s);
		}
	}

	int sccIndex = 0;
	std::fill(v.begin(), v.end(), false);
	while (!s.empty()) {
		int node = s.top();
		s.pop();
		if (!v[node]) {
			dfs2(node, sccIndex);
			sccIndex++;
		}
	}

	for (int i = 0; i < m; ++i) {
		int j = 2 * m - i;
		if (scc[i] == scc[j]) {
			std::cout << "OTL\n";
			return 0;
		}
	}

	std::cout << "^_^\n";

	return 0;
}