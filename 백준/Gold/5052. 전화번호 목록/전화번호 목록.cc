
#include <iostream>
#include <cstring>
#include <vector>

struct Node 
{
	Node()
		: valid(false)
	{
		std::memset(children, -1, sizeof(children));
	}
	bool valid;
	int children[10];
};

typedef std::vector<Node> Trie;

int init(Trie& trie)
{
	Node x;
	trie.push_back(x);
	return trie.size() - 1;
}

bool add(Trie& trie, int node, const std::string& s, int index)
{
	if (index == s.size()) {
		for (int i = 0; i < 10; ++i) {
			if (trie[node].children[i] != -1) {
				return false;
			}
		}
		trie[node].valid = true;
		return true;
	}

	if (trie[node].valid) {
		return false;
	}

	int c = s[index] - '0';
	if (trie[node].children[c] == -1) {
		int next = init(trie);
		trie[node].children[c] = next;
	}
	int child = trie[node].children[c];
	return add(trie, child, s, index + 1);
}

int main()
{
	int T, N;
	std::string num;

	std::cin >> T;
	while (T--) {
		std::cin >> N;
		
		Trie trie;
		int root = init(trie);
		bool flag = true;
		while (N--) {
			std::cin >> num;
			if (!add(trie, root, num, 0)) {
				flag = false;
			}
		}
		if (flag) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}

	return 0;
}
