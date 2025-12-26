#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> pii_t;
typedef map<string, set<string>> graph_t;

vector<string> split(const string &str) {
	vector<string> ret;
	for (size_t pos = 0, xpos = 0;;) {
		xpos = str.find(' ', pos);
		ret.push_back(str.substr(pos, xpos - pos));
		if (xpos == string::npos) {
			break;
		}
		pos = xpos + 1;
	}
	return ret;
}

void dfs1(const string &cur, graph_t &outLinks, set<std::string> &visited, stack<std::string> &stk) {
	if (visited.find(cur) != visited.end()) {
		return;
	}
	visited.insert(cur);
	for (auto &v : outLinks[cur]) {
		dfs1(v, outLinks, visited, stk);
	}
	stk.push(cur);
}

void dfs2(const string &cur, graph_t &inLinks, set<string> &visited, vector<string> &scc, map<string, int> &sccIndex, vector<vector<int>> &sccInlinks, int curSccNo) {
	if (visited.find(cur) != visited.end()) {
		return;
	}
	visited.insert(cur);
	scc.push_back(cur);
	sccIndex[cur] = curSccNo;
	for (const auto &v : inLinks[cur]) {
		if (visited.find(v) == visited.end()) {
			dfs2(v, inLinks, visited, scc, sccIndex, sccInlinks, curSccNo);
		} else if (sccIndex[v] != curSccNo && std::find(sccInlinks[curSccNo].begin(), sccInlinks[curSccNo].end(), sccIndex[v]) == sccInlinks[curSccNo].end()) {
			sccInlinks[curSccNo].push_back(sccIndex[v]);
		}
	}
}

void updateBase(int scc, vector<vector<int>> &sccInlinks, vector<bool> &sccVisited, vector<int> &base) {
	if (sccVisited[scc]) {
		return;
	}
	sccVisited[scc] = true;
	base.push_back(scc);
	for (int par : sccInlinks[scc]) {
		updateBase(par, sccInlinks, sccVisited, base);
	}
}

int main(void) {
  int n;
  while (cin >> n && n > 0) {
	cin >> ws;
	graph_t inLinks;
	graph_t outLinks;
	for (int i = 0; i < n; ++i) {
		string line;
		cin >> ws;
		getline(cin, line);
		auto words = split(line);
		string &w = words[0];
		for (int i = 1; i < words.size(); ++i) {
			outLinks[words[i]].insert(w);
			inLinks[w].insert(words[i]);
		}
	}

	set<string> visited;
	stack<string> stk;
	for (auto &[key, val] : inLinks) {
		dfs1(key, outLinks, visited, stk);
	}

	visited.clear();
	vector<vector<string>> sccs;
	vector<vector<int>> sccInlinks;
	map<string, int> sccIndex;
	while (stk.size()) {
		const auto &cur = stk.top();
		if (visited.find(cur) == visited.end()) {
			sccInlinks.push_back(vector<int>());
			vector<string> scc;
			dfs2(cur, inLinks, visited, scc, sccIndex, sccInlinks, sccs.size());
			sccs.push_back(scc);
		}
		stk.pop();
	}

	vector<int> base;
	vector<bool> sccVisited(sccs.size());
	for (int i = 0; i < sccs.size(); ++i) {
		if (sccVisited[i]) {
			continue;
		}
		if (sccs[i].size() > 1 || sccInlinks[i].size() == 0) {
			updateBase(i, sccInlinks, sccVisited, base);
		}
	}

	vector<string> baseWords;
	for (int scc : base) {
		for (const auto &word : sccs[scc]) {
			baseWords.push_back(word);
		}
	}
	sort(baseWords.begin(), baseWords.end());
	cout << baseWords.size() << '\n';
	for (const auto &word : baseWords) {
		cout << word << ' ';
	}
	cout << '\n';
  }

  return 0;
}