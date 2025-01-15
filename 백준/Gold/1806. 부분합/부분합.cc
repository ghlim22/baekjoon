#include <algorithm>
#include <climits>
#include <iostream>

int sequence[100000];
int N;
int S;

int solve(void) {
  int sum = sequence[0];
  int ans = INT_MAX;
  for (int i = 0, j = 0; i <= j && j < N;) {
    if (sum >= S) {
      ans = std::min(ans, j - i + 1);
      sum -= sequence[i];
      i++;
    } else {
      j++;
      sum += sequence[j];
    }
  }

  if (ans == INT_MAX) {
    return 0;
  }

  return ans;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> S;
  for (int i = 0; i < N; ++i) {
    std::cin >> sequence[i];
  }
  std::cout << solve() << std::endl;

  return 0;
}