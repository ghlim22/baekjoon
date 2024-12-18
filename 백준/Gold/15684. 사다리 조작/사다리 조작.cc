#include <iostream>

int N;
int M;
int H;
bool L[31][11];

bool check(void) {
  for (int col = 1; col <= N; ++col) {
    int cur = col;
    for (int row = 1; row <= H; ++row) {
      if (L[row][cur])
        cur++;
      else if (L[row][cur - 1])
        cur--;
    }
    if (cur != col)
      return false;
  }
  return true;
}

bool solve(int cnt) {
  if (cnt == 0) {
    return check();
  }

  for (int col = 1; col < N; ++col) {
    for (int row = 1; row <= H; ++row) {
      if (L[row][col - 1] || L[row][col + 1] || L[row][col])
        continue;
      L[row][col] = true;
      if (solve(cnt - 1))
        return true;
      L[row][col] = false;
      while (row <= H && !L[row][col - 1] && !L[row][col + 1])
        row++;
    }
  }

  return false;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M >> H;
  while (M--) {
    int a, b;
    std::cin >> a >> b;
    L[a][b] = true;
  }

  for (int i = 0; i < 4; ++i) {
    if (solve(i)) {
      std::cout << i;
      return 0;
    }
  }

  std::cout << -1;

  return 0;
}