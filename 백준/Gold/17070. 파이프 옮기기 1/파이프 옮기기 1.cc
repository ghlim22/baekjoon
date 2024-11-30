#include <iostream>

#define MAX 16
#define HOR 0
#define VER 1
#define DIA 2

struct pos {
  int y;
  int x;
  int type;
};

int MAP[MAX][MAX];
bool V[MAX][MAX];
int N;
int ANSWER = 0;

void dfs(int y, int x, int type) {
  if (y == N - 1 && x == N - 1) {
    ANSWER++;
    return;
  }

  if (type == HOR) {
    if (x + 1 < N && MAP[y][x + 1] == 0) {
      dfs(y, x + 1, HOR);
    }
    if (y + 1 < N && x + 1 < N && MAP[y + 1][x] == 0 &&
        MAP[y + 1][x + 1] == 0 && MAP[y][x + 1] == 0) {
      dfs(y + 1, x + 1, DIA);
    }
  } else if (type == VER) {
    if (y + 1 < N && MAP[y + 1][x] == 0) {
      dfs(y + 1, x, VER);
    }
    if (y + 1 < N && x + 1 < N && MAP[y + 1][x] == 0 &&
        MAP[y + 1][x + 1] == 0 && MAP[y][x + 1] == 0) {
      dfs(y + 1, x + 1, DIA);
    }
  } else {
    if (x + 1 < N && MAP[y][x + 1] == 0) {
      dfs(y, x + 1, HOR);
    }
    if (y + 1 < N && MAP[y + 1][x] == 0) {
      dfs(y + 1, x, VER);
    }
    if (y + 1 < N && x + 1 < N && MAP[y + 1][x] == 0 &&
        MAP[y + 1][x + 1] == 0 && MAP[y][x + 1] == 0) {
      dfs(y + 1, x + 1, DIA);
    }
  }
}

int main(void) {
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      std::cin >> MAP[i][j];
  }
  dfs(0, 1, HOR);
  std::cout << ANSWER;
  return 0;
}