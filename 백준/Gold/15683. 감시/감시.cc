#include <algorithm>
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

struct pos {
  int y;
  int x;
};

int N;
int M;
int MAP[8][8];
int ANSWER = 64;
std::vector<pos> CAMS;

void solve(int cur);
void cam_one(int cur);
void cam_two(int cur);
void cam_three(int cur);
void cam_four(int cur);
void cam_five(int cur);
void (*CAM_FUNC[5])(int) = {cam_one, cam_two, cam_three, cam_four, cam_five};

void cam_one(int cur) {
  int tmp[8][8];
  memmove(tmp, MAP, sizeof(int) * 8 * 8);

  const int DY[4] = {-1, 1, 0, 0};
  const int DX[4] = {0, 0, -1, 1};
  for (int i = 0; i < 4; ++i) {
    int ny = CAMS[cur].y;
    int nx = CAMS[cur].x;
    while (ny >= 0 && ny < N && nx >= 0 && nx < M && MAP[ny][nx] != 6) {
      if (MAP[ny][nx] == 0)
        MAP[ny][nx] = -1;
      ny += DY[i];
      nx += DX[i];
    }
    solve(cur + 1);
    memmove(MAP, tmp, sizeof(int) * 8 * 8);
  }
}

void cam_two(int cur) {
  int tmp[8][8];
  memmove(tmp, MAP, sizeof(int) * 8 * 8);

  // horizontal
  int ny = CAMS[cur].y;
  int nx = CAMS[cur].x;
  while (nx >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx--;
  }
  nx = CAMS[cur].x;
  while (nx < M && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx++;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);

  // vertical
  ny = CAMS[cur].y;
  nx = CAMS[cur].x;
  while (ny < N && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny++;
  }
  ny = CAMS[cur].y;
  while (ny >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny--;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);
}

void cam_three(int cur) {
  int tmp[8][8];
  memmove(tmp, MAP, sizeof(int) * 8 * 8);

  // 1
  int ny = CAMS[cur].y;
  int nx = CAMS[cur].x;
  while (nx >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx--;
  }
  nx = CAMS[cur].x;
  while (ny >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny--;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);

  // 2
  ny = CAMS[cur].y;
  nx = CAMS[cur].x;
  while (nx < M && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx++;
  }
  nx = CAMS[cur].x;
  while (ny >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny--;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);

  // 3
  ny = CAMS[cur].y;
  nx = CAMS[cur].x;
  while (nx < M && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx++;
  }
  nx = CAMS[cur].x;
  while (ny < N && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny++;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);

  // 4
  ny = CAMS[cur].y;
  nx = CAMS[cur].x;
  while (nx >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx--;
  }
  nx = CAMS[cur].x;
  while (ny < N && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny++;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);
}

void cam_four(int cur) {
  int tmp[8][8];
  memmove(tmp, MAP, sizeof(int) * 8 * 8);

  // 1
  int ny = CAMS[cur].y;
  int nx = CAMS[cur].x;
  while (nx >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx--;
  }
  nx = CAMS[cur].x;
  while (nx < M && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx++;
  }
  nx = CAMS[cur].x;
  while (ny >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny--;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);

  // 2
  ny = CAMS[cur].y;
  nx = CAMS[cur].x;
  while (nx >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx--;
  }
  nx = CAMS[cur].x;
  while (nx < M && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx++;
  }
  nx = CAMS[cur].x;
  while (ny < N && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny++;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);

  // 3
  ny = CAMS[cur].y;
  nx = CAMS[cur].x;
  while (ny >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny--;
  }
  ny = CAMS[cur].y;
  while (ny < N && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny++;
  }
  ny = CAMS[cur].y;
  while (nx >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx--;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);

  // 4
  ny = CAMS[cur].y;
  nx = CAMS[cur].x;
  while (ny >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny--;
  }
  ny = CAMS[cur].y;
  while (ny < N && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny++;
  }
  ny = CAMS[cur].y;
  while (nx < M && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx++;
  }
  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);
}

void cam_five(int cur) {
  int tmp[8][8];
  memmove(tmp, MAP, sizeof(int) * 8 * 8);

  int ny = CAMS[cur].y;
  int nx = CAMS[cur].x;
  while (nx >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx--;
  }
  nx = CAMS[cur].x;
  while (nx < M && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    nx++;
  }
  nx = CAMS[cur].x;
  while (ny >= 0 && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny--;
  }
  ny = CAMS[cur].y;
  while (ny < N && MAP[ny][nx] != 6) {
    if (MAP[ny][nx] == 0)
      MAP[ny][nx] = -1;
    ny++;
  }

  solve(cur + 1);
  memmove(MAP, tmp, sizeof(int) * 8 * 8);
}

void solve(int cur) {
  if (cur == CAMS.size()) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (MAP[i][j] == 0)
          cnt++;
      }
    }
    ANSWER = std::min(ANSWER, cnt);
    return;
  }

  const int CAM_NO = MAP[CAMS[cur].y][CAMS[cur].x] - 1;
  CAM_FUNC[CAM_NO](cur);
}

int main(void) {
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> MAP[i][j];
      if (MAP[i][j] != 0 && MAP[i][j] != 6)
        CAMS.push_back(pos{.y = i, .x = j});
    }
  }

  solve(0);

  std::cout << ANSWER;

  return 0;
}