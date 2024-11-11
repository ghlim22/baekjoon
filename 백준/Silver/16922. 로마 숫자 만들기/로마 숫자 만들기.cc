#include <iostream>

bool NUM[50 * 20 + 1][21];
int N;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  NUM[0][0] = true;
  for (int digit_cnt = 1; digit_cnt <= N; ++digit_cnt) {
    for (int num = 0; num < 50 * N + 1; ++num) {
      if (NUM[num][digit_cnt - 1]) {
        NUM[num + 1][digit_cnt] = true;
        NUM[num + 5][digit_cnt] = true;
        NUM[num + 10][digit_cnt] = true;
        NUM[num + 50][digit_cnt] = true;
      }
    }
  }

  int cnt = 0;
  for (int i = 1; i <= N * 50; ++i) {
    if (NUM[i][N])
      cnt++;
  }
  std::cout << cnt;

  return 0;
}