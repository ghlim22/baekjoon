#include <algorithm>
#include <iostream>
#include <queue>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

struct lecture {
  int d;
  int p;
} request[10000];

struct comp {
  bool operator()(const lecture &a, const lecture &b) const {
    return a.d > b.d;
  }
};

int main() {
  fastio;
  int n;
  int max_day = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> request[i].p >> request[i].d;
    if (request[i].d > max_day)
      max_day = request[i].d;
  }

  comp compare;
  std::sort(request, request + n, compare);
  std::priority_queue<int> pq;
  int total = 0;
  for (int date = max_day, i = 0; date >= 1; --date) {
    while (i < n && request[i].d >= date) /* push requests that have a due date
                                             on or after the date into pq */
      pq.push(request[i++].p);
    if (pq.empty())
      continue;
    total += pq.top();
    pq.pop();
  }

  std::cout << total << std::endl;

  return 0;
}