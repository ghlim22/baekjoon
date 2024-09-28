#include <stdio.h>
#include <stdlib.h>

#define LIMIT (10)

int N;
char S[LIMIT + 1][LIMIT + 1];
int cache[LIMIT + 1][LIMIT + 1];

void input() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    for (int j = i; j <= N; ++j) {
      scanf(" %c", &S[i][j]);
    }
  }
}

void print(void) {
  for (int i = 1; i <= N; ++i) {
    printf("%d ", cache[i][i]);
  }
  printf("\n");
  exit(0);
}

void solve(int pos) {
  if (pos == N + 1) {
    print();
  }

  for (int num = -10; num <= 10; ++num) {
    /* Check if the selected number meets the conditions for partial sums */
    for (int i = pos; i >= 1; --i) {
      int sum = cache[i][pos - 1] + num;
      switch (S[i][pos]) {
      case '+':
        if (sum <= 0)
          goto CONTINUE;
        break;
      case '-':
        if (sum >= 0)
          goto CONTINUE;
        break;
      case '0':
        if (sum != 0)
          goto CONTINUE;
        break;
      }
    }
    for (int i = 1; i <= pos; ++i) {
      cache[i][pos] = cache[i][pos - 1] + num;
    }
    solve(pos + 1);
  CONTINUE:;
  }
}

int main(void) {
  input();
  solve(1);
  return 0;
}