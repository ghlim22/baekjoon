#include <limits.h>
#include <stdio.h>

#define MAX (13)

int A[MAX];
int COMB[MAX];
int K;

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void dfs(int start, int len) {
  if (len == 6) {
    /* Print */
    for (int i = 0; i < 6; ++i) {
      printf("%d ", COMB[i]);
    }
    printf("\n");
    return;
  }

  for (int i = start; i < K; ++i) {
    COMB[len] = A[i];
    dfs(i + 1, len + 1);
  }
}

int main(void) {
  /* INPUT */
  while (1) {
    scanf("%d", &K);
    if (K == 0) {
      break;
    }
    for (int i = 0; i < K; ++i) {
      scanf("%d", &A[i]);
    }
    dfs(0, 0);
    printf("\n");
  }

  return 0;
}
