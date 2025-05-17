
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

class Solution
{
public:
	Solution(int hp, int wp, int hm, int wm)
		: _hp(hp), _wp(wp), _hm(hm), _wm(wm)
	{
		_root = init();
		_row_num = 0;
	}

	void AddRow(const std::vector<bool>& s)
	{
		int searched = search_row(_root, s, 0);
		if (searched != -1) {
			_row_pattern.push_back(searched);
		}
		else {
			add(_root, s, 0, _row_num);
			_row_pattern.push_back(_row_num);
			_row_num += 1;
		}
	}

	void Construct()
	{
		_trie[_root].pi = _root;
		std::queue<int> q;
		q.push(_root);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < 2; ++i) {
				int child = _trie[cur].children[i];
				if (child == -1) {
					continue;
				}
				
				if (cur == _root) {
					_trie[child].pi = _root;
				}
				else {
					int pi = _trie[cur].pi;
					while (pi != _root && _trie[pi].children[i] == -1) {
						pi = _trie[pi].pi;
					}
					if (_trie[pi].children[i] != -1) {
						pi = _trie[pi].children[i];
					}
					_trie[child].pi = pi;
				}

				q.push(child);
			}
		} 
	}

	void AhoCorasickSearch(const std::vector<bool>& s, int row)
	{
		int node = _root;
		for (int i = 0; i < _wm; ++i) {
			int index = boolToIndex(s[i]);
			while (node != _root && _trie[node].children[index] == -1) {
				node = _trie[node].pi;
			}
			int child = _trie[node].children[index];
			if (child == -1) {
				continue;
			}
			else {
				node = child;
				if (_trie[node].num != -1) {
					_paint_row_num[row][i] = _trie[node].num;
				}
			}
		}
	}

	void AnalyzeRowPattern(const std::vector<std::vector<bool>>& m)
	{
		for (int i = 0; i < _hm; ++i) {
			_paint_row_num.push_back(std::vector<int>(_wm, -1));
			AhoCorasickSearch(m[i], i);
		}
	}

	int KMPSearchRowPattern()
	{
		std::vector<int> fail(_hp);
		fail[0] = 0;
		int j = 0;
		for (int i = 1; i < _hp; ++i) {
			while (j > 0 && _row_pattern[i] != _row_pattern[j]) {
				j = fail[j - 1];
			}
			if (_row_pattern[i] == _row_pattern[j]) {
				fail[i] = j + 1;
				j += 1;
			}
			else {
				fail[i] = 0;
			}
		}

		int count = 0;
		for (int col = 0; col < _wm; ++col) {
			j = 0;
			for (int row = 0; row < _hm; ++row) {
				while (j != 0 && _paint_row_num[row][col] != _row_pattern[j]) {
					j = fail[j - 1];
				}
				if (_row_pattern[j] == _paint_row_num[row][col]) {
					j += 1;
					if (j == _hp) {
						count += 1;
						j = fail[j - 1];
					}
				}
			}
		}

		return count;
	}

private:
	struct Node
	{
		Node()
			: pi(-1), num(-1)
		{
			children[0] = -1;
			children[1] = -1;
		}
		int children[2];
		int pi;
		int num;
	};

	int init()
	{
		Node x;
		_trie.push_back(x);
		return (int)_trie.size() - 1;
	}

	void add(int node, const std::vector<bool>& s, int index, int row_num)
	{
		if (s.size() == index) {
			_trie[node].num = row_num;
			return;
		}

		int i = boolToIndex(s[index]);
		if (_trie[node].children[i] == -1) {
			int next = init();
			_trie[node].children[i] = next;
		}
		int child = _trie[node].children[i];
		add(child, s, index + 1, row_num);
	}

	int search_row(int node, const std::vector<bool>& s, int index)
	{
		if (node == -1) {
			return -1;
		}
		if (index == s.size()) {
			return _trie[node].num;
		}
		int i = boolToIndex(s[index]);
		int child = _trie[node].children[i];
		return search_row(child, s, index + 1);
	}

	//bool search(int node, const std::string& s, int index)
	//{
	//	if (node == -1) {
	//		return false;
	//	}
	//	if (index == s.size()) {
	//		return true;
	//	}
	//	int i = boolToIndex(s[index]);
	//	int child = _trie[node].children[i];
	//	return search(child, s, index + 1);
	//}

	int boolToIndex(bool b)
	{
		if (b)
			return 1;
		else
			return 0;
	}

	int _root;
	int _row_num;
	int _hp;
	int _wp;
	int _hm;
	int _wm;
	std::vector<Node> _trie;
	std::vector<int> _row_pattern;
	std::vector<std::vector<int>> _paint_row_num;
};

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int hp, wp, hm, wm;
	std::cin >> hp >> wp >> hm >> wm;

	std::vector<std::vector<bool>> p(hp, std::vector<bool>(wp));
	std::vector<std::vector<bool>> m(hm, std::vector<bool>(wm));

	for (int i = 0; i < hp; ++i) {
		std::string s;
		std::cin >> s;
		for (int j = 0; j < wp; ++j) {
			if (s[j] == 'o')
				p[i][j] = true;
		}
	}

	for (int i = 0; i < hm; ++i) {
		std::string s;
		std::cin >> s;
		for (int j = 0; j < wm; ++j) {
			if (s[j] == 'o')
				m[i][j] = true;
		}
	}

	Solution sol(hp, wp, hm, wm);
	for (int i = 0; i < hp; ++i) {
		sol.AddRow(p[i]);
	}
	sol.Construct();
	sol.AnalyzeRowPattern(m);
	int result = sol.KMPSearchRowPattern();
	std::cout << result;

	return 0;
}
