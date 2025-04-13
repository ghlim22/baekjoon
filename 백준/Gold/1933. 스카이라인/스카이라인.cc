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

struct Building {
  int left;
  int right;
  int height;
};

typedef std::pair<int, int> pii_t;
typedef std::vector<pii_t> Result; /* <left, height> */
typedef std::vector<Building> Buildings;

void append(Result &v, const pii_t &p) {
  if (v.empty()) {
    v.push_back(p);
    return;
  }
  if (v.back().second == p.second) { /* 높이가 변하지 않는 경우 */
    return;
  }
  if (v.back().first == p.first) { /* 같은 x위치에 겹치는 경우, 둘 중 더 높이가
                                      높은 것만 남긴다. */
    // v.back().second = std::max(v.back().second, p.second);
    v.back().second = p.second;
    return;
  }
  v.push_back(p);
}

Result merge(const Result &left, const Result &right) {
  Result merged;
  int leftHeight = 0;
  int rightHeight = 0;
  int leftIndex = 0;
  int rightIndex = 0;

  while (leftIndex < left.size() && rightIndex < right.size()) {
    const auto l = left[leftIndex];
    const auto r = right[rightIndex];
    if (l.first < r.first) {
      leftHeight = l.second;
      auto p = std::make_pair(l.first, std::max(leftHeight, rightHeight));
      append(merged, p);
      leftIndex++;
    } else {
      rightHeight = r.second;
      auto p = std::make_pair(r.first, std::max(leftHeight, rightHeight));
      append(merged, p);
      rightIndex++;
    }
  }

  while (leftIndex < left.size()) {
    append(merged, left[leftIndex++]);
  }
  while (rightIndex < right.size()) {
    append(merged, right[rightIndex++]);
  }

  return merged;
}

Result solve(const Buildings &v, int lo, int hi) {
  if (lo == hi) {
    return {{v[lo].left, v[lo].height}, {v[lo].right, 0}};
  }

  int mid = (lo + hi) / 2;
  auto left = solve(v, lo, mid);
  auto right = solve(v, mid + 1, hi);

  return merge(left, right);
}

int main() {
  fastio;

  int n;
  std::cin >> n;

  std::vector<Building> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].left >> v[i].height >> v[i].right;
  }

  std::sort(v.begin(), v.end(),
            [](const auto &a, const auto &b) { return a.left < b.left; });

  auto result = solve(v, 0, n - 1);
  for (const auto &p : result) {
    std::cout << p.first << ' ' << p.second << ' ';
  }
  std::cout << std::endl;

  return 0;
}