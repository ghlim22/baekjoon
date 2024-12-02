#include <algorithm>
#include <cstring>
#include <iostream>

int N;
int M;
char MAP[15][15];
bool V[15][15];
const int DY[4] = {-1, 1, 0, 0};
const int DX[4] = {0, 0, -1, 1};

int get_max_size(int y, int x) {
  int size = 32;
  for (int i = 0; i < 4; ++i) {
    int cur_size = -1;
    int ny = y;
    int nx = x;
    while (ny >= 0 && ny < N && nx >= 0 && nx < M) {
      if (V[ny][nx])
        break;
      if (MAP[ny][nx] != '#')
        break;
      cur_size++;
      ny += DY[i];
      nx += DX[i];
    }
    size = std::min(size, cur_size);
  }
  return size;
}

int put_cross(int y, int x) {
  int max_area = 0;
  int first_max_size = get_max_size(y, x);
  
  for (int first_size = 0; first_size <= first_max_size; ++first_size) {
    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + DY[dir] * first_size;
      int nx = x + DX[dir] * first_size;
      V[ny][nx] = true;
    }
    int first_area = 1 + first_size * 4;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        int second_size = get_max_size(i, j);
        if (second_size < 0)
          continue;
        int second_area = 1 + second_size * 4;
        max_area = std::max(max_area, first_area * second_area);
      }
    }
  }

  return max_area;
}

int main(void) {
  int answer = 0;
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    std::string line;
    std::cin >> line;
    for (int j = 0; j < M; ++j)
      MAP[i][j] = line[j];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (MAP[i][j] == '#') {
        std::memset(V, 0, sizeof(V));
        answer = std::max(answer, put_cross(i, j));
      }
    }
  }
  std::cout << answer;

  return 0;
}