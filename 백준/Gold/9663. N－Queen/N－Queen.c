#include <stdio.h>

#define MAX (15)

int COLUMN[MAX];
int DIAGONAL[MAX * 2];
int REVERSE_DIAGONAL[MAX * 2];
int N;
int TOTAL;

void solve(int row) {
  if (row == N) {
    TOTAL++;
    return;
  }

  for (int col = 0; col < N; col++) {
    int dia = row - col + N - 1;
    int r_dia = row + col;

    if (COLUMN[col])
      continue;
    if (DIAGONAL[dia])
      continue;
    if (REVERSE_DIAGONAL[r_dia])
      continue;

    COLUMN[col] = 1;
    DIAGONAL[dia] = 1;
    REVERSE_DIAGONAL[r_dia] = 1;

    solve(row + 1);

    COLUMN[col] = 0;
    DIAGONAL[dia] = 0;
    REVERSE_DIAGONAL[r_dia] = 0;
  }
}

int main(void) {
  scanf("%d", &N);
  solve(0);
  printf("%d\n", TOTAL);

  return 0;
}