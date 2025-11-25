#include <algorithm>
#include <iostream>
#include <utility>
#include <stack>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

std::vector<int> G[20001];
std::vector<int> G_T[20001];
std::vector<bool> V(20001);
std::vector<int> SCC_INDEX(20001);
int n, m;

void dfs1(int node, std::stack<int> &s) {
	V[node] = true;
	for (int adj : G[node]) {
		if (!V[adj]) {
			dfs1(adj, s);
		}
	}
	s.push(node);
}

void dfs2(int node, int sccIndex) {
	V[node] = true;
	SCC_INDEX[node] = sccIndex;
	for (int adj : G_T[node]) {
		if (!V[adj]) {
			dfs2(adj, sccIndex);
		}
	}
}

int main(void) {
  fastio;
  std::cin >> n >> m;
  while (m--) {
	int x, y;
	std::cin >> x >> y;
	G[-x + n].push_back(y + n);
	G[-y + n].push_back(x + n);
	G_T[y + n].push_back(-x + n);
	G_T[x + n].push_back(-y + n);
  }

  std::stack<int> S;
  for (int i = 0; i <= 2 * n; ++i) {
	if (!V[i] && i != n) {
		dfs1(i, S);
	}
  }

  int sccIndex = 0;
  std::fill(V.begin(), V.end(), false);
  while (!S.empty()) {
	int node = S.top();
	S.pop();
	if (!V[node]) {
		dfs2(node, sccIndex);
		sccIndex++;
	}
  }

  for (int i = 0; i < n; ++i) {
	if (SCC_INDEX[i] == SCC_INDEX[2 * n - i]) {
		std::cout << 0;
		return 0;
	}
  }

  std::cout << 1 << '\n';
  for (int i = n + 1; i <= 2 * n; ++i) {
	int j = 2 * n - i;
	if (SCC_INDEX[i] < SCC_INDEX[j]) {
		std::cout << 0 << ' ';
	} else {
		std::cout << 1 << ' ';
	}
  }
  std::cout << '\n';

  return 0;
}