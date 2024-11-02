#include <cstring>
#include <iostream>
#include <vector>

#define MAX (1000)

int input[MAX][MAX];
int info[MAX][MAX]; /* 각 빈 공간이 어떤 그룹에 속하는지 저장 */
int output[MAX][MAX];
int group_cnt = 0;
int height;
int width;
std::vector<int> group_info; /* 각 그룹이 몇 개의 빈 공간으로 구성되었는지 저장 */

const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

int dfs(int r, int c) {
  int sum = 1;

  info[r][c] = group_cnt;
  for (int i = 0; i < 4; i++) {
    int nr = r + DY[i];
    int nc = c + DX[i];
    if (!(nr >= 0 && nr < height && nc >= 0 && nc < width))
      continue;
    if (info[nr][nc] != -1) /* Already visited */
      continue;
    if (input[nr][nc] == 1) /* Wall */
      continue;
    sum += dfs(nr, nc);
  }

  return sum;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> height >> width;
  for (int i = 0; i < height; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < width; ++j) {
      input[i][j] = s[j] - '0';
    }
  }

  memset(info, -1, sizeof(info));

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (input[i][j] == 0 && info[i][j] == -1) {
        group_info.push_back(dfs(i, j));
        group_cnt++;
      }
    }
  }

  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      if (input[r][c] == 0)
        continue;

      int sum = 1;
      int adj_cnt = 0;
      int adj_groups[4];

      for (int i = 0; i < 4; i++) {
        int nr = r + DY[i];
        int nc = c + DX[i];
        if (!(nr >= 0 && nr < height && nc >= 0 && nc < width))
          continue;
        if (input[nr][nc] == 1)
          continue;
        adj_groups[adj_cnt++] = info[nr][nc];
      }

      for (int i = 0; i < adj_cnt; i++) {
        bool duplicated = false;
        for (int j = 0; j < i; j++) {
          if (adj_groups[i] == adj_groups[j]) {
            duplicated = true;
            break;
          }
        }
        if (duplicated == false)
          sum += group_info[adj_groups[i]];
      }

      output[r][c] = sum % 10;
    }
  }

  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      std::cout << output[r][c];
    }
    if (r < height - 1)
      std::cout << '\n';
  }

  return 0;
}