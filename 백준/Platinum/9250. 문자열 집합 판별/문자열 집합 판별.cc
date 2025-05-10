#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

/* Aho-Corasick Algorithm */

struct Node
{
	Node()
	: valid(false), suffixLink(-1)
	{
		std::memset(children, -1, sizeof(children));
	}
	bool valid;
	int children[26];
	int suffixLink;
};

typedef std::vector<Node> Trie;

int init(Trie &t)
{
	Node x;
	t.push_back(x);
	return t.size() - 1;
}

void add(Trie &t, int node, const std::string &s, int index)
{
	if (index == s.size()) {
		t[node].valid = true;
		return;
	}

	int c = s[index] - 'a';
	if (-1 == t[node].children[c]) {
		int next = init(t);
		t[node].children[c] = next;
	}
	int child = t[node].children[c];
	add(t, child, s, index + 1);
}

void findLongestSuffix(Trie &t, int root)
{
	t[root].suffixLink = root;
	std::queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < 26; ++i) {
			int child = t[current].children[i];
			if (child == -1) {
				continue;
			}

			if (current == root) {
				t[child].suffixLink = root;
			} else {
				int pi = t[current].suffixLink;
				while (pi != root && t[pi].children[i] == -1) {
					pi = t[pi].suffixLink;
				}
				if (t[pi].children[i] != -1) {
					pi = t[pi].children[i];
				}
				t[child].suffixLink = pi; /* failure link */
				t[child].valid |= t[pi].valid; /* dictionary link */
			}

			q.push(child);
		}
	}
}

bool match(Trie &t, int root, const std::string &s)
{
	int node = root;
	for (char c : s) {
		c -= 'a';
		while (node != root && t[node].children[c] == -1) {
			node = t[node].suffixLink;
		}
		if (t[node].children[c] != -1) {
			node = t[node].children[c];
		}
		if (t[node].valid) {
			return true;
		}
	}
	return false;
}

int main()
{
	Trie t;
	int root = init(t);

	int n;
	std::cin >> n;

	while (n--) {
		std::string s;
		std::cin >> s;
		add(t, root, s, 0);
	}

	findLongestSuffix(t, root);

	int q;
	std::cin >> q;
	while (q--) {
		std::string s;
		std::cin >> s;
		if (match(t, root, s)) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}

	return 0;
}
