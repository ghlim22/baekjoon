#include <algorithm>
#include <climits>
#include <iostream>

int N;
int min_value = INT_MAX;
int max_value INT_MIN;
int seq[11];
int operators[4];

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i)
    std::cin >> seq[i];
  for (int i = 0; i < 4; ++i)
    std::cin >> operators[i];
}

void bruteforce(int level, int sum) {
  if (level == N) {
    min_value = std::min(min_value, sum);
    max_value = std::max(max_value, sum);
    return;
  }

  int elem = seq[level];
  int ns[4] = {sum + elem, sum - elem, sum * elem, sum / elem};
  for (int i = 0; i < 4; ++i) {
    if (operators[i] > 0) {
      operators[i]--;
      bruteforce(level + 1, ns[i]);
      operators[i]++;
    }
  }
}

void solve() {
  bruteforce(1, seq[0]);
  std::cout << max_value << '\n';
  std::cout << min_value;
}

int main(void) {
  input();
  solve();
  return 0;
}