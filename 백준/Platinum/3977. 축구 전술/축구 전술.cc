#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)
  
#define LIMIT 100000

typedef std::pair<int, int> pii_t;

std::vector<std::vector<int>> G;
std::vector<std::vector<int>> G_T;
std::vector<bool> V(LIMIT);

void dfs1(int node, std::stack<int> &s) {
	V[node] = true;
	for (int adj : G[node]) {
		if (!V[adj]) {
			dfs1(adj, s);
		}
	}
	s.push(node);
}

void dfs2(int node, std::vector<int> &scc) {
	scc.push_back(node);
	V[node] = true;
	for (int adj : G_T[node]) {
		if (!V[adj]) {
			dfs2(adj, scc);
		}
	}
}

int dfs3(int node) {
	int ret = 1;
	V[node] = true;
	for (int adj : G[node]) {
		if (!V[adj]) {
			ret += dfs3(adj);
		}
	}
	return ret;
}

int main(void) {
  fastio;
  int t;
  std::cin >> t;
  while (t--) {
	int n, m;
	std::cin >> n >> m;

	G=std::vector<std::vector<int>>(n);
	G_T=std::vector<std::vector<int>>(n);

	while (m--) {
		int a, b;
		std::cin >> a >> b;
		G[a].push_back(b);
		G_T[b].push_back(a);
	}

	std::stack<int> s;
	for (int i = 0; i < n; ++i) {
		if (!V[i]) {
			dfs1(i, s);
		}
	}

	std::fill(V.begin(), V.end(), false);
	std::vector<int> scc;
	dfs2(s.top(), scc);

	std::fill(V.begin(), V.end(), false);
	if (dfs3(s.top()) == n)	 {
		std::sort(scc.begin(), scc.end());
		for (int node : scc) {
			std::cout << node << '\n';
		}
	} else {
		std::cout << "Confused\n";
	}
	std::cout << "\n";
	
	std::fill(V.begin(), V.end(), false);
  }

  return 0;
}