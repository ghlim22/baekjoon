#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <algorithm>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

#define LIMIT 5000

typedef std::pair<int, int> pii_t;

std::vector<int> G[LIMIT * 2 + 1];
std::vector<int> G_T[LIMIT * 2 + 1];
std::vector<bool> V(LIMIT * 2 + 1);
std::vector<int> SCC(LIMIT * 2 + 1);

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
	SCC[node] = sccIndex;
	for (int adj : G_T[node]) {
		if (!V[adj]) {
			dfs2(adj, sccIndex);
		}
	}
}

int main(void) {
  fastio;
  int k, n;
  std::cin >> k >> n;
  while (n--) {
	std::vector<int> choices;
	for (int i = 0; i < 3; ++i) {
		int lamp;
		char color;
		std::cin >> lamp >> color;
		if (color == 'B') {
			lamp = -lamp;
		}
		choices.push_back(lamp + k);
	}

	for (int i = 0; i < 3; ++i) {
		int from = 2 * k - choices[i];
		for (int j = 0; j < 3; ++j) {
			if (i == j) continue;	
			int to = choices[j];
			G[from].push_back(to);
			G_T[to].push_back(from);
		}
	}
  }

  std::stack<int> s;
  for (int i = 0; i <= 2 * k; ++i) {
	if (!V[i] && i != k) {
		dfs1(i, s);
	}
  }

  std::fill(V.begin(), V.end(), false);
  int sccIndex = 0;
  while (!s.empty()) {
	int node = s.top();
	s.pop();
	if (!V[node]) {
		dfs2(node, sccIndex);
		sccIndex++;
	}
  }

  for (int i = 0; i < k; ++i) {
	int j = 2 * k - i;
	if (SCC[i]==SCC[j]) {
		std::cout<<"-1\n";
		return 0;
	}
  }

  for (int i = k + 1; i <= 2 * k; ++i) {
	int j = 2 * k - i;
	if (SCC[i] < SCC[j]) {
		std::cout << 'B';
	} else {
		std::cout << 'R';
	}
  }
  std::cout << '\n';

  return 0;
}