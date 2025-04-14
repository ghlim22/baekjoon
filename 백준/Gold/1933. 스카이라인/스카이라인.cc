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

struct coord {
  coord() : _y(0), _x(0) {}
  coord(int y, int x) : _y(y), _x(x) {}
  bool operator==(const coord &other) {
    return _y == other._y && _x == other._x;
  }
  bool operator!=(const coord &other) {
    return !(_y == other._y && _x == other._x);
  }
  bool inRange(int w, int h) {
    return (_y >= 0 && _y < h && _x >= 0 && _x < w);
  }
  int _y;
  int _x;
};

struct Building {
  int left;
  int right;
  int height;
};

typedef std::pair<int, int> pii_t;
typedef std::vector<pii_t> Result;

const int d4y[4] = {0, -1, 1, 0};
const int d4x[4] = {-1, 0, 0, 1};
const int d8y[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int d8x[8] = {-1, 1, -1, 0, 1, -1, 0, 1};

void append(Result &v, const pii_t &p) {
  if (v.empty()) {
    v.push_back(p);
    return;
  }
  if (v.back().second == p.second) { /* 높이가 변하지 않는 경우 */
    return;
  }
  if (v.back().first == p.first) { /* x 위치가 중첩되는 경우 */
    v.back().second = p.second;    /* 더 높은 위치로 갱신 */
    return;
  }
  v.push_back(p);
}

Result merge(const Result &left, const Result &right) {
  Result merged;
  int leftIndex = 0;
  int rightIndex = 0;
  int leftHeight = 0;
  int rightHeight = 0;
  const int LEFT_SIZE = left.size();
  const int RIGHT_SIZE = right.size();

  while (leftIndex < LEFT_SIZE && rightIndex < RIGHT_SIZE) {
    const pii_t &u = left[leftIndex];
    const pii_t &v = right[rightIndex];
    if (u.first < v.first) {
      leftHeight = u.second;
      int height = std::max(leftHeight, rightHeight);
      pii_t p = {u.first, height};
      append(merged, p);
      leftIndex++;
    } else {
      rightHeight = v.second;
      int height = std::max(leftHeight, rightHeight);
      pii_t p = {v.first, height};
      append(merged, p);
      rightIndex++;
    }
  }

  while (leftIndex < LEFT_SIZE) {
    append(merged, left[leftIndex]);
    leftIndex++;
  }
  while (rightIndex < RIGHT_SIZE) {
    append(merged, right[rightIndex]);
    rightIndex++;
  }

  return merged;
}

Result solve(std::vector<Building> &v, int lo, int hi) {
  if (lo == hi) {
    return {{v[lo].left, v[lo].height}, {v[lo].right, 0}};
  }

  int mid = (lo + hi) / 2;
  auto left = solve(v, lo, mid);
  auto right = solve(v, mid + 1, hi);

  return merge(left, right);
}

int main(void) {
  fastio;

  int n;
  std::cin >> n;

  std::vector<Building> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i].left >> v[i].height >> v[i].right;

  std::sort(v.begin(), v.end(),
            [](const auto &a, const auto &b) { return a.left < b.left; });

  auto result = solve(v, 0, n - 1);
  for (const auto &p : result)
    std::cout << p.first << ' ' << p.second << ' ';

  return 0;
}