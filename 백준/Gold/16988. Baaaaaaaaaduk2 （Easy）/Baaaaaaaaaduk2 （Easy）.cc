#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

const int DY[4] = {0, 0, -1, 1};
const int DX[4] = {-1, 1, 0, 0};
int ANSWER;
int N;
int M;
int BOARD[20][20];
bool V[20][20];

int bfs(int y, int x) {
  int ret = 0;
  bool flag = false;
  std::queue<std::pair<int, int> > q;
  q.push(std::make_pair(y, x));
  V[y][x] = true;
  while (!q.empty()) {
    std::pair<int, int> cur = q.front();
    q.pop();
    ret++;
    for (int i = 0; i < 4; ++i) {
      int ny = cur.first + DY[i];
      int nx = cur.second + DX[i];
      if (!(ny >= 0 && ny < N && nx >= 0 && nx < M))
        continue;
      if (V[ny][nx])
        continue;
      if (BOARD[ny][nx] == 1)
        continue;
      if (BOARD[ny][nx] == 0)
        flag = true; // 이 그룹은 죽지 않는다.
      
      V[ny][nx] = true;
      q.push(std::make_pair(ny, nx));
    }
  }

  if (flag)
    return 0;

  return ret;
}

int find(void) {
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (BOARD[i][j] == 2 && !V[i][j]) {
        ret += bfs(i, j);
      }
    }
  }
  return ret;
}

int main(void) {
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j)
      std::cin >> BOARD[i][j];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (BOARD[i][j] != 0)
        continue;
      BOARD[i][j] = 1;
      for (int k = i; k < N; ++k) {
        for (int l = 0; l < M; ++l) {
          if (k == i && l <= j)
            continue;
          if (BOARD[k][l] != 0)
            continue;
          BOARD[k][l] = 1;
          std::memset(V, 0, sizeof(V));
          ANSWER = std::max(ANSWER, find());
          BOARD[k][l] = 0;
        }
      }
      BOARD[i][j] = 0;
    }
  }

  std::cout << ANSWER;

  return 0;
}