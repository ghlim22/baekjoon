#include <stdio.h>
#include <string.h>

#define MAX (4)

int paper[MAX][MAX];

int main(void) {
  /* INPUT */
  int row_size;
  int col_size;

  scanf("%d %d", &row_size, &col_size);
  for (int i = 0; i < row_size; ++i) {
    for (int j = 0; j < col_size; ++j) {
      scanf("%1d", &paper[i][j]);
    }
  }

  /* SOLVE */
  const int LIMIT = 1 << (row_size * col_size);
  int max_score = 0;

  for (int status = 0; status < LIMIT; ++status) {
    int total_score = 0;
    /* 세로 */
    /* 비트가 1이면 세로 */
    for (int c = 0; c < col_size; ++c) {
      int current_score = 0;
      for (int r = 0; r < row_size; ++r) {
        int idx = r * col_size + c;
        if (status & (1 << idx)) {
          current_score *= 10;
          current_score += paper[r][c];
        } else {
          total_score += current_score;
          current_score = 0;
        }
      }
      total_score += current_score;
    }
    /* 가로 */
    /* 비트가 0이면 가로 */
    for (int r = 0; r < row_size; ++r) {
      int current_score = 0;
      for (int c = 0; c < col_size; ++c) {
        int idx = r * col_size + c;
        if (!(status & (1 << idx))) {
          current_score *= 10;
          current_score += paper[r][c];
        } else {
          total_score += current_score;
          current_score = 0;
        }
      }
      total_score += current_score;
    }

    max_score = (total_score > max_score) ? total_score : max_score;
  }

  /* PRINT THE ANSWER */
  printf("%d\n", max_score);

  return 0;
}
