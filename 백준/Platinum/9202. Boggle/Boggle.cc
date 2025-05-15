#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

struct Node
{
	Node()
		: valid(false)
	{
		std::memset(children, -1, sizeof(children));
	}
	bool valid;
	int children[26];
};

typedef std::vector<Node> Trie;

char board[4][4];
bool visited[4][4];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
Trie trie;
int root;

int init(Trie &trie)
{
	Node x;
	trie.push_back(x);
	return trie.size() - 1;
}

int charToIndex(char c)
{
	return c - 'A';
}

void add(Trie &trie, int node, const std::string &s, int index)
{
	if (index == s.size())
	{
		trie[node].valid = true;
		return;
	}

	int c = charToIndex(s[index]);
	if (trie[node].children[c] == -1)
	{
		int next = init(trie);
		trie[node].children[c] = next;
	}
	int child = trie[node].children[c];
	add(trie, child, s, index + 1);
}

bool search(Trie &trie, int node, const std::string &s, int index)
{
	if (node == -1)
	{
		return false;
	}

	if (index == s.size())
	{
		return trie[node].valid;
	}

	int c = charToIndex(s[index]);
	int child = trie[node].children[c];

	return search(trie, child, s, index + 1);
}

void dfs(int y, int x, int depth, std::string &s, std::vector<std::string> &list)
{
	if (search(trie, root, s, 0))
		list.push_back(s);

	if (depth == 7)
		return;

	for (int i = 0; i < 8; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(ny >= 0 && ny < 4 && nx >= 0 && nx < 4))
			continue;
		if (visited[ny][nx])
			continue;

		visited[ny][nx] = true;
		s.push_back(board[ny][nx]);
		dfs(ny, nx, depth + 1, s, list);
		s.pop_back();
		visited[ny][nx] = false;
	}
}

void solve()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			std::cin >> board[i][j];
	}

	std::string s = "";
	std::vector<std::string> list;
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			visited[y][x] = true;
			s.push_back(board[y][x]);
			dfs(y, x, 0, s, list);
			s.pop_back();
			visited[y][x] = false;
		}
	}

	std::sort(list.begin(), list.end(), [](const auto &a, const auto &b)
			  {
		if (a.size() == b.size()) {
			return a > b;
		}
		return a.size() < b.size(); });

	auto it = std::unique(list.begin(), list.end());
	list.erase(it, list.end());

	std::string answer = list.back();
	int score = 0;
	for (const auto &s : list)
	{
		switch (s.size())
		{
		case 1:
		case 2:
			score += 0;
			break;
		case 3:
		case 4:
			score += 1;
			break;
		case 5:
			score += 2;
			break;
		case 6:
			score += 3;
			break;
		case 7:
			score += 5;
			break;
		case 8:
			score += 11;
			break;
		}
	}
	std::cout << score << ' ' << answer << ' ' << list.size() << '\n';
}

int main()
{
	int w;
	int b;

	root = init(trie);

	std::cin >> w;
	while (w--)
	{
		std::string s;
		std::cin >> s;
		add(trie, root, s, 0);
	}

	std::cin >> b;
	while (b--)
	{
		solve();
	}

	return 0;
}