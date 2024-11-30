#include <iostream>

#define MAX 32
#define HOR 0
#define VER 1
#define DIA 2

int MAP[MAX][MAX];
long CACHE[MAX][MAX][3];
int N;

int main(void) {
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      std::cin >> MAP[i][j];
  }

  CACHE[0][1][HOR] = 1;
  for (int col = 2; col < N; ++col) {
    for (int row = 0; row < N; ++row) {
      if (MAP[row][col] == 1)
        continue;
      // HOR
      CACHE[row][col][HOR] =
          CACHE[row][col - 1][HOR] + CACHE[row][col - 1][DIA];
      // DIA
      if (row > 0 && MAP[row - 1][col] == 0 && MAP[row][col - 1] == 0) {
        CACHE[row][col][DIA] = CACHE[row - 1][col - 1][DIA] +
                               CACHE[row - 1][col - 1][HOR] +
                               CACHE[row - 1][col - 1][VER];
      }
      // VER
      if (row > 0) {
        CACHE[row][col][VER] =
            CACHE[row - 1][col][VER] + CACHE[row - 1][col][DIA];
      }
    }
  }

  std::cout << CACHE[N - 1][N - 1][HOR] + CACHE[N - 1][N - 1][VER] +
                   CACHE[N - 1][N - 1][DIA];

  return 0;
}