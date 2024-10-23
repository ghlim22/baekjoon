#include <stdio.h>
#include <stdlib.h>

int BOARD[9][9];
int CHECK_ROW[9];
int CHECK_COL[9];
int CHECK_SQ[9];

void solve(int idx) {
  int row = idx / 9;
  int col = idx % 9;
  int sq = row - row % 3 + col / 3;

  if (idx == 81) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        printf("%d ", BOARD[i][j]);
      }
      printf("\n");
    }
    exit(0);
  }

  if (BOARD[row][col]) {
    solve(idx + 1);
    return;
  }

  for (int num = 1; num <= 9; num++) {
    if (CHECK_ROW[row] & (1 << num))
      continue;
    if (CHECK_COL[col] & (1 << num))
      continue;
    if (CHECK_SQ[sq] & (1 << num))
      continue;

    CHECK_ROW[row] |= (1 << num);
    CHECK_COL[col] |= (1 << num);
    CHECK_SQ[sq] |= (1 << num);
    BOARD[row][col] = num;

    solve(idx + 1);

    BOARD[row][col] = 0;
    CHECK_ROW[row] &= ~(1 << num);
    CHECK_COL[col] &= ~(1 << num);
    CHECK_SQ[sq] &= ~(1 << num);
  }
}

int main(void) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%1d", &BOARD[i][j]);
      CHECK_ROW[i] |= (1 << BOARD[i][j]);
      CHECK_COL[j] |= (1 << BOARD[i][j]);
      CHECK_SQ[i - i % 3 + j / 3] |= (1 << BOARD[i][j]);
    }
  }
  solve(0);
  return 0;
}