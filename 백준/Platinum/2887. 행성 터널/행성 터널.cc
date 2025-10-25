#include <algorithm>
#include <cmath>
#include <list>
#include <iostream>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

struct planet {
	int index;
	int x;
	int y;
	int z;
};

struct edge {
	int n1;
	int n2;
	int weight;
};

int set[100000];
int rank[100000];

int find(int x) {
	if (set[x] == x) return x;
	else return set[x] = find(set[x]);
}

void merge(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);

	if (rank[rootx] < rank[rooty]) {
		std::swap(rootx, rooty);
	}

	set[rooty] = rootx;
	if (rank[rootx] == rank[rooty]) {
		rank[rootx]++;
	}
}

int main(void) {
  fastio;

  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
	set[i] = i;
  }

  std::vector<planet> planets;
  for (int i = 0; i < n; ++i) {
	int x, y, z;
	std::cin >> x >> y >> z;
	planets.push_back({i, x, y, z});
  }

  std::vector<edge> edges;

  std::sort(planets.begin(), planets.end(), [](const auto &a, const auto &b) -> bool {
	return a.x < b.x;
  });
  for (int i = 1; i < n; ++i) {
	int prev = planets[i - 1].index;
	int curr = planets[i].index;
	edges.push_back({prev, curr, std::abs(planets[i - 1].x - planets[i].x)});
  }

  std::sort(planets.begin(), planets.end(), [](const auto &a, const auto &b) -> bool {
	return a.y < b.y;
  });
  for (int i = 1; i < n; ++i) {
	int prev = planets[i - 1].index;
	int curr = planets[i].index;
	edges.push_back({prev, curr, std::abs(planets[i - 1].y - planets[i].y)});
  }

  std::sort(planets.begin(), planets.end(), [](const auto &a, const auto &b) -> bool {
	return a.z < b.z;
  });
  for (int i = 1; i < n; ++i) {
	int prev = planets[i - 1].index;
	int curr = planets[i].index;
	edges.push_back({prev, curr, std::abs(planets[i - 1].z - planets[i].z)});
  }

  std::sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) -> bool {
	return a.weight < b.weight;
  });

  long total = 0;
  for (const edge &e : edges) {
	int rootx = find(e.n1);
	int rooty = find(e.n2);
	if (rootx == rooty) {
		continue;
	}
	total += e.weight;
	merge(rootx, rooty);
  }
  
  std::cout << total << std::endl;

  return 0;
}