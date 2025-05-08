#include <iostream>
#include <vector>

struct Node
{
	Node()
	{
		children[0] = -1;
		children[1] = -1;
	}
	int children[2];
};

int init(std::vector<Node> &trie)
{
	Node x;
	trie.push_back(x);
	return trie.size() - 1;
}

void add(std::vector<Node> &trie, int node, int num, int index)
{
	if (index == -1)
		return;

	int b = (num >> index) & 1;
	if (trie[node].children[b] == -1) {
		int next = init(trie);
		trie[node].children[b] = next;
	}
	int child = trie[node].children[b];
	add(trie, child, num, index - 1);
}

int find(std::vector<Node> &trie, int node, int num, int index)
{
	if (node == -1 || index == -1)
		return 0;

	int b = (num >> index) & 1;
	int ret = 0;
	int child;
	if (trie[node].children[b ^ 1] != -1) {
		ret = (1 << index);
		child = trie[node].children[b ^ 1];
	} else {
		child = trie[node].children[b];
	}
	return ret | find(trie, child, num, index - 1);
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<Node> trie;
	int root = init(trie);

	int maxValue = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		std::cin >> num;
		int val = find(trie, root, num, 31);
		if (maxValue < val)
			maxValue = val;
		add(trie, root, num, 31);
	}
	std::cout << maxValue;

	return 0;
}
