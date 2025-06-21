#include <iostream>
#include <queue>
#include <vector>

#define MAX 32000

int inDegree[MAX+1];
std::vector<std::vector<int>> graph(MAX+1);

int main()
{
	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		inDegree[v]+=1;
	}

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i]==0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int u = pq.top();
		pq.pop();

		std::cout << u << ' ';

		for (int v : graph[u]) {
			inDegree[v] -= 1;
			if (inDegree[v] == 0) {
				pq.push(v);
			}
		}	
	}

	std::cout << std::endl;

	return 0;
}
