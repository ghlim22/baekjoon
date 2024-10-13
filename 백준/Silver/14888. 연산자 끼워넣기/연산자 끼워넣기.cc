#include <algorithm>
#include <climits>
#include <iostream>

#define MAX (100)

int N;
int seq[MAX];
int op_cnt[4];
int min_value = INT_MAX;
int max_value = INT_MIN;

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i)
    std::cin >> seq[i];
  for (int i = 0; i < 4; ++i)
    std::cin >> op_cnt[i];
}

void bruteforce(int level, int sum, int op) {
  switch (op) {
  case 0:
    sum += seq[level];
    break;
  case 1:
    sum -= seq[level];
    break;
  case 2:
    sum *= seq[level];
    break;
  case 3:
    sum /= seq[level];
    break;
  default:
    sum = seq[level];
    break;
  }

  if (level == N - 1) {
    min_value = std::min(min_value, sum);
    max_value = std::max(max_value, sum);
    return;
  }

  for (int i = 0; i < 4; ++i) {
    if (op_cnt[i] == 0)
      continue;
    op_cnt[i]--;
    bruteforce(level + 1, sum, i);
    op_cnt[i]++;
  }
}

void solve() {
    bruteforce(0, 0, -1);
    std::cout << max_value << '\n' << min_value;
}

int main() {
    input();
    solve();
    return 0;
}
