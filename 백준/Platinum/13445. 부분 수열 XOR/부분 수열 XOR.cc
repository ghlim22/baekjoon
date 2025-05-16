#include <iostream>
#include <vector>

struct Node
{
	Node()
		: count(0)
	{
		children[0] = -1;
		children[1] = -1;
	}
	int children[2];
	long count;
};

typedef std::vector<Node> Trie;

int init(Trie& trie) 
{
	Node x;
	trie.push_back(x);
	return trie.size() - 1;
}

void add(Trie& trie, int node, int num, int index)
{
	if (index == -1) {
		return;
	}
	int bit = (num >> index) & 1;
	if (trie[node].children[bit] == -1) {
		int next = init(trie);
		trie[node].children[bit] = next;
	}
	int child = trie[node].children[bit];
	trie[child].count += 1;
	add(trie, child, num, index - 1);
}

long doXOR(Trie &trie, int node, int num, int index, int k)
{
	if (index == -1) {
		return 0;
	}
	if (trie[node].children[0] == -1 && trie[node].children[1] == -1) {
		return 0;
	}

	int numbit = (num >> index) & 1;
	int kbit = (k >> index) & 1;
	long result = 0;
	for (int i = 0; i < 2; ++i) {
		int child = trie[node].children[i];
		if (child == -1) {
			continue;
		}
		int xorbit = i ^ numbit;
		if (xorbit < kbit) {
			result += trie[child].count;
		}
		else if (xorbit == kbit) {
			result += doXOR(trie, child, num, index - 1, k);
		}
	}

	return result;
}

int main()
{
	int N;
	int K;
	int elem;

	std::cin >> N >> K;
	
	Trie trie;
	int root = init(trie);
	add(trie, root, 0, 20);

	int xorsum = 0;
	long count = 0;
	for (int i = 0; i < N; ++i) {
		std::cin >> elem;
		xorsum ^= elem;
		count += doXOR(trie, root, xorsum, 20, K);
		add(trie, root, xorsum, 20);
	} 

	std::cout << count;

	return 0;
}