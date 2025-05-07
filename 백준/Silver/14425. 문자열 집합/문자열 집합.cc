#include <cstring>
#include <iostream>
#include <vector>

struct Node
{
	Node ()
	: valid(false) {
		std::memset(children, -1, sizeof(children));
	}
	bool valid;
	int children[26];
};

int init(std::vector<Node> &trie)
{
	Node x;
	trie.push_back(x);
	return trie.size() - 1;
}

void add(std::vector<Node> &trie, int node, const std::string &s, int index)
{
	if (s.size() == index) {
		trie[node].valid = true;
		return;
	}

	int c = s[index] - 'a';
	if (trie[node].children[c] == -1) {
		int next = init(trie);
		trie[node].children[c] = next;
	}
	int child = trie[node].children[c];
	add(trie, child, s, index + 1);

	//
	// {
	// 	int &child = trie[node].children[c];
	// 	if (child == -1) {
	// 		child = init(trie);
	// 	}
	// 	add(trie, child, s, index + 1);
	// }
}

bool search(std::vector<Node> &trie, int node, const std::string &s, int index)
{
	if (node == -1) {
		return false;
	}
	if (index == s.size()) {
		return trie[node].valid;
	}

	int c = s[index] - 'a';
	int child = trie[node].children[c];
	return search(trie, child, s, index + 1);
}

int main()
{
	std::vector<Node> trie;
	int root = init(trie);

	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		add(trie, root, s, 0);
	}

	int count = 0;
	for (int i = 0; i < m; ++i) {
		std::string s;
		std::cin >> s;
		if (search(trie, root, s, 0)) {
			count++;
		}
	}
	std::cout << count << '\n';

	return 0;
}
