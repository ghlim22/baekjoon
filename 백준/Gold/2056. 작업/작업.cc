#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#define MAX 10000

int cache[MAX+1];
bool visited[MAX+1];
std::vector<int> graph[MAX+1];

int dfs(int u) 
{
	if (visited[u]) {
		return cache[u];
	}

	int cost = 0;
	for (int v : graph[u]) {
		cost = std::max(cost, dfs(v));	
	}
	cache[u] += cost;
	visited[u] = true;

	return cache[u];
}

int main()
{
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		int cost, m, v;
		std::cin >> cost >> m;
		cache[i] = cost;
		while (m--) {
			std::cin >> v;
			graph[i].push_back(v);
		}
	}

	int total = 0;
	for (int i = n; i > 0; --i) {
		if (!visited[i]) {
			total = std::max(total, dfs(i));
		}
	}

	std::cout << total << std::endl;

	return 0;
}
