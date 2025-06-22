#include <algorithm>
#include <iostream>
#include <queue>

#define MAX (10000)

struct edge
{
	int u;
	int v;
	int w;
	bool operator<(const edge& other) const 
	{
		return w > other.w;
	}
};

int parent[MAX + 1];
int rank[MAX + 1];

int find(int x) 
{
	if (parent[x] == x) {
		return x;
	}

	int root = find(parent[x]);
	parent[x] = root;
	return root;
}

void unionXY(int x, int y) 
{
	int rootX = find(x);
	int rootY = find(y);
	if (rootX == rootY) {
		return;
	}

	if (rank[rootX] < rank[rootY]) {
		std::swap(rootX, rootY);
	}
	parent[rootY] = rootX;
	if (rank[rootX] == rank[rootY]) {
		rank[rootX] += 1;
	}
}

int main()
{
	int V, E, a, b, c;
	std::cin >> V >> E;

	for (int i = 1; i <= V; ++i) {
		parent[i] = i;
	}

	std::priority_queue<edge> pq;

	for (int i = 0; i < E; ++i) {
		std::cin >> a >> b >> c;
		pq.push({a, b, c});
	}

	int sum = 0;
	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();
		if (find(e.u) == find(e.v)) {
			continue;
		}

		unionXY(e.u, e.v);
		sum += e.w;
	}

	std::cout << sum << std::endl;

	return 0;
}