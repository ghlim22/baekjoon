#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>


void dfs1(const std::string &cur, std::map<std::string, std::vector<std::string>> &graph, std::map<std::string, bool> &visited, std::stack<std::string> &stk) {
	if (visited[cur]) {
		return;
	}
	visited[cur] = true;
	if (graph.find(cur) != graph.end()) {
		for (const auto &other : graph[cur]) {
			dfs1(other, graph, visited, stk);
		}
	}
	stk.push(cur);
}


void dfs2(const std::string &cur, std::map<std::string, std::vector<std::string>> &graphT, std::map<std::string, int> &sccIndex, std::vector<std::string> &scc, int curSccIndex) {
	if (sccIndex.find(cur) != sccIndex.end()) {
		return;
	}
	sccIndex[cur] = curSccIndex;
	scc.push_back(cur);
	if (graphT.find(cur) != graphT.end()) {
		for (const auto &other : graphT[cur]) {
			dfs2(other, graphT, sccIndex, scc, curSccIndex);
		}
	}
}

int main() {
	std::map<std::string, std::vector<std::string>> graph;
	std::map<std::string, std::vector<std::string>> graphT;
	std::set<std::string> sites;
	int n;
	std::cin >> n;

	// construct graph and graphT
	for (int i = 0; i < n; ++i) {
		std::string site;
		int m;
		std::cin >> site >> m;
		sites.insert(site);
		while (m--) {
			std::string referrer;
			std::cin >> referrer;
			sites.insert(referrer);
			graph[referrer].push_back(site);
			graphT[site].push_back(referrer);
		}
	}

	std::map<std::string, bool> visited;
	std::stack<std::string> stk;

	for (auto &e : sites){
		if (!visited[e]) {
			dfs1(e, graph, visited, stk);
		}
	}

	std::map<std::string, int> sccIndex;
	std::vector<std::vector<std::string>> sccs;
	while (stk.size()) {
		const auto &cur = stk.top();
		if (sccIndex.find(cur) == sccIndex.end()) {
			std::vector<std::string> scc;
			dfs2(cur, graphT, sccIndex,scc , sccs.size());
			sccs.push_back(scc);
		}
		stk.pop();
	}

	std::map<std::string, long long> scores;
	for (auto &e : sites) {
		scores[e] = 1;
	}
	for (auto &scc : sccs) {
		for (auto &cur : scc) {
			if (graph.find(cur) == graph.end()) {
				continue;
			}
			for (auto &other : graph[cur]) {
				if (sccIndex[other] == sccIndex[cur]) {
					continue;
				}
				scores[other] += scores[cur];
			}
		}
	}

	std::string target;
	std::cin >> target;
	std::cout << scores[target];

	return 0;
}