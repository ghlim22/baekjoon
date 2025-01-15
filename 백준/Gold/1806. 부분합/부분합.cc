#include <algorithm>
#include <climits>
#include <iostream>

int sequence[100001];
int sum[100001];
int N;
int S;

int solve(void) {
  if (sum[N] < S) {
    return 0;
  }

  if (sequence[1] >= S) {
    return 1;
  }

  int i = 0;
  int j = 0;
  int ans = INT_MAX;
  while (j <= N && i <= j) {
    if (sum[j] - sum[i] >= S) {
      ans = std::min(ans, j - i);
      i++;
    } else {
      j++;
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
  for (int i = 1; i <= N; ++i) {
    std::cin >> sequence[i];
    sum[i] = sum[i - 1] + sequence[i];
  }
  std::cout << solve() << std::endl;

  return 0;
}