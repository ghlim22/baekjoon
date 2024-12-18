#include <algorithm>
#include <iostream>

int N;
int M;
int H;
int L[11][31]; /* Index starts from 1  */

bool check(void) {
  for (int i = 1; i <= N; ++i) {
    int cur = i;
    for (int j = 1; j <= H; ++j) {
      if (L[cur][j] != 0) {
        cur = L[cur][j];
      }
    }
    if (i != cur)
      return false;
  }
  return true;
}

int solve(int ver, int hor, int dep) {
  if (dep > 3)
    return -1;

  if (check())
    return dep;

  int ret = 4;
  for (int i = hor; i <= H; ++i) {
    for (int j = 1; j < N; ++j) {
      if (i == hor && j <= ver)
        continue;
      if (L[j][i] != 0)
        continue;
      if (L[j + 1][i] != 0)
        continue;
      L[j][i] = j + 1;
      L[j + 1][i] = j;
      int tmp = solve(j, i, dep + 1);
      if (tmp != -1)
        ret = std::min(ret, tmp);
      L[j][i] = 0;
      L[j + 1][i] = 0;
    }
  }

  if (ret == 4)
    return -1;

  return ret;
}

int main(void) {
  std::cin >> N >> M >> H;
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    L[b][a] = b + 1;
    L[b + 1][a] = b;
  }

  std::cout << solve(0, 1, 0);

  return 0;
}