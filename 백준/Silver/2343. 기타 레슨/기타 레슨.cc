#include <iostream>
#include <vector>

bool check(const std::vector<int> &v, int capa, int m) {
  int remainder = capa;
  for (int disk : v) {
    if (disk > capa) {
      return false;
    }

    if (disk <= remainder) {
      remainder -= disk;
    } else if (m > 1) {
      m--;
      remainder = capa - disk;
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  int n, m, lo = 0, hi = 0;

  std::cin >> n >> m;

  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
    hi += v[i];
  }

  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(v, mid, m)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  std::cout << hi; 

  return 0;
}