#include <algorithm>
#include <iostream>
#include <queue>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

struct jewelry {
  int m;
  int v;
} jewelries[300000];

int bags[300000];

bool operator<(const jewelry &lhs, const jewelry &rhs) { return lhs.m < rhs.m; }

int main() {
  fastio;

  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> jewelries[i].m >> jewelries[i].v;
  }
  for (int i = 0; i < k; ++i) {
    std::cin >> bags[i];
  }

  std::sort(jewelries, jewelries + n);
  std::sort(bags, bags + k);

  long total = 0;
  std::priority_queue<int> pq;
  for (int i = 0, j = 0; i < k; ++i) {
    while (j < n && jewelries[j].m <= bags[i]) /* push jewelries which can be put into the bag i */
      pq.push(jewelries[j++].v);
    if (pq.empty())
      continue;
    /* all the jewelries in pq can be put into the bag i */
    /* select the valuable one in pq */
    total += pq.top();
    pq.pop();
  }

  std::cout << total << std::endl;

  return 0;
}