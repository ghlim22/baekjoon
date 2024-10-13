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

void bruteforce(int level, int sum) {
  if (level == N - 1) {
    min_value = std::min(min_value, sum);
    max_value = std::max(max_value, sum);
    return;
  }
  int ne = seq[level + 1];
  int ns[4] = {sum + ne, sum - ne, sum * ne, sum / ne};
  for (int i = 0; i < 4; ++i) {
    if (op_cnt[i] > 0) {
      op_cnt[i]--;
      bruteforce(level + 1, ns[i]);
      op_cnt[i]++;
    }
  }
}

void solve() {
  bruteforce(0, seq[0]);
  std::cout << max_value << '\n' << min_value;
}

int main() {
  input();
  solve();
  return 0;
}
