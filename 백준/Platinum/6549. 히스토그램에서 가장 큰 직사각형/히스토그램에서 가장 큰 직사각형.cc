#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>

typedef std::pair<int, int> pii_t;

int h[100001];

long f(int h[], int n) {
  std::stack<pii_t> s; /* <height, index> */
  long res = 0;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (!s.empty() && s.top().first >= h[i]) {
      int ht = s.top().first;
      j = s.top().second;
      res = std::max(res, (long)ht * (i - j));
      s.pop();
    }
    s.push(std::make_pair(h[i], j));
  }

  return (res);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;

  for (;;) {
    std::cin >> n;
    if (n == 0)
      break;

    for (int i = 0; i < n; ++i)
      std::cin >> h[i];

    h[n] = 0; /* to compute the remaining elements on the stack */
    std::cout << f(h, n + 1) << std::endl;
  }

  return 0;
}
