#include <algorithm>
#include <iostream>
#include <vector>

int N;
int ANSWER = 100001;
std::vector<int> B;

void solve(int cur, int cnt, int prev, int diff) {
  if (cur == N) {
    ANSWER = std::min(ANSWER, cnt);
    return;
  }

  int nums[3] = {B[cur], B[cur] + 1, B[cur] - 1};
  for (int i = 0; i < 3; ++i) {
    if (cur <= 1) {
      solve(cur + 1, cnt + (i >= 1), nums[i], nums[i] - prev);
    } else {
      if (diff != nums[i] - prev)
        continue;
      solve(cur + 1, cnt + (i >= 1), nums[i], diff);
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int num;
    std::cin >> num;
    B.push_back(num);
  }
  solve(0, 0, 0, 0);
  if (ANSWER == 100001)
    ANSWER = -1;
  std::cout << ANSWER;

  return 0;
}