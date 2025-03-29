#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct jewelry {
  int m;
  int v;
};

bool operator<(const jewelry &l, const jewelry &r) { return l.m < r.m; }

class compare {
public:
  bool operator()(const jewelry &a, const jewelry &b) const {
    return a.v < b.v;
  }
};

jewelry jewelries[300000];
int bags[300000];

int main() {
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

  std::priority_queue<jewelry, std::vector<jewelry>, compare> pq;
  long total = 0;
  int j = 0;
  for (int i = 0; i < k; ++i) {
    while (j < n && jewelries[j].m <= bags[i]) {
      pq.push(jewelries[j]);
      j++;
    }
    if (pq.empty()) {
		continue;
    }
    total += pq.top().v;
    pq.pop();
  }

  std::cout << total << std::endl;

  return 0;
}