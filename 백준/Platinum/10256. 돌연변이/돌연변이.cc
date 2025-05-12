#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

struct Node
{
	Node()
	: valid(false), pi(-1)
	{
		for (int i = 0; i < 4; ++i) {
			children[i] = -1;
		}
	}

	bool valid;
	int pi;
	int children[4];
};

typedef std::vector<Node> Trie;

int charToIndex(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
	case 'G':
		return 1;
	case 'T':
		return 2;
	case 'C':
		return 3;
	default:
		return -1;
	}
}

int init(Trie &trie)
{
	Node x;
	trie.push_back(x);
	return trie.size() - 1;
}

void add(Trie &trie, int node, const std::string &s, int index)
{
	if (index == s.size()) {
		trie[node].valid = true;
		return;
	}

	int c = charToIndex(s[index]);
	if (trie[node].children[c] == -1) {
		int next = init(trie);
		trie[node].children[c] = next;
	}
	int child = trie[node].children[c];
	add(trie, child, s, index + 1);
}

void linkSuffix(Trie &trie, int root)
{
	trie[root].pi = root;
	std::queue<int> q;
	q.push(root);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int child = trie[cur].children[i];
			if (child == -1) {
				continue;
			}

			if (cur == root) {
				trie[child].pi = root;
			} else {
				int pi = trie[cur].pi;
				while (pi != root && trie[pi].children[i] == -1) {
					pi = trie[pi].pi;
				}
				if (trie[pi].children[i] != -1) {
					pi = trie[pi].children[i];
				}
				trie[child].pi = pi;
				trie[child].valid |= trie[pi].valid;
			}
			q.push(child);
		}
	}
}

int main()
{
	fastio;

	int t, n, m;
	std::string dna, marker;

	std::cin >> t;

	while (t--) {
		std::cin >> n >> m;
		std::cin >> dna >> marker;

		Trie trie;
		int root = init(trie);
		
		add(trie, root, marker, 0);
		for (int len = 2; len <= m; ++len) {
			for (int i = 0; i <= m - len; ++i) {
				std::string s = marker;
				std::reverse(s.begin() + i, s.begin() + i + len);
				add(trie, root, s, 0);
			}
		}
		linkSuffix(trie, root);

		int node = root;
		int count = 0;
		for (int i = 0; i < n; ++i) {
			int c = charToIndex(dna[i]);
			while (node != root && trie[node].children[c] == -1) {
				node = trie[node].pi;
			}
			if (trie[node].children[c] != -1) {
				node = trie[node].children[c];
			}
			if (trie[node].valid) {
				count++;
			}
		}

		std::cout << count << '\n';
	}

	return 0;
}