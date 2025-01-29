#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

int main(void) {
  int capacity[3];
  std::cin >> capacity[0] >> capacity[1] >> capacity[2];

  int init = capacity[2];
  std::set<int> s;
  std::vector<int> answer;
  std::queue<int> q;

  s.insert(init);
  q.push(init);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    int a = cur >> 16;
    int b = (cur >> 8) & ((1 << 8) - 1);
    int c = cur & ((1 << 8) - 1);
    if (a == 0) {
      answer.push_back(c);
    }

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i == j)
          continue;
        int bottles[3] = {a, b, c};
        if (bottles[i] == 0)
          break;
        int remaining_capacity = capacity[j] - bottles[j];
        bottles[j] += std::min(remaining_capacity, bottles[i]);
        bottles[i] -= std::min(remaining_capacity, bottles[i]);
        int n = 0;
        for (int k = 0; k < 3; ++k) {
          n |= bottles[k] << (8 * (2 - k));
        }
        if (s.find(n) != s.end()) {
          continue;
        }
        s.insert(n);
        q.push(n);
      }
    }
  }

  std::sort(answer.begin(), answer.end());
  for (int i = 0; i < answer.size(); ++i) {
    if (i > 0 && answer[i - 1] == answer[i]) {
      continue;
    }
    std::cout << answer[i] << ' ';
  }

  return 0;
}