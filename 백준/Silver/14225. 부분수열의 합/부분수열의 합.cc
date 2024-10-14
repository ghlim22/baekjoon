#include <algorithm>
#include <iostream>
#include <vector>

#define MAX (20)

int N;
int min_value = 2000000;
int seq[MAX];
std::vector<int> sums;

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i)
    std::cin >> seq[i];
}

void bruteforce(int idx, int sum) {
  if (idx == N) {
    if (sum != 0)
      sums.push_back(sum);
    return;
  }
  bruteforce(idx + 1, sum + seq[idx]);
  bruteforce(idx + 1, sum);
}

void solve() {
  bruteforce(0, 0);
  std::sort(sums.begin(), sums.end());

  int j = 0;
  for (int i = 1; j < sums.size(); ++i) {
    if (i < sums[j]) {
      std::cout << i;
      break;
    }
    while (i == sums[j]) {
      j++;
    }
  }
  if (j == sums.size()) {
    std::cout << sums.back() + 1;
  }
}

int main() {
  input();
  solve();
}