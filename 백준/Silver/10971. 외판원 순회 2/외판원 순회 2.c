#include <limits.h>
#include <stdio.h>

#define MAX (10)

int P[MAX + 1];
int W[MAX][MAX];
int N;
int answer = INT_MAX;

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void permutations(int idx) {
  /* Checks if the path is possible. */
  if (idx > 0 && W[P[idx - 1]][P[idx]] == 0) {
    return;
  }
  /* The salesman visited all N cities. */
  if (idx == N - 1) {
    int start = P[0];
    int last = P[N - 1];

    /* If there's no path back to start point. */
    if (W[last][start] == 0) {
      return;
    }

    int cost = 0;
    int total = 0;
    P[N] = start;
    for (int i = 0; i < N; ++i) {
      int cost = W[P[i]][P[i + 1]];
      if (cost == 0)
        return;
      total += cost;
    }

    if (total < answer) {
      answer = total;
    }

    return;
  }

  for (int i = idx; i < N; ++i) {
    swap(&P[i], &P[idx]);
    permutations(idx + 1);
    swap(&P[i], &P[idx]);
  }
}

int main(void) {
  /* INPUT */
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &W[i][j]);
    }
  }

  for (int i = 0; i < N; ++i) {
    P[i] = i;
  }

  permutations(0);

  printf("%d", answer);

  return 0;
}
