#include <iostream>
#include <string>

int getLength(int n) {
  int len = 0;
  for (int start = 1, i = 1; n >= start; start *= 10, ++i) {
    int end = start * 10 - 1;
    len += (std::min(end, n) - start + 1) * i;
  }
  return len;
}

void solve(int n, int k) {
  int lo = 1;
  int hi = n;
  int ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (k > getLength(mid)) {
      lo = mid + 1;
    } else {
      ans = mid;
      hi = mid - 1;
    }
  }

  auto str = std::to_string(ans);
  std::cout << str[str.length() - (getLength(ans) - k) - 1];
}

int main() {
  int n, k;
  std::cin >> n >> k;
  if (k > getLength(n)) {
    std::cout << -1;
    return 0;
  }
  solve(n, k);
  return 0;
}