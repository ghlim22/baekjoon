#include <stdio.h>

char coins[20][20];

int main(void) {
  int n;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      scanf(" %c", &c);
      if (c == 'H')
        coins[i][j] = 1; /* head */
    }
  }

  int lmt = 1 << n;
  int answer = n * n;
  for (int i = 0; i < lmt; ++i) {
	int tails = 0;
    for (int col = 0; col < n; ++col) {
      int column_tails = 0;
      for (int row = 0; row < n; ++row) {
        if (i & (1 << row)) {
          if (coins[row][col]) /* flipped head */
            column_tails++;
        } else if (!coins[row][col]) {
          column_tails++;
        }
      }
	  if (column_tails > n / 2) { /* flip the column or don't */
		column_tails = n - column_tails;
	  }
	  tails += column_tails;
    }
	answer = (tails < answer) ? tails : answer;
  }

  printf("%d\n", answer);

  return 0;
}