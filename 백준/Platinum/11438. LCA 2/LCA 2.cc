#include <algorithm>
#include <iostream>
#include <vector>

#define LMT (100000)

using namespace std;

int n, m;
std::vector<int> tree[LMT+1];
int table[18][LMT+1];
int depth[LMT+1];

void dfs(int prev, int current, int dep) {
	depth[current] = dep;
	table[0][current] = prev;
	for (int child : tree[current]) {
		if (child != prev) {
			dfs(current, child, dep + 1);
		}
	}
}

void buildTable() {
	for (int k = 1; k < 18; ++k) {
		for (int i = 1; i <= n; ++i) {
			int midNode = table[k - 1][i];
			int dest = table[k - 1][midNode];
			table[k][i] = dest;
		}
	}
}

void solve(int a, int b) {
	if (depth[a] > depth[b]) {
		swap(a, b);
	}
	int diff = depth[b] - depth[a];
	for (int i = 0; i < 18; ++i) {
		if ((diff >> i) & 1) {
			b = table[i][b];
		}
	}

	for (int k = 17; k >= 0; --k) {
		if (table[k][a] != table[k][b])	{
			a = table[k][a];
			b = table[k][b];
		}
	}

	if (a == b) {
		std::cout << a << '\n';
	} else {
		std::cout << table[0][a] << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::ios_base::sync_with_stdio(false);

	std::cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		std::cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, 1, 0);
	buildTable();
	
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		solve(a, b);
	}

	return 0;
}