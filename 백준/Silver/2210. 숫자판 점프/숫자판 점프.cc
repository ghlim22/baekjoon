#include <iostream>
#include <set>

const int DY[4] = {0, 0, -1, 1};
const int DX[4] = {-1, 1, 0, 0};
int map[5][5];
std::set<int> s;
int answer = 0;

void solve(int depth, int y, int x, int num) {
  if (depth == 6) {
    if (s.find(num) == s.end()) {
      s.insert(num);
      answer++;
    }
    return;
  }

  num = num * 10 + (map[y][x] - '0');

  for (int i = 0; i < 4; ++i) {
    int ny = y + DY[i];
    int nx = x + DX[i];
    if (!(ny >= 0 && ny < 5 && nx >= 0 && nx < 5))
      continue;
    solve(depth + 1, ny, nx, num);
  }
}

int main(void) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j)
      std::cin >> map[i][j];
  }
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      solve(0, i, j, 0);
    }
  }
  std::cout << answer;
  return 0;
}