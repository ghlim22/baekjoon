#include <algorithm>
#include <iostream>
#include <utility>

int N;
int ANSWER;
std::pair<int, int> EGGS[8];

void solve(int cur, int cnt) {
  ANSWER = std::max(ANSWER, cnt);
  if (cur == N || cnt == N) {
    return;
  }

  if (EGGS[cur].first <= 0) {
    solve(cur + 1, cnt);
    return;
  }

  for (int i = 0; i < N; ++i) {
    if (i == cur)
      continue;
    if (EGGS[i].first <= 0)
      continue;
    int tmp = cnt;
    EGGS[i].first -= EGGS[cur].second;
    EGGS[cur].first -= EGGS[i].second;
    if (EGGS[i].first <= 0)
      tmp++;
    if (EGGS[cur].first <= 0)
      tmp++;
    solve(cur + 1, tmp);
    EGGS[i].first += EGGS[cur].second;
    EGGS[cur].first += EGGS[i].second;
  }
}

int main(void) {
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int s, w;
    std::cin >> s >> w;
    EGGS[i].first = s;
    EGGS[i].second = w;
  }
  solve(0, 0);
  std::cout << ANSWER;

  return 0;
}