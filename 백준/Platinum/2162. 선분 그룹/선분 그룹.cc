#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<long, long> pii_t;
typedef std::pair<pii_t, pii_t> segment;

int set[3000];
int rank[3000];
int size[3000];

int find(int x) {
	if (x == set[x]) return x;
	else return set[x] = find(set[x]);
}

int merge(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);

	if (rank[rootx] < rank[rooty]) {
		std::swap(rootx, rooty);
	}

	set[rooty] = rootx;
	size[rootx] += size[rooty];

	if (rank[rootx] == rank[rooty]) {
		rank[rootx]++;
	}

	return size[rootx];
}

long ccw(pii_t &p1, pii_t &p2, pii_t &p3) {
	long x1 = p1.first;
	long y1 = p1.second;

	long x2 = p2.first;
	long y2 = p2.second;

	long x3 = p3.first;
	long y3 = p3.second;

	return x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x3 * y2 - x2 * y1;
}

bool cross(segment &s1, segment &s2) {
	pii_t &p1 = s1.first;
	pii_t &p2 = s1.second;
	pii_t &p3 = s2.first;
	pii_t &p4 = s2.second;
	long r1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	long r2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
	if (r1 == 0 && r2 == 0) {
		return p3 <= p2 && p1 <= p4;
	}
	return r1 <= 0 && r2 <= 0;
}

int main(void) {
  fastio;
  int N;
  std::cin >> N;
  std::vector<segment> segs;
  for (int i = 0; i < N; ++i) {
	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	pii_t p1 = {x1, y1};
	pii_t p2 = {x2, y2};
	if (p2 < p1) {
		segs.push_back({p2, p1});
	} else {
		segs.push_back({p1, p2});
	}
  }
  std::sort(segs.begin(), segs.end());

  for (int i = 0; i < N; ++i) {
	set[i] = i;
	size[i] = 1;
  }

  int groups = N;
  int maxsize = 1;
  for (int i = 0; i < N; ++i) {
	for (int j = i + 1; j < N; ++j) {
		if (cross(segs[i], segs[j])) {
			int rootx = find(i);
			int rooty = find(j);
			if (rootx != rooty) {
				groups--;
				maxsize = std::max(maxsize, merge(rootx, rooty));
			}
		}
	}
  }

  std::cout << groups << '\n' << maxsize << '\n';

  return 0;
}