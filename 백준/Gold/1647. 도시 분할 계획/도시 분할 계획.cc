#include <algorithm>
#include <iostream>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

struct edge {
	int x;
	int y;
	int weight;
};

int set[100001];
int rank[100001];

int find(int x) {
	if (set[x] == x) {
		return x;
	}

	int parent = set[x];
	return set[x] = find(parent);
}

void ft_union(int x, int y) {
	int root_x = find(x);
	int root_y = find(y);
	if (rank[root_x] < rank[root_y]) {
		std::swap(root_x, root_y);
	}
	set[root_y] = root_x;
	if (rank[root_x] == rank[root_y]) {
		rank[root_x] += 1;
	}
}

int main(void) {
	fastio;

	int N, M;
	std::cin >> N >> M;

	std::vector<edge> edges(M);
	for (int i = 0; i < M; ++i) {
		std::cin >> edges[i].x >> edges[i].y >> edges[i].weight;
	}
	std::sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) -> bool {
		return a.weight < b.weight;
	});

	for (int i = 1; i <= N; ++i) {
		set[i] = i;
	}

	int set_count = N;
	int answer = 0;
	for (const edge &e : edges) {
		if (set_count == 2) break;
		int set_x = find(e.x);
		int set_y = find(e.y);
		if (set_x != set_y) {
			ft_union(set_x, set_y);
			answer += e.weight;
			set_count--;
		}
	}

	std::cout << answer << std::endl;

    return 0;
}