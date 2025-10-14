#include <algorithm>
#include <iostream>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

int set[500000];
int rank[500000];

int find(int x) {
	if (set[x] == x) return x;

	int root = find(set[x]);
	return set[x] = root;
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

  int N, M, answer = 0;
  std::cin >> N >> M;

  for (int i = 0; i < N; ++i) {
	set[i] = i;
  }

  for (int i = 0; i < M; ++i) {
	int a, b;
	std::cin >> a >> b;
	if (find(a) == find(b)) {
		answer = i + 1;
		break;
	} else {
		ft_union(a, b);
	}
  }

  std::cout << answer << std::endl;

  return 0;
}