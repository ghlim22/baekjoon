#include <iostream>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

int cables[10000];

long count(int len, int c[], int k) {
  long ret = 0;
  for (int i = 0; i < k; ++i) {
    ret += c[i] / len;
  }
  return ret;
}

int main() {
  fastio;
  int n, k;
  std::cin >> k >> n;

  long lo = 1;
  long hi = 1;
  for (int i = 0; i < k; ++i) {
    std::cin >> cables[i];
    if (hi < cables[i]) {
      hi = cables[i];
    }
  }

  int ans = 0;
  while (lo <= hi) {
    long m = (hi-lo)/2+lo;
    long c = count(m, cables, k);
    if (c >= n) {
      ans = m;
      lo = m + 1;
    } else {
      hi = m - 1;
    }
  }

  std::cout << ans;

  return 0;
}