#include <stdio.h>
#include <string.h>

const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};
int BOARD[9][9];
int CHECK_ROW[9];
int CHECK_COL[9];
int CHECK_SQ[9];
int DOMINO[10][10];
int DONE = 0;
int TC = 0;

void solve(int idx) {
  int row = idx / 9;
  int col = idx % 9;
  int sq = row - row % 3 + col / 3;

  if (DONE)
    return;

  if (idx == 81) {
    printf("Puzzle %d\n", TC);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        printf("%d", BOARD[i][j]);
      }
      printf("\n");
    }
    DONE = 1;
    return;
  }

  if (BOARD[row][col] != 0) {
    solve(idx + 1);
    return;
  }

  for (int num1 = 1; num1 <= 9 && !DONE; num1++) {
    if (CHECK_ROW[row] & (1 << num1))
      continue;
    if (CHECK_COL[col] & (1 << num1))
      continue;
    if (CHECK_SQ[sq] & (1 << num1))
      continue;

    CHECK_ROW[row] |= (1 << num1);
    CHECK_COL[col] |= (1 << num1);
    CHECK_SQ[sq] |= (1 << num1);
    BOARD[row][col] = num1;

    for (int i = 0; i < 4 && !DONE; i++) {
      int nr = row + DY[i];
      int nc = col + DX[i];
      int nsq = nr - nr % 3 + nc / 3;

      if (!(nr >= 0 && nr < 9 && nc >= 0 && nc < 9))
        continue;
      if (BOARD[nr][nc] != 0)
        continue;

      for (int num2 = 1; num2 <= 9 && !DONE; num2++) {
        if (num1 == num2)
          continue;
        if (CHECK_ROW[nr] & (1 << num2))
          continue;
        if (CHECK_COL[nc] & (1 << num2))
          continue;
        if (CHECK_SQ[nsq] & (1 << num2))
          continue;
        if (DOMINO[num1][num2])
          continue;

        CHECK_ROW[nr] |= (1 << num2);
        CHECK_COL[nc] |= (1 << num2);
        CHECK_SQ[nsq] |= (1 << num2);

        DOMINO[num1][num2] = 1;
        DOMINO[num2][num1] = 1;
        BOARD[nr][nc] = num2;

        solve(idx + 1);

        DOMINO[num1][num2] = 0;
        DOMINO[num2][num1] = 0;
        BOARD[nr][nc] = 0;

        CHECK_ROW[nr] &= ~(1 << num2);
        CHECK_COL[nc] &= ~(1 << num2);
        CHECK_SQ[nsq] &= ~(1 << num2);
      }
    }

    CHECK_ROW[row] &= ~(1 << num1);
    CHECK_COL[col] &= ~(1 << num1);
    CHECK_SQ[sq] &= ~(1 << num1);
    BOARD[row][col] = 0;
  }
}

int input(void) {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    int num, num2;
    char pos[3], pos2[3];

    scanf("%d %s %d %s", &num, pos, &num2, pos2);

    int row = pos[0] - 'A';
    int col = pos[1] - '1';
    int sq = row - row % 3 + col / 3;

    CHECK_ROW[row] |= (1 << num);
    CHECK_COL[col] |= (1 << num);
    CHECK_SQ[sq] |= (1 << num);
    BOARD[row][col] = num;

    int row2 = pos2[0] - 'A';
    int col2 = pos2[1] - '1';
    int sq2 = row2 - row2 % 3 + col2 / 3;

    CHECK_ROW[row2] |= (1 << num2);
    CHECK_COL[col2] |= (1 << num2);
    CHECK_SQ[sq2] |= (1 << num2);
    BOARD[row2][col2] = num2;

    DOMINO[num][num2] = 1;
    DOMINO[num2][num] = 1;
  }

  for (int num = 1; num <= 9; num++) {
    char pos[3];

    scanf("%s", pos);
    int row = pos[0] - 'A';
    int col = pos[1] - '1';
    int sq = row - row % 3 + col / 3;

    CHECK_ROW[row] |= (1 << num);
    CHECK_COL[col] |= (1 << num);
    CHECK_SQ[sq] |= (1 << num);
    BOARD[row][col] = num;
  }

  return 1;
}

int main(void) {
  while (1) {
    TC++;

    /* INPUT */
    if (!input())
      break;

    /* SOLVE */
    solve(0);

    // for (int i = 0; i < 9; ++i) {
    //   for (int j = 0; j < 9; ++j) {
    //     printf("%d", BOARD[i][j]);
    //   }
    //   printf("\n");
    // }

    /* CLEAR MEMORY */
    DONE = 0;
    memset(BOARD, 0, sizeof(BOARD));
    memset(CHECK_ROW, 0, sizeof(CHECK_ROW));
    memset(CHECK_COL, 0, sizeof(CHECK_COL));
    memset(CHECK_SQ, 0, sizeof(CHECK_SQ));
    memset(DOMINO, 0, sizeof(DOMINO));
  }

  return 0;
}