#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  int n, m, k;

  std::cin >> n >> m >> k;

  if (!(k + m - 1 <= n && n <= m * k)) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::vector<int> v;
  for (int i = 1; i <= n; ++i) {
    v.push_back(i);
  }

  std::vector<int> boundary(m);
  boundary[0] = k;
  int q = (n - k) / std::max(1, m - 1);
  int r = (n - k) % std::max(1, m - 1);
  for (int i = 1; i < m; ++i) {
    boundary[i] = boundary[i - 1] + q;
    if (r > 0) {
      boundary[i]++;
      r--;
    }
  }

  std::greater<int> greater;
  for (int i = 0; i < m; ++i) {
    if (i == 0) {
      std::sort(v.begin(), v.begin() + k, greater);
    } else {
      std::sort(v.begin() + boundary[i - 1], v.begin() + boundary[i], greater);
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << v[i] << ' ';
  }
  std::cout << std::endl;

  return 0;
}