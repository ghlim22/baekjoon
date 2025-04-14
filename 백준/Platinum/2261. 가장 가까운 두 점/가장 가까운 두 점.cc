#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

struct Point {
  int x;
  int y;
};

Point V[100000];
Point TMP[100000];

inline int squared(int x) { return (x) * (x); }

inline int getDistanceSquared(const Point &a, const Point &b) {
  return squared(a.x - b.x) + squared(a.y - b.y);
}

int solve(int lo, int hi) {
  int n = hi - lo + 1;
  if (n <= 3) {
    int minD = INT_MAX;
    for (int i = lo; i < hi; ++i) {
      for (int j = i + 1; j <= hi; ++j) {
        int d = getDistanceSquared(V[i], V[j]);
        minD = std::min(minD, d);
      }
    }
    return minD;
  }

  int mid = (lo + hi) / 2;
  int leftD = solve(lo, mid);
  if (leftD == 0) {
    return leftD;
  }
  int rightD = solve(mid + 1, hi);
  int d = std::min(leftD, rightD);

  if (d == 0) {
    return d;
  }

  int m = 0;
  for (int i = lo; i <= hi; ++i) {
    if (squared(V[i].x - V[mid].x) < d) {
      TMP[m] = V[i];
      m++;
    }
  }
  std::sort(TMP, TMP + m, [](const auto &a, const auto &b) {
    if (a.y == b.y)
      return a.x < b.x;
    else
      return a.y < b.y;
  });

  for (int i = 0; i < m - 1; ++i) {
    for (int j = i + 1; j < m; ++j) {
      if (squared(TMP[i].y - TMP[j].y) < d) {
        int distance = getDistanceSquared(TMP[i], TMP[j]);
        d = std::min(d, distance);
      } else {
        break;
      }
    }
    if (d == 0)
      break;
  }

  return d;
}

int main(void) {
  fastio;

  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i)
    std::cin >> V[i].x >> V[i].y;

  std::sort(V, V + n, [](const auto &a, const auto &b) {
    if (a.x == b.x)
      return a.y < b.y;
    else
      return a.x < b.x;
  });

  std::cout << solve(0, n - 1);

  return 0;
}