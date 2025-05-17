#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

class AhoCorasick
{
public:
	AhoCorasick()
	{
		_root = init();
	}

	void Add(const std::string& s)
	{
		add(_root, s, 0);
	}

	void Construct()
	{
		_trie[_root].pi = _root;

		std::queue<int> q;
		q.push(_root);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			Node& curnode = _trie[cur];

			for (auto it = curnode.children.begin(); it != curnode.children.end(); ++it) {
				int child = it->second;
				if (cur == _root) {
					_trie[child].pi = _root;
				}
				else {
					char ch = it->first;
					int pi = curnode.pi;
					while (pi != _root && _trie[pi].children.count(ch) == 0) {
						pi = _trie[pi].pi;
					}
					if (_trie[pi].children.count(ch) > 0) {
						pi = _trie[pi].children[ch];
					}
					_trie[child].pi = pi;
					_trie[child].len = std::max(_trie[child].len, _trie[pi].len);
				}
				q.push(child);
			}
		}
	}

	int Solve(const std::string& s) 
	{
		std::vector<std::pair<int, int>> m;
		int n = s.size();
		int node = _root;

		for (int i = 0; i < n; ++i) {
			char ch = s[i];
			while (node != _root && _trie[node].children.count(ch) == 0) {
				node = _trie[node].pi;
			}
			if (_trie[node].children.count(ch) > 0) {
				node = _trie[node].children[ch];
			}
			if (_trie[node].len > 0) {
				m.push_back({ i - _trie[node].len + 1, 0 });
				m.push_back({ i, 1 });
			}
		}

		std::sort(m.begin(), m.end());
		int open = 0;
		int start;
		for (auto& p : m) {
			if (!p.second) {
				if (open == 0) {
					start = p.first;
				}
				open += 1;
			}
			else {
				open -= 1;
				if (open == 0) {
					n -= (p.first - start + 1);
				}
			}
		}

		return n;
	}

private:
	struct Node
	{
		Node()
			: len(0), pi(-1)
		{
		}
		std::map<char, int> children;
		int len;
		int pi;
	};

	int init()
	{
		Node x;
		_trie.push_back(x);
		return _trie.size() - 1;
	}

	void add(int node, const std::string& s, int index)
	{
		if (s.size() == index) {
			_trie[node].len = s.size();
			return;
		}

		char ch = s[index];
		if (_trie[node].children.count(ch) == 0) {
			int next = init();
			_trie[node].children.insert({ ch, next });
		}
		int child = _trie[node].children[ch];
		add(child, s, index + 1);
	}

	int _root;
	std::vector<Node> _trie;
};

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N;
	int M;
	std::string s;
	AhoCorasick ac;

	std::cin >> N;
	std::cin >> s;

	std::cin >> M;
	while (M--) {
		std::string tile;
		std::cin >> tile;
		
		ac.Add(tile);
	}

	ac.Construct();

	std::cout << ac.Solve(s);

	return 0;
}