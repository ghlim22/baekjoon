#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

struct Node
{
	Node()
		: valid(false), dictionaryLink(-1), suffixLink(-1), len(0)
	{
		std::memset(children, -1, sizeof(children));
	}
	bool valid;
	int dictionaryLink;
	int suffixLink;
	int len;
	int children[26];
};

typedef std::vector<Node> Trie;

int init(Trie& trie)
{
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

void add(Trie& trie, int node, const std::string& word, int index)
{
	if (index == word.size()) {
		trie[node].valid = true;
		return;
	}

	int i = word[index] - 'a';
	if (trie[node].children[i] == -1) {
		int next = init(trie);
		trie[node].children[i] = next;
		trie[next].len = index + 1;
	}
	int child = trie[node].children[i];
	add(trie, child, word, index + 1);
}

void construct(Trie& trie, int root)
{
	std::queue<int> q;

	trie[root].suffixLink = root;
	q.push(root);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 26; ++i) {
			int child = trie[cur].children[i];
			if (child == -1) {
				continue;
			}

			if (cur == root) {
				trie[child].suffixLink = root;
			}
			else {
				/* suffix link */
				int pi = trie[cur].suffixLink;
				while (pi != root && trie[pi].children[i] == -1) {
					pi = trie[pi].suffixLink;
				}
				if (trie[pi].children[i] != -1) {
					pi = trie[pi].children[i];
				}
				trie[child].suffixLink = pi;

				/* dictionary link */
				while (pi != root && !trie[pi].valid && trie[pi].dictionaryLink == -1) {
					pi = trie[pi].suffixLink;
				}
				if (trie[pi].valid) {
					trie[child].dictionaryLink = pi;
				}
				else if (trie[pi].dictionaryLink != -1) {
					trie[child].dictionaryLink = trie[pi].dictionaryLink;
				}
			}
			q.push(child);
		}
	}
}

void solve(Trie& trie, int root, std::string& street, std::vector<std::pair<int, int>> &matches)
{
	int changedCount = 0;
	int node = root;
	for (int i = 0; i < street.size(); ++i) {
		int c = street[i] - 'a';
		while (node != root && trie[node].children[c] == -1) {
			node = trie[node].suffixLink;
		}
		if (trie[node].children[c] == -1) {
			continue;
		}

		node = trie[node].children[c];
		if (trie[node].valid) {
			matches.push_back({ i - trie[node].len + 1, i });
		}
		else {
			int dict = trie[node].dictionaryLink;
			if (dict == -1) {
				continue;
			}
			matches.push_back({ i - trie[dict].len + 1, i });
		}
	}
}

int main()
{
	int N;
	int M;
	std::string street;
	std::string tile;
	Trie trie;
	int root = init(trie);

	std::cin >> N;
	std::cin >> street;

	std::vector<std::pair<int, int>> matches;

	std::cin >> M;
	for (int i = 0; i < M; ++i) {
		std::cin >> tile;
		add(trie, root, tile, 0);
		if (i > 0 && i % 150 == 0) {
			construct(trie, root);
			solve(trie, root, street, matches);
			trie.clear();
			root = init(trie);
		}
	}

	if (trie.size() > 1) {
		construct(trie, root);
		solve(trie, root, street, matches);
	}

	std::sort(matches.begin(), matches.end(), [](const auto& a, const auto& b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
		});

	std::vector<bool> changed(N, false);
	int count = N;
	for (auto& p : matches) {
		int start = p.first;
		int end = p.second;
		for (int i = start; i <= end; ++i) {
			if (changed[i])
				break;
			changed[i] = true;
			count -= 1;
		}
		for (int i = end; i >= start; --i) {
			if (changed[i])
				break;
			changed[i] = true;
			count -= 1;
		}
	}
	std::cout << count;

	return 0;
}