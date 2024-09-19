#include <algorithm>
#include <iostream>

#define MAX (1000000)
#define NOT_DISCARDED (0)
#define DISCARDED (1)

int seq[MAX];
int cache[MAX][2];

inline int max(int a, int b, int c) { return std::max(a, std::max(b, c)); }

int main(void) {
  std::cin.tie(NULL)->sync_with_stdio(false);

  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> seq[i];
  }

  /* 최소 하나의 원소를 선택해야 한다. */
  cache[0][0] = seq[0];
  int ans = seq[0];
  for (int i = 1; i < n; ++i) {
    /* cache[i][x]: i번 원소를 마지막 원소로 고려하는 부분 수열의 연속합
     * x = 0: 원소를 버리지 않은 상태
     * x = 1: 원소 하나를 버린 상태
     * cache[i][0] = max(seq[i], cache[i - 1][0] + seq[i])
     *   - 1. 현재 원소를 새로운 연속합의 시작점으로 삼는다.
     *   - 2. 이전 연속합을 이어간다.
     * cache[i][1] = max(cache[i - 1][0], cache[i - 1][1] + seq[i])
     *   - 1. 현재 원소를 버리고, 원소를 버리지 않은 상태의 연속합을 이어간다.
     *   - 2. 원소 하나를 버린 상태의 연속합을 이어간다.
     */
    cache[i][0] = std::max(seq[i], cache[i - 1][0] + seq[i]);
    cache[i][1] = std::max(cache[i - 1][1] + seq[i], cache[i - 1][0]);
    ans = max(ans, cache[i][0], cache[i][1]);
  }
  std::cout << ans;

  return 0;
}
